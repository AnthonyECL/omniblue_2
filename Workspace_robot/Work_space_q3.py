from pymodbus.client import ModbusTcpClient
import matplotlib.pyplot as plt
import pandas as pd
from mpl_toolkits.mplot3d import Axes3D
from math import atan2,cos,sin,pi, sqrt
import numpy as np
import time

def auto_calibration():
    print ("Calibrate Robot if needed ...")
    client.write_register(310 ,1)
    #print("ccccccc")
    client.write_register(311 ,1)
    # Wait for end of calibration
    while client.read_input_registers(402, 1).registers[0] == 1:
        time.sleep(0.05)

def number_to_raw_data(val):
    if val < 0:
        val = (1 << 15) - val
    return val


def raw_data_to_number(val):
    if (val >> 15) == 1:
        val = - (val & 0x7FFF)
    return val

def Model_direct(q1,q2,q3,q4,q5,q6):
	T01 = np.array([ [cos(q1), -sin(q1), 0, 0], [sin(q1), cos(q1), 0, 0], [0, 0, 1, 0.1195], [0, 0, 0, 1] ])
	T12 = np.array([ [cos(q2), 0, sin(q2), 0], [0, 1, 0, 0], [sin(q2), 0, cos(q2), 0.080], [0, 0, 0, 1] ])
	T23 = np.array([ [cos(q3), 0, sin(q3), 0], [0, 1, 0, 0], [sin(q3), 0, cos(q3), 0.210], [0, 0, 0, 1] ])
	T34 = np.array([ [1, 0, 0, 0.0655], [0, cos(q4), -sin(q4), 0], [0, sin(q4), cos(q4), 0.030], [0, 0, 0, 1] ])
	T45 = np.array([ [cos(q5), 0, sin(q5), 0.195], [0, 1, 0, 0], [-sin(q5), 0, cos(q5), 0], [0, 0, 0, 1] ])
	T56 = np.array([ [1, 0, 0, 0.0277], [0, cos(q6), -sin(q6), 0], [0, sin(q6), cos(q6), -0.0055], [0, 0, 0, 1] ])
	T06=T01.dot(T12).dot(T23).dot(T34).dot(T45).dot(T56)
	test=atan2(T06[2,1],T06[2,2])
	roll= atan2(sqrt(((T06[0,2])**2)+((T06[1,2])**2)), T06[2,2])
	if sin(roll)==0:
		pitch=0
		yaw=0
	else:
		yaw= atan2(T06[1,2]/sin(roll),T06[0,2]/sin(roll))
		pitch= atan2(T06[2,1]/sin(roll),-T06[2,0]/sin(roll))

	x_data.append(T06[0,3])
	y_data.append(T06[1,3])
	z_data.append(T06[2,3])

if __name__ == '__main__':
	print ("-- START")
	address = '169.254.200.200'
	client = ModbusTcpClient(address, port=5020)
	client.connect()
	print ("Connected to modbus server")
	auto_calibration()
	while client.read_input_registers(402, 1).registers[0] == 1:
		time.sleep(0.05)

	print ("Send a Joint Move command to the robot")
	joint_limits = [-1.07, 1.37]

	# Définir un pas d'incrément pour l'articulation
	step = 0.1

	x_data = []
	y_data = []
	z_data = []
	
	# Initialisation de la figure
	fig = plt.figure()
	ax = fig.add_subplot(111, projection='3d')

	# Génération des coordonnées pour chaque point dans l'espace de travail
	for i in np.arange(joint_limits[0], joint_limits[1], step):   
		joints = [0.0, 0.0, i, 0.0, 0.0]
		Model_direct(0.0, 0.0, i, 0.0, 0.0, 0.0)
		joints_to_send = list(map(lambda j: int(number_to_raw_data(j * 1000)), joints))
		print (joints_to_send)
		ax.scatter(x_data, y_data, z_data, c='b', marker='o')
		client.write_registers(0, joints_to_send)
		client.write_register(100, 1)

	while client.read_holding_registers(150, count=1).registers[0] == 1:
		time.sleep(0.01)
	
	# Personnalisation des options d'affichage
	ax.set_xlim(joint_limits)
	ax.set_xlabel('X(m)')
	ax.set_ylabel('Y(m)')
	ax.set_zlabel('Z(m)')
	ax.set_title('Espace de travail de l\'articulation q3')

	data_q3 = pd.read_csv("opti_q3.csv")
	x_data1=-data_q3.x
	y_data1=data_q3.y
	z_data1=data_q3.z
	ax.set_xlim([-1.0, 1.0])
	ax.set_ylim([-0.0, 0.8])
	ax.set_zlim([0.0, 0.7])
	ax.scatter(x_data1, y_data1, z_data1, c='r', marker='o')
	
	# Affichage de la figure
	plt.show()
	print ("Joint Move command is finished")
	# Activate learning mode
	client.write_register(300, 1)

	client.close()
