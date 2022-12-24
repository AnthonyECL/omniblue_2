######################################################################################################################
########################### Node to decode the encoders and send odometry to controllers ########################### 
######################################################################################################################
import rclpy
import can
import time
import struct
import csv

from rclpy.node import Node
from rclpy.clock import Clock
from std_msgs.msg import String
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3 , TransformStamped

#from geometry_msgs.msg import TransformStamped

import math
import numpy as np
from math import sin, cos, pi ,exp

from tf2_ros import TransformBroadcaster


def quaternion_from_euler(ai, aj, ak):
    ai /= 2.0
    aj /= 2.0
    ak /= 2.0
    ci = math.cos(ai)
    si = math.sin(ai)
    cj = math.cos(aj)
    sj = math.sin(aj)
    ck = math.cos(ak)
    sk = math.sin(ak)
    cc = ci*ck
    cs = ci*sk
    sc = si*ck
    ss = si*sk

    q = np.empty((4, ))
    q[0] = cj*sc - sj*cs
    q[1] = cj*ss + sj*cc
    q[2] = cj*cs - sj*sc
    q[3] = cj*cc + sj*ss

    return q

class Odometry_pub(Node):

    def __init__(self):
        super().__init__('odometry')
                       
        self.last_time = time.time()
        self.time = 0
        
        #to print position
        self.X = 0
        self.Y = 0
        self.Phi = 0
        
        # Initialize the transform broadcaster
        self.tf_broadcaster = TransformBroadcaster(self)
        
        ## publish twist msg
        self.publisher_ = self.create_publisher(Odometry, 'odom', 10)
        timer_period =   0.16 # seconds
        self.timer = self.create_timer(timer_period, self.Send_odom)
            
############################################  decode encoders #####################################################
    
    def listen_encoder(self,id_enc):
    
      bus = can.interface.Bus(bustype='socketcan', channel='can0', bitrate=125000)
      # iterate over received messages
      i=0
      for msg in bus:
        if msg.arbitration_id == 0x404 and id_enc == 0 :
          print(f"ENCODER 0: {msg.data}")
          d = struct.unpack('4h', msg.data)
          pm = d[0]*2
          p = d[1]
          print(pm,p)
          return pm
        if msg.arbitration_id == 0x414 and id_enc == 1 :
          print(f"ENCODER 1: {msg.data}")
          d = struct.unpack('4h', msg.data)
          pm = d[0]*2
          p = d[1]
          print(pm,p)
          return pm

        if msg.arbitration_id == 0x424 and id_enc == 2 :
          print(f"ENCODER 2: {msg.data}")
          d = struct.unpack('4h', msg.data)
          pm = d[0]*2
          p = d[1]
          print(pm,p)
          return pm

        if msg.arbitration_id == 0x434 and id_enc == 3 :
          print(f"ENCODER 3: {msg.data}")
          d = struct.unpack('4h', msg.data)
          pm = d[0]*2
          p = d[1]
          print(pm,p)
          return pm
       
    ############################################ from pulse to rd/s #########################################
    
    def Calcul_vitesse(self,P0,P1,P2,P3):
        # 2 pulse --> 2.5cm/s --> 0.5 rd/s
        R=5 #cm
        alpha = 2.56072580645161/2 #(cm/s)/pulse
        
        #rad/s
        w0 = P0 * (alpha/R) #*2
        w1 = P1 * (alpha/R) #*2
        w2 = P2 * (alpha/R) #*2
        w3 = P3 * (alpha/R) #*2
           
        wm = [w0,w1,w2,w3]
        
        return wm

    #####################################################  [V]=[A].[W]   ########################################
    
    def Model_Direct(self,Wm):
     
        R=0.05
        L=0.425/2
        w=0.335/2
       
        W0 = Wm[0]
        W1 = Wm[1]
        W2 = Wm[2]
        W3 = Wm[3]
       
        #matrice A
        A = np.array([[R/4,R/4,R/4,R/4],[-R/4,R/4,R/4,-R/4],[-R/(4*(L+w)),R/(4*(L+w)),-R/(4*(L+w)),R/(4*(L+w))],[1,1,-1,-1]])
       
        W= np.array([W0,W1,W2,W3])
       
        #Calcul de Vx,Vy,Vphi//[V]=[A].[W]
        V=A.dot(W)
       
        return V
   
    ############################# Integration et passage de R1 a R0  #####################################  
    ############################# --> Vitesses et Positions estimees #####################################
    
    def Integral(self,V,X,Y,Phi,dt):            
      
        x = X
        y = Y
        phi = Phi
                
        dt= 0.128999  #20ms 
        
        vx = V[0]
        vy = V[1]
        vphi = V[2]
        
        # de R1 a R0    
        delta_x = (vx * cos(phi) - vy * sin(phi)) * dt 
        delta_y = (vx * sin(phi) + vy * cos(phi)) * dt 
        delta_phi = vphi * dt 
        
        x += delta_x
        y += delta_y
        phi += delta_phi

       
        V = [vx , vy , vphi]
        P = [x , y , phi]

        print(f"delta t = {dt} ")
       
        return V , P 
        
    ############################### envoie odometry #########################################
    
    def Send_odom(self):
        
        current_time = time.time() 
        last_time = self.last_time
        
        dt = current_time - last_time
        #self.time += dt
        
        # P[n-1]
        X = self.X 
        Y = self.Y 
        Phi = self.Phi
       
        #########               
        P0 = self.listen_encoder(0)
        P1 = self.listen_encoder(1)
        P2 = self.listen_encoder(2)
        P3 = self.listen_encoder(3)
       
        Wm = self.Calcul_vitesse(P0,P1,P3,P2)
        
        print("\n Wn \n")
        print(Wm)
        
        Vm = self.Model_Direct(Wm)#R1
        
        [Vel,Pose] = self.Integral(Vm,X,Y,Phi,dt)  #Dans R0

        # P[n] = P[n-1]+ dP
        self.X =  Pose[0]
        self.Y =  Pose[1]
        self.Phi =  Pose[2]
        # Save Pose (Somme des P[i] {i de 0 a n} )
        X = self.X
        Y = self.Y
        Phi = self.Phi   
        
        print(f'Vitesse {Vel}  Positions {X,Y,Phi} ')     
        
        current_time = self.get_clock().now().to_msg()
       
        t = TransformStamped()
        # Read message content and assign it to
        # corresponding tf variables
        t.header.stamp = current_time
        t.header.frame_id = "base_mobile"
        t.child_frame_id = "odom"

        t.transform.translation.x = Vel[0]
        t.transform.translation.y = Vel[1]
        t.transform.translation.z = 0.0

        q = quaternion_from_euler(0, 0, Vel[2])
        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]

        # Send the transformation
        self.tf_broadcaster.sendTransform(t)

        odom = Odometry()
        
        odom.header.stamp = current_time
        odom.header.frame_id = "odom"
        odom.child_frame_id = "base_mobile"
        
        # set the position
        odom.pose.pose.position.x = X
        odom.pose.pose.position.y = Y
        odom.pose.pose.position.z = 0.0

        q = quaternion_from_euler(0, 0, Phi)
        odom.pose.pose.orientation.x = q[0]
        odom.pose.pose.orientation.y = q[1]
        odom.pose.pose.orientation.z = q[2]
        odom.pose.pose.orientation.w = q[3]

        # set the velocity
        odom.twist.twist.linear.x = Vel[0]
        odom.twist.twist.linear.y = Vel[1]
        odom.twist.twist.angular.z = Vel[2]
        
        self.publisher_.publish(odom)
        self.get_logger().info("Odometry published")
        
        self.last_time = time.time()
        #time.sleep(0.02) 
               
#############################################################################################  

def main():
    rclpy.init()
    node = Odometry_pub()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()

if __name__ == '__main__':
    main()      