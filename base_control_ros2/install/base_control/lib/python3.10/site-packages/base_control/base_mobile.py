##################################################################################################################
######################################################################################################################
################################            Node _base_mobile_ Low level     #########################################
################################ subscribe to controller or teleop_keyb and send CAN msgs ############################
######################################################################################################################
############################################### Haytham Rabi #########################################################       
import rclpy
import can
import time 

from rclpy.node import Node

from std_msgs.msg import String
from geometry_msgs.msg import Twist

import numpy as np
from math import sin, cos, pi ,exp


class Base_mobile(Node):

    def __init__(self):
        super().__init__('base_mobile')

        #subscribe to teleop twist keyboard
        self.subscription = self.create_subscription(Twist,'cmd_vel',self.listener_callback,10)
        #subscribe to controler
        self.subscription = self.create_subscription(Twist,'cmd_vel_control',self.listener_callback1,1)
        self.subscription  # prevent unused variable warning

    def Model_Inv(self,x,y,phi):
        R=0.05
        L=0.425/2
        w=0.335/2
        #matrice A-1
        AA = np.array([[1/R,-1/R,-(L+w)/R,1/4],[1/R,1/R,-(L+w)/R,-1/4],[1/R,-1/R,(L+w)/R,-1/4],[1/R,1/R,(L+w)/R,1/4]])#old
        #AA = np.array([[1/R,-1/R,-(L+w)/R,1/4],[1/R,1/R,(L+w)/R,1/4],[1/R,1/R,-(L+w)/R,-1/4],[1/R,-1/R,(L+w)/R,-1/4]])#new
        #/cmd_vel
        V= np.array([x,y,phi,0])
        #Calcul de W1,W2,W3 et W4 //[W]=[A-1].[V]
        W=AA.dot(V)
        return W

#################  send to can  ########################################################
    #pour arrondir les float    
    def round(self,num, dec=0):
        num = str(num)[:str(num).index('.')+dec+2]
        if num[-1]>='5':
            return float(num[:-2-(not dec)]+str(int(num[-2-(not dec)])+1))
        return float(num[:-1])
    
    #envoie les msgs CAN 
    def sendCan(self,W):      
        #  1 cons ----> 2.083 cm/s ------> 0.4166 rd/s
        #     # 1 pulse --> 2.5cm/s --> 0.5 rd/s
        R=5 #cm
        alpha = 2.56072580645161/2 #cm/s (alpha/2 nouvelle m_a_j uC)
        #conversion from rd/s to cons
        constante_mot0 = float(W[0]/(alpha/R))
        constante_mot1 = float(W[1]/(alpha/R))
        constante_mot2 = float(W[2]/(alpha/R))
        constante_mot3 = float(W[3]/(alpha/R))
        #partie entiere arrondie
        constante_mot0 = int(round(constante_mot0))
        constante_mot1 = int(round(constante_mot1))
        constante_mot2 = int(round(constante_mot2))
        constante_mot3 = int(round(constante_mot3))
        
        print("send can (%d %d %d %d)" %(constante_mot0,constante_mot1,constante_mot2,constante_mot3))
        
        #conversion to bytes
        bytes_val_mot0 = constante_mot0.to_bytes(2, 'little',signed=True)
        bytes_val_mot1 = constante_mot1.to_bytes(2, 'little',signed=True)
        bytes_val_mot2 = constante_mot2.to_bytes(2, 'little',signed=True)
        bytes_val_mot3 = constante_mot3.to_bytes(2, 'little',signed=True)
        
        bus = can.interface.Bus(bustype='socketcan', channel='can0', bitrate=125000)
        msg = can.Message(arbitration_id=0x401, data=[bytes_val_mot0[0],bytes_val_mot0[1],bytes_val_mot1[0],bytes_val_mot1[1],bytes_val_mot2[0],bytes_val_mot2[1],bytes_val_mot3[0],bytes_val_mot3[1]], is_extended_id=False)
        
        try:
          bus.send(msg)
          time.sleep(0.04)
          print(f"Message sent on {bus.channel_info}")
        except can.CanError:
          print("Message NOT sent")
          
    def listener_callback(self, msg):
        self.get_logger().info("Received a Twist message!")
        self.get_logger().info("Linear Components: [%f, %f, %f]"%(msg.linear.x, msg.linear.y, msg.linear.z))
        self.get_logger().info("Angular Components: [%f, %f, %f]"%(msg.angular.x, msg.angular.y, msg.angular.z))
        W=self.Model_Inv(msg.linear.x, msg.linear.y,msg.angular.z)
        self.sendCan(W)
    # controler 
    def listener_callback1(self, msg):
        self.get_logger().info("Received a Twist message!")
        self.get_logger().info("Linear Components: [%f, %f, %f]"%(msg.linear.x, msg.linear.y, msg.linear.z))
        self.get_logger().info("Angular Components: [%f, %f, %f]"%(msg.angular.x, msg.angular.y, msg.angular.z))
        W=self.Model_Inv(msg.linear.x, msg.linear.y,msg.angular.z)
        self.sendCan(W)   
   
def main(args=None):
    rclpy.init(args=args)
    base = Base_mobile()
    rclpy.spin(base)
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
