######################################################################################################################
########################### Node to decode encoders msgs and send odometry to controllers ########################### 
######################################################################################################################
######################################## Haytham Rabi ###############################################################
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
        self.T = time.time()
        
        #to print position
        self.P = [0 , 0 , 0]
        self.t_plot = 0
        self.Te = 0.08

        # Initialize the transform broadcaster
        self.tf_broadcaster = TransformBroadcaster(self)
        
        ## publish twist msg
        self.publisher_ = self.create_publisher(Odometry, 'odom', 10)
        timer_period =  self.Te  # seconds
        self.timer = self.create_timer(timer_period, self.Send_odom)
        
                # Data aquisitions
        # Init the csv file for writing Poses and Velocities
        with open('/home/ubuntu/data_aquisition/vitesses.csv', 'w') as fileObj:
            writerObj = csv.writer(fileObj)
            writerObj.writerow(['vx', 'vy', 'vphi', 't(sec)'])

        with open('/home/ubuntu/data_aquisition/positions.csv', 'w') as fileObj:
            writerObj = csv.writer(fileObj)
            writerObj.writerow(['x', 'y', 'phi', 't(sec)'])    
############################################  decode encoders #####################################################
    
    def listen_encoder(self,id_enc):
    
      bus = can.interface.Bus(bustype='socketcan', channel='can0', bitrate=125000)
      # iterate over received messages
      i=0
      for msg in bus:
        if msg.arbitration_id == 0x404 and id_enc == 0 :
          print(f"ENCODER 0: {msg.data}")
          d = struct.unpack('4h', msg.data)
          pm = d[0]
          p = d[1]
          print(pm,p)
          return pm
        if msg.arbitration_id == 0x414 and id_enc == 1 :
          print(f"ENCODER 1: {msg.data}")
          d = struct.unpack('4h', msg.data)
          pm = d[0]
          p = d[1]
          print(pm,p)
          return pm

        if msg.arbitration_id == 0x424 and id_enc == 2 :
          print(f"ENCODER 2: {msg.data}")
          d = struct.unpack('4h', msg.data)
          pm = d[0]
          p = d[1]
          print(pm,p)
          return pm

        if msg.arbitration_id == 0x434 and id_enc == 3 :
          print(f"ENCODER 3: {msg.data}")
          d = struct.unpack('4h', msg.data)
          pm = d[0]
          p = d[1]
          print(pm,p)
          return pm
       
    ############################################ from pulse to rd/s #########################################
    
    def Calcul_vitesse(self,P0,P1,P2,P3):
        # 2 pulse --> 2.5cm/s --> 0.5 rd/s
        R=5 #cm
        alpha = 2.083 #2.56072580645161 #(cm/s)/pulse
        
        #rad/s
        w0 = P0 * (alpha/R) 
        w1 = P1 * (alpha/R) 
        w2 = P2 * (alpha/R) 
        w3 = P3 * (alpha/R)
           
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
        A = np.array([[R/4,R/4,R/4,R/4],[R/4,-R/4,R/4,-R/4],[-R/(4*(L+w)),R/(4*(L+w)),R/(4*(L+w)),-R/(4*(L+w))],[1,1,-1,-1]])
        W= np.array([W0,W1,W2,W3])
       
        #Calcul de Vx,Vy,Vphi//[V]=[A].[W]
        V=A.dot(W)
       
        return V
   
    ############################# Integration et passage de R1 a R0  #####################################  
    ############################# --> Vitesses et Positions estimees #####################################
    
    def Integral(self,V,P,current_time,last_time):            
      
        x = P[0]
        y = P[1]
        th = P[2]
    
        dt= current_time - last_time

        vx = V[0]
        vy = V[1]
        vth = V[2]
        
        # de R1 a R0    
        delta_x = (vx * cos(th) - vy * sin(th)) * dt
        delta_y = (vx * sin(th) + vy * cos(th)) * dt
        delta_th = vth * dt 
   
        x += delta_x
        y += delta_y
        th += delta_th

       
        V = [vx, vy , vth ]
        P = [x, y, th]

        print(f"delta t = {dt} // Integration")
       
        return V , P
        
    ############################### envoie odometry #########################################
    
    def Send_odom(self):
        
        current_time = time.time() 
        last_time = self.last_time
        self.last_time = time.time()

        #########               
        P0 = self.listen_encoder(0)
        P1 = self.listen_encoder(1)
        P2 = self.listen_encoder(2)
        P3 = self.listen_encoder(3)
       
        Wm = self.Calcul_vitesse(P0,P1,P2,P3)
        #Wm = [20 , 0 , 20 , 0]        
        Vm = self.Model_Direct(Wm)#R1

        # P[n-1]
        P = self.P        
        [Vel,Pose] = self.Integral(Vm,P,current_time,last_time)     #Dans R0
        if ( P[2] > pi ) : # phi entre -pi et pi 
            P[2] = - pi
        if ( P[2] < -pi ) :
            P[2] =  pi
        # Save Pose (Somme des P[i] {i de 0 a n} )
        self.P = Pose + P
    
        T = current_time - self.T   
        print(f'Vitesse {Vel}  Positions {Pose[0],Pose[1],Pose[2]} Time {T}')       
        
        ######################################################################################
        # create msg 
        
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
        odom.pose.pose.position.x = float(Pose[0])
        odom.pose.pose.position.y = float(Pose[1])
        odom.pose.pose.position.z = 0.0

        q = quaternion_from_euler(0, 0, float(Pose[2]))
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
        
        if (Pose[0] != 0 or Pose[1] != 0 or Pose[2] != 0 ):
            # Save Poses and Velocities to Csv
            t_plot = self.t_plot
            with open('/home/ubuntu/data_aquisition/vitesses.csv', 'a') as fileObj:
                tocsv = [Vel[0],Vel[1],Vel[2],t_plot]
                writerObj = csv.writer(fileObj)
                writerObj.writerow(tocsv)

            with open('/home/ubuntu/data_aquisition/positions.csv', 'a') as fileObj:
                tocsv = [Pose[0],Pose[1],Pose[2],t_plot]
                writerObj = csv.writer(fileObj)
                writerObj.writerow(tocsv)        
            self.t_plot = t_plot + self.Te               
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
