##################################################################################################################
######################################################################################################################
################################            Node _base_mobile_ Low level     #########################################
################################ subscribe to controller or teleop_keyb and send CAN msgs ############################
######################################################################################################################
############################################### Haytham Rabi #########################################################       
import rospy
import can
import time 
import struct

from std_msgs.msg import String
from geometry_msgs.msg import Twist
from nav_msgs.msg import  Odometry
from marvelmind_nav.msg import hedge_pos, hedge_imu_fusion

import numpy as np
from math import sin, cos, pi ,exp
from tf2_ros import TransformBroadcaster
from geometry_msgs.msg import TransformStamped


class omniBlue():
    P = [0, 0, 0]
    nodeName = "car2"
    BattVal = 0
    R = 0.04
    w=0.288
    T = 0.04
    alpha =1041
    flagTracking = False
    trackedPos = [0.0, 0.0, 0.0]
    trackedVel = [0.0, 0.0, 0.0]
    trackedQuat = [0.0, 0.0, 0.0, 0.0]
    
    
    bus = can.interface.Bus(bustype='socketcan', channel='can0', bitrate=125000)
    tf_broadcaster = TransformBroadcaster()

    pub = rospy.Publisher (nodeName + '/odom', Odometry, queue_size=1)   

    def __init__(self):
        msg = self.bus.recv(0.025)
        while msg is not None:
            if msg.arbitration_id == 0x403 or msg.arbitration_id == 0x400:
                pass
            else:
                d = struct.unpack('4h', msg.data)
                self.BattVal = ( d[3] & 0x00FF ) * 0.0645
            msg = self.bus.recv(0.002)
        print ("Battery value: " + str(self.BattVal))
        #subscribe to teleop twist keyboard
        rospy.init_node(self.nodeName, anonymous=True)
        rospy.Subscriber('cmd_vel', Twist, self.listener_callback1)
        rospy.Subscriber('hedge_pos', hedge_pos, self.listener_callback_tracking_pos)
        rospy.Subscriber('hedge_imu_fusion', hedge_imu_fusion, self.listener_callback_tracking_imu)
        rospy.Subscriber(self.nodeName + '/cmd_vel', Twist, self.listener_callback1)
        rospy.Timer(rospy.Duration(self.T), self.fill_encoders)
        
        
    def round(self,num):
        if (abs(num) - abs(int(num)) > 0.5):
            return (int(num) +np.sign(num))
        else:
            return int(num)

    def sendCan(self,W):      
        #  1 cons ----> 2.083 cm/s ------> 0.4166 rd/s
        #     # 1 pulse --> 2.5cm/s --> 0.5 rd/s
        #conversion from rd/s to cons
        factor = 1/(self.alpha/(self.R*1e5))
        constante_mot0 = int(self.round(W[0]*factor))
        constante_mot1 = int(self.round(W[1]*factor))
        constante_mot2 = int(self.round(W[1]*factor))
        constante_mot3 = int(self.round(W[0]*factor))
       
        #conversion to bytes
        bytes_val_mot1 = constante_mot0.to_bytes(2, 'little',signed=True)
        bytes_val_mot0 = constante_mot1.to_bytes(2, 'little',signed=True)
        bytes_val_mot3 = constante_mot2.to_bytes(2, 'little',signed=True)
        bytes_val_mot2 = constante_mot3.to_bytes(2, 'little',signed=True)
        
        msg = can.Message(arbitration_id=0x401, data=[bytes_val_mot0[0],bytes_val_mot0[1],bytes_val_mot1[0],bytes_val_mot1[1],bytes_val_mot2[0],bytes_val_mot2[1],bytes_val_mot3[0],bytes_val_mot3[1]], is_extended_id=False)
        
        try:
          self.bus.send(msg)
          time.sleep(0.005)
        except can.CanError:
          print("Message NOT sent")

    def fill_encoders(self, event):
        P0 =P1= P2=P3 = 0
        msg = self.bus.recv(0.002)
        while msg is not None:
            if msg.arbitration_id == 0x403:
                pass
            elif msg.arbitration_id == 0x400:
                print("Low battery detected")
            else:
                d = struct.unpack('4h', msg.data)
                self.BattVal = ( d[3] & 0x00FF ) * 0.0645
                if msg.arbitration_id == 0x404:
                    P0 += float(d[0])
                if msg.arbitration_id == 0x414:
                    P1 += float(d[0])
                if msg.arbitration_id == 0x424:
                    P2 += float(d[0])
                if msg.arbitration_id == 0x434:
                    P3 += float(d[0])
            msg = self.bus.recv(0.002)
        self.Send_odom(P0,P1,P2,P3)
      
    def Send_odom(self,P0,P1,P2,P3):
        #########  
        if (not self.flagTracking):
            Wm = self.Calcul_vitesse(P0,P1,P2,P3)
            Vm = self.Model_Direct(Wm)#R1

            [Vel,self.P] = self.Integral(Vm,self.P, self.T)     #Dans R0
            if ( self.P[2] > pi ) : # phi entre -pi et pi 
                self.P[2] -=  2*pi
            if ( self.P[2] < -pi ) :
                self.P[2] +=  2*pi
            q = quaternion_from_euler(0, 0, float(self.P[2]))

        else:
            self.P[0] = self.trackedPos[1]
            self.P[1] = self.trackedPos[0]
            Vel = [self.trackedVel[0], self.trackedVel[1], self.trackedVel[2]] 
            q = [self.trackedQuat[0], self.trackedQuat[1], self.trackedQuat[2], self.trackedQuat[3]]
#            print (q)

        odom = Odometry()
        
        timeStamp = time.time_ns()
        odom.header.stamp.secs = int(timeStamp/1e9)
        odom.header.stamp.nsecs = int(timeStamp - odom.header.stamp.secs * 1e9) 
        odom.header.frame_id = self.nodeName + '/odom'
        odom.child_frame_id = "laser_frame"
        
        # set the position
        odom.pose.pose.position.x = float(self.P[0])
        odom.pose.pose.position.y = float(self.P[1])
        odom.pose.pose.position.z = 0.0
    #    print(P[2]*180/pi)
        odom.pose.pose.orientation.x = q[0]
        odom.pose.pose.orientation.y = q[1]
        odom.pose.pose.orientation.z = q[2]
        odom.pose.pose.orientation.w = q[3]

        # set the velocity
        odom.twist.twist.linear.x = Vel[0]
        odom.twist.twist.linear.y = Vel[1]
        odom.twist.twist.angular.z = Vel[2]
        
        t = TransformStamped()
        # Read message content and assign it to
        # corresponding tf variables
        t.header.stamp.secs = odom.header.stamp.secs
        t.header.stamp.nsecs = odom.header.stamp.nsecs
        t.header.frame_id = "map"
        t.child_frame_id = self.nodeName + '/odom'

        t.transform.translation.x = odom.pose.pose.position.x
        t.transform.translation.y = odom.pose.pose.position.y
        t.transform.translation.z = 0.0

        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]

        # Send the transformation
        self.tf_broadcaster.sendTransform(t)
        
        self.pub.publish(odom)

    def Calcul_vitesse(self,P0,P1,P2,P3):
        factor = (self.R/(self.alpha*self.T)) * 100
        w0 = P0 * factor
        w1 = P1 * factor
        w2 = P2 * factor
        w3 = P3 * factor
           
        wm = [w0,w1,w2,w3]
        
        return wm

    def Model_Direct(self,Wm):
     
       
        Wl = pi*(Wm[0] +  Wm[3])/2  
        Wr = pi*(Wm[1] +  Wm[2])/2
       
        #matrice A
        A = np.array([[self.R/2,self.R/2],[0,0],[-self.R/self.w,self.R/self.w]])
        W= np.array([Wl,Wr])
       
        #Calcul de Vx,Vy,Vphi//[V]=[A].[W]
        V=A.dot(W)
        V[2]/=8
       
        return V

    def Integral(self,V,Pose, dt):            
      
        x = Pose[0]
        y = Pose[1]
        th = Pose[2]

        
        delta_x = (V[0] * cos(th) ) * dt
        delta_y = (V[0] * sin(th)) * dt
        delta_th = V[2] * dt 

        x += delta_x
        y += delta_y
        th += delta_th

       
        V = [V[0], V[1] , V[2] ]
        Pose = [x, y, th]
       
        return V , Pose
    
    def Model_Inv(self,x,y,phi):
        Wr = (x + phi * self.w)/(self.R)
        Wl = (x - phi * self.w)/(self.R)
        return [Wr, Wl]

    def listener_callback1(self,msg):
        W=self.Model_Inv(msg.linear.x, msg.linear.y,msg.angular.z)
        self.sendCan(W)   

    def listener_callback_tracking_pos(self,msg):
        self.flagTracking = True
        self.trackedPos[0] = msg.x_m
        self.trackedPos[1] = msg.y_m
        self.trackedPos[2] = msg.y_m
        
    def listener_callback_tracking_imu(self,msg):
        self.flagTracking = True
        self.trackedVel[0] = msg.vx
        self.trackedVel[1] = msg.vy
        self.trackedVel[2] = msg.vz
        self.trackedQuat[0] = msg.qx
        self.trackedQuat[1] = msg.qy
        self.trackedQuat[2] = msg.qz
        self.trackedQuat[3] = msg.qw
        #print (msg)
        

        
#################  send to can  ########################################################
#pour arrondir les float    

#envoie les msgs CAN 

def quaternion_from_euler(ai, aj, ak):
    ai /= 2.0
    aj /= 2.0
    ak /= 2.0
    ci = cos(ai)
    si = sin(ai)
    cj = cos(aj)
    sj = sin(aj)
    ck = cos(ak)
    sk = sin(ak)
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


#############################################################################################  


# controler 
   
if __name__ == '__main__':
    omniblue = omniBlue()
    print("Omniblue initiated")
    rospy.spin()
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
 #   rclpy.shutdown()
