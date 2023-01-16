######################################################################################################################
######################################################################################################################
################################            Node to control trajectory       #########################################
##################### subscribe to odometry or optitrack and publish cmd_vel to base_mobile ##########################
######################################################################################################################
######################################## Haytham Rabi ################################################################       
import rclpy
import can
import time
import struct
import csv

from rclpy.node import Node
from std_msgs.msg import String
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3 , TransformStamped

from mocap_optitrack_interfaces.msg import RigidBodyArray 

#from geometry_msgs.msg import TransformStamped

import math
import numpy as np
from math import sin, cos, pi ,exp

from tf2_ros import TransformBroadcaster

from simple_pid import PID


def euler_from_quaternion(x, y, z, w):
#Convert a quaternion into euler angles (roll, pitch, yaw)
#roll is rotation around x in radians (counterclockwise)
#pitch is rotation around y in radians (counterclockwise)
#yaw is rotation around z in radians (counterclockwise)
    t0 = +2.0 * (w * x + y * z)
    t1 = +1.0 - 2.0 * (x * x + y * y)
    roll_x = math.atan2(t0, t1)
    
    t2 = +2.0 * (w * y - z * x)
    t2 = +1.0 if t2 > +1.0 else t2
    t2 = -1.0 if t2 < -1.0 else t2
    pitch_y = math.asin(t2)
    
    t3 = +2.0 * (w * z + x * y)
    t4 = +1.0 - 2.0 * (y * y + z * z)
    yaw_z = math.atan2(t3, t4)
    
    return roll_x, pitch_y, yaw_z # in radians


class Controller_pub(Node):

    def __init__(self):
        
        super().__init__('Controller')
        
        #init variable
        self.odom = Odometry()
        self.optitrack = RigidBodyArray()
        
        self.t0 = time.time()
        self.Te = 0.08 #sec optitrack # 0.16 # sec odom 
        self.t_plot = 0

        self.xref = 0
        self.yref = 0
        self.phiref = 0  
        
        # subscribe to odometry 
        self.subscription = self.create_subscription(Odometry,'odom',self.listener_callback,10)
        # subscribe to optitrack
        self.subscription = self.create_subscription(RigidBodyArray,'mocap_rigid_bodies',self.listener_callback1,10)
        self.subscription  # prevent unused variable warning
        
        time.sleep(0.0001)# to subsribe first before publishing
        
        ## publish twist msg
        self.publisher = self.create_publisher(Twist, 'cmd_vel_control', 10)
        timer_period = self.Te # seconds
        self.timer = self.create_timer(timer_period, self.Controller_callback)
        
        # init cpt pub/sub
        self.cpt_sub = -1
        self.cpt_pub = 0

        # Data aquisitions
        # Init the csv file for writing Poses and Velocities
        with open('/home/hrabi/data_aquisition/vitesses.csv', 'w') as fileObj:
            writerObj = csv.writer(fileObj)
            writerObj.writerow(['vx', 'vy', 'vphi', 't(sec)'])

        with open('/home/hrabi/data_aquisition/positions.csv', 'w') as fileObj:
            writerObj = csv.writer(fileObj)
            writerObj.writerow(['x', 'y', 'phi', 't(sec)'])



    def pid_controller(self,ref,mesure,min_,max_,kp,ki):
        
        pid = PID()

        pid.tunings = (kp , ki , 0)        
        pid.setpoint = ref
        pid.sample_time = self.Te
        #pid.auto_mode = True 
        pid.output_limits = (min_,max_)
                
        while True:
           output = pid(mesure)
           return output
   
    def listener_callback(self, odom):
        if(self.cpt_sub == self.cpt_pub - 1 ):
            self.get_logger().info("Odometry Vel Received")
            self.get_logger().info("[%f, %f, %f]"%(odom.twist.twist.linear.x, odom.twist.twist.linear.y, odom.twist.twist.angular.z))      
            self.get_logger().info("Odometry Pose Received")
            #phi from quaternion
            q =euler_from_quaternion(odom.pose.pose.orientation.x,odom.pose.pose.orientation.y,odom.pose.pose.orientation.z,odom.pose.pose.orientation.w)
            self.get_logger().info("[%f, %f, %f]"%(odom.pose.pose.position.x, odom.pose.pose.position.y, q[2]))      
            self.odom = odom
            self.cpt_sub += 1
    
    def listener_callback1(self, optitrack): 
        if(self.cpt_sub == self.cpt_pub - 1 ):
            self.get_logger().info("RigidBody Pose Received")
            rigid = optitrack.rigid_bodies
            q =euler_from_quaternion(rigid[0].pose_stamped.pose.orientation.x,rigid[0].pose_stamped.pose.orientation.y,rigid[0].pose_stamped.pose.orientation.z,rigid[0].pose_stamped.pose.orientation.w)
            self.get_logger().info("[%f, %f, %f]"%(rigid[0].pose_stamped.pose.position.x, rigid[0].pose_stamped.pose.position.y , q[2]))   
            self.optitrack = optitrack  
            self.cpt_sub += 1

    def trajectoire(self,t0):
        #Ref dans R0
        t = time.time() - t0    
        #print(f"time {t}")
        while True :              
            x = sin(2*pi*t/60)
            y = 1.5 + cos(2*pi*t/60)
            phi = 0
            P = [x,y,phi]
            return P,t
        
    def Controller_callback(self):

        t0 = self.t0
        #trajectoire ref dans R0   
        P,temps = self.trajectoire(t0)  
        ###################################################
        xref = P[0]
        yref = P[1]
        phiref = P[2]        
        
        #######################################################
        vx = 0
        vy = 0
        vphi = 0
        # recuperer les positions mesure par odometry dans R0 
        odom = self.odom
        if odom :
            x = odom.pose.pose.position.x
            y = odom.pose.pose.position.y
            #phi from quaternion
            q =euler_from_quaternion(odom.pose.pose.orientation.x,odom.pose.pose.orientation.y,odom.pose.pose.orientation.z,odom.pose.pose.orientation.w)
            phi = q[2]

        optitrack = self.optitrack
        rigid = optitrack.rigid_bodies
        # check if the list is not empty to avoid list index error
        if rigid :    
            q =euler_from_quaternion(rigid[0].pose_stamped.pose.orientation.x,rigid[0].pose_stamped.pose.orientation.y,rigid[0].pose_stamped.pose.orientation.z,rigid[0].pose_stamped.pose.orientation.w)
            stamp = rigid[0].pose_stamped.header.stamp.sec
            x = rigid[0].pose_stamped.pose.position.x
            y = rigid[0].pose_stamped.pose.position.y
            phi = q[2]
            #print(x,y,phi)

        ############################################################       
        #####################################        
        
        vx = self.pid_controller(xref,x, -0.3 , 0.3 , 0.32 , 0)
        vy = self.pid_controller(yref,y, -0.2 , 0.2 , 0.31 , 0)
        vphi = self.pid_controller(phiref,phi, -0.2 , 0.2 , 0.58 , 0)

        if abs(xref-x) < 0.002 and abs(yref-y) < 0.002  and abs(phiref-phi) < 0.05 :
            vx = 0
            vy = 0
            vphi = 0       

        ###################################################################################
        print(f"\nPose : ref[{xref},{yref},{phiref}] estime[{x},{y},{phi}] Time[{temps}]\n")        
        print(f"Sub {self.cpt_sub} Pub {self.cpt_pub}\n")

        #Vitesses commande de R0 a R1
        commande_x = float( vx * cos(phi) + vy * sin(phi))
        commande_y = float(-vx * sin(phi) + vy * cos(phi))
        commande_phi = float(vphi)
        
        #create a msg twist to publish
        commande = Twist()    
        commande.linear.x = float(commande_x)
        commande.linear.y = float(commande_y)
        commande.angular.z = float(commande_phi)
        
        if(self.cpt_pub == self.cpt_sub):
            #publish twist msg 
            self.get_logger().info('Publishing Command Velocities' )
            self.get_logger().info("[%f, %f, %f]"%(commande.linear.x, commande.linear.y, commande.angular.z))
            self.publisher.publish(commande)
            self.cpt_pub += 1 
        
        if (x != 0 or y != 0 or phi != 0 ):
            # Save Poses and Velocities to Csv
            t_plot = self.t_plot
            with open('/home/hrabi/data_aquisition/vitesses.csv', 'a') as fileObj:
                tocsv = [commande_x,commande_y,commande_phi,temps]
                writerObj = csv.writer(fileObj)
                writerObj.writerow(tocsv)

            with open('/home/hrabi/data_aquisition/positions.csv', 'a') as fileObj:
                tocsv = [x,y,phi,temps]
                writerObj = csv.writer(fileObj)
                writerObj.writerow(tocsv)

            self.t_plot = t_plot + self.Te

def main():
    rclpy.init()
    node = Controller_pub()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    rclpy.shutdown()

if __name__ == '__main__':
    main()   
