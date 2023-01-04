from math import atan2,cos,sin,pi, sqrt
from pymodbus.client import ModbusTcpClient
import numpy as np
import time

def Model_direct(q4,q5,q6,q7,q8,q9):
	T01 = np.array([ [cos(q1), -sin(q1), 0, 0], [sin(q1), cos(q1), 0, 0], [0, 0, 1, 90], [0, 0, 0, 1] ])
	T12 = np.array([ [cos(q2), 0, sin(q2), 0], [0, 1, 0, 0], [-sin(q2), 0, cos(q2), 81.5], [0, 0, 0, 1] ])
	T23 = np.array([ [cos(q3), 0, sin(q3), 0], [0, 1, 0, 0], [-sin(q3), 0, cos(q3), 221], [0, 0, 0, 1] ])
	T34 = np.array([ [1, 0, 0, 45], [0, cos(q4), -sin(q4), 0], [0, sin(q4), cos(q4), 32.5], [0, 0, 0, 1] ])
	T45 = np.array([ [cos(q5), 0, sin(q5), 190], [0, 1, 0, 0], [-sin(q5), 0, cos(q5), 0], [0, 0, 0, 1] ])
	T56 = np.array([ [1, 0, 0, 23.7], [0, cos(q6), -sin(q6), 0], [0, sin(q6), cos(q6), -5.5], [0, 0, 0, 1] ])
	T06=T01.dot(T12).dot(T23).dot(T34).dot(T45).dot(T56)
	roll= atan2(sqrt(((T06[0,2])**2)+((T06[1,2])**2)), T06[2,2])
	if roll==0:
		pitch=0
		yaw=0
	else:
		yaw= atan2(T06[1,2]/sin(roll),T06[0,2]/sin(roll))
		pitch= atan2(T06[2,1]/sin(roll),-T06[2,0]/sin(roll))
	
	print("T01 : ", T01)
	
	print("T12 : ", T12)
	print("T23 : ", T23)
	print("T34 : ", T34)
	print("T45 : ", T45)
	print("T56 : ", T56)
	print("X", T06[0,3])
	print("Y", T06[1,3])
	print("Z", T06[2,3])
	print("Roll", roll)
	print("Pitch", pitch)
	print("Yaw", yaw)
	print("T06: ", T06)
if __name__ == '__main__':
	q1=0.2
	q2=0.2
	q3=0.2
	q4=0.2
	q5=0.2
	q6=0.2
	Model_direct(q1,q2,q3,q4,q5,q6)
	
	

