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
import datetime

from std_msgs.msg import String
from geometry_msgs.msg import Twist
from nav_msgs.msg import  Odometry

import numpy as np
from math import sin, cos, pi ,exp


bus = can.interface.Bus(bustype='socketcan', channel='can0', bitrate=125000)

pub = rospy.Publisher ('car2/odom', Odometry, queue_size=1)   

#################  send to can  ########################################################
#pour arrondir les float    
def round(num):
    if (abs(num) - abs(int(num)) > 0.5):
        return (int(num) +np.sign(num))
    else:
        return int(num)

#envoie les msgs CAN 
def sendCan(W):      
    #  1 cons ----> 2.083 cm/s ------> 0.4166 rd/s
    #     # 1 pulse --> 2.5cm/s --> 0.5 rd/s
    R=4 #cm
    alpha =1e-3*1041#2.56072580645161 #cm/s (alpha/2 nouvelle m_a_j base)
    #conversion from rd/s to cons
    constante_mot0 = float(W[0]/(alpha/R))
    constante_mot1 = float(W[1]/(alpha/R))
    constante_mot2 = float(W[1]/(alpha/R))
    constante_mot3 = float(W[0]/(alpha/R))
#    print([constante_mot0,constante_mot1,constante_mot2,constante_mot3])

#partie entiere arrondie
    constante_mot0 = int(round(constante_mot0))
    constante_mot1 = int(round(constante_mot1))
    constante_mot2 = int(round(constante_mot2))
    constante_mot3 = int(round(constante_mot3))
#    print([constante_mot0,constante_mot1,constante_mot2,constante_mot3])
    
    
    #conversion to bytes
    bytes_val_mot1 = constante_mot0.to_bytes(2, 'little',signed=True)
    bytes_val_mot0 = constante_mot1.to_bytes(2, 'little',signed=True)
    bytes_val_mot3 = constante_mot2.to_bytes(2, 'little',signed=True)
    bytes_val_mot2 = constante_mot3.to_bytes(2, 'little',signed=True)
    
    msg = can.Message(arbitration_id=0x401, data=[bytes_val_mot0[0],bytes_val_mot0[1],bytes_val_mot1[0],bytes_val_mot1[1],bytes_val_mot2[0],bytes_val_mot2[1],bytes_val_mot3[0],bytes_val_mot3[1]], is_extended_id=False)
    
    try:
      bus.send(msg)
      time.sleep(0.01)
    except can.CanError:
      print("Message NOT sent")
      
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


############################################ from pulse to rd/s #########################################

def Calcul_vitesse(P0,P1,P2,P3):
    # 2 pulse --> 2.5cm/s --> 0.5 rd/s
    R=0.04   * 100#cm
    alpha = 1041#2.56072580645161 #(cm/s)/pulse
    
    #rad/s
    w0 = P0 * (R/alpha) 
    w1 = P1 * (R/alpha) 
    w2 = P2 * (R/alpha) 
    w3 = P3 * (R/alpha) 
       
    wm = [w0,w1,w2,w3]
    
    return wm
    
############################# Integration et passage de R1 a R0  #####################################  
############################# --> Vitesses et Positions estimees #####################################

def Integral(V,Pose, dt):            
  
    x = Pose[0]
    y = Pose[1]
    th = Pose[2]

    vx = V[0]
    vy = V[1]
    vth = V[2]
    
    delta_x = (vx * cos(th) ) * dt
    delta_y = (vx * sin(th)) * dt
    delta_th = V[2] * dt 

    x += delta_x
    y += delta_y
    th += delta_th

   
    V = [vx, vy , vth ]
    Pose = [x, y, th]
   
    return V , Pose
    
#####################################################  [V]=[A].[W]   ########################################

def Model_Direct(Wm):
 
    R=0.08
    w=0.288
   
    Wl = (Wm[0] +  Wm[3])/2 
    Wr = (Wm[1] +  Wm[2])/2
   
    #matrice A
    A = np.array([[R/2,R/2],[0,0],[-R/w,R/w]])
    W= np.array([Wl,Wr])
   
    #Calcul de Vx,Vy,Vphi//[V]=[A].[W]
    V=A.dot(W)
    
   
    return V

def Model_Inv(x,y,phi):
    R=0.04
    w=0.288/2
    Wr = (x + phi * w)/R
    Wl = (x - phi * w)/R
    return [Wr, Wl]

def omniBlue():
    global P, current_time 
    P = [1, 0, 0]
    current_time = 0
    msg = bus.recv(0.02)
    BattVal = 0
    while msg is not None:
        if msg.arbitration_id == 0x403 or msg.arbitration_id == 0x400:
            pass
        else:
            d = struct.unpack('4h', msg.data)
            BattVal = ( d[3] & 0x00FF ) * 0.0645
        msg = bus.recv(0.002)
    print ("Battery value: " + str(BattVal))
    #subscribe to teleop twist keyboard
    rospy.init_node('car2', anonymous=True)
    rospy.Subscriber('cmd_vel', Twist, listener_callback1)
    rospy.Subscriber('car2/cmd_vel', Twist, listener_callback1)
    rospy.Timer(rospy.Duration(0.04), fill_encoders)


def fill_encoders(event):
    P0 =P1= P2=P3 = 0
    BattVal =0
    T = 0.04
    msg = bus.recv(0.002)
    while msg is not None:
        if msg.arbitration_id == 0x403:
            pass
        elif msg.arbitration_id == 0x400:
            print("Low battery detected")
        else:
            d = struct.unpack('4h', msg.data)
            BattVal = ( d[3] & 0x00FF ) * 0.0645
            if msg.arbitration_id == 0x404:
                P0 += float(d[0])
            if msg.arbitration_id == 0x414:
                P1 += float(d[0])
            if msg.arbitration_id == 0x424:
                P2 += float(d[0])
            if msg.arbitration_id == 0x434:
                P3 += float(d[0])
        msg = bus.recv(0.002)
    Send_odom(P0/T,P1/T,P2/T,P3/T,BattVal)
############################### envoie odometry #########################################

def Send_odom(P0,P1,P2,P3,BattVal):
    global P, current_time
#    print('P ' + str([P0,P1,P2,P3]))       
    #########               
    Wm = Calcul_vitesse(P0,P1,P2,P3)
#    print('Wm ' + str(Wm))       
    Vm = Model_Direct(Wm)#R1
#    print('Vm ' + str(Vm))       

    [Vel,P] = Integral(Vm,P, 0.04)     #Dans R0
    if ( P[2] > pi ) : # phi entre -pi et pi 
        P[2] -=  2*pi
    if ( P[2] < -pi ) :
        P[2] +=  2*pi
    current_time = current_time + 0.04
    current_ns = current_time
    if current_time > 1:
        current_ns -= int(current_time)

    odom = Odometry()
    timeStamp = time.time_ns()
    odom.header.stamp.secs = int(timeStamp/1e9)
    odom.header.stamp.nsecs = int(timeStamp - odom.header.stamp.secs * 1e9) 
    odom.header.frame_id = "odom"
    odom.child_frame_id = "base_mobile"
    
    # set the position
    odom.pose.pose.position.x = float(P[0])
    odom.pose.pose.position.y = float(P[1])
    odom.pose.pose.position.z = 0.0
#    print(P[2]*180/pi)
    q = quaternion_from_euler(0, 0, float(P[2]))
    odom.pose.pose.orientation.x = q[0]
    odom.pose.pose.orientation.y = q[1]
    odom.pose.pose.orientation.z = q[2]
    odom.pose.pose.orientation.w = q[3]

    # set the velocity
    odom.twist.twist.linear.x = Vel[0]
    odom.twist.twist.linear.y = Vel[1]
    odom.twist.twist.angular.z = Vel[2]
    
    pub.publish(odom)
    
#############################################################################################  


# controler 
def listener_callback1(msg):
#    rospy.loginfo("Received a Twist message!")
#    rospy.loginfo("Linear Components: [%f, %f, %f]"%(msg.linear.x, msg.linear.y, msg.linear.z))
#    rospy.loginfo("Angular Components: [%f, %f, %f]"%(msg.angular.x, msg.angular.y, msg.angular.z))
    W=Model_Inv(msg.linear.x, msg.linear.y,msg.angular.z)
#    print(W)
    #Send_odom()
    sendCan(W)   
   
def main(args=None):
    omniBlue()
    print("Omniblue initiated")
    rospy.spin()
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
 #   rclpy.shutdown()

if __name__ == '__main__':
    main()
