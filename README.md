# Omniblue 

Fork of omniblue with all the cmd_vel and odom topics included, organized as nodes with the car number.
- omniblue.py has the same holonomic model as the ROS2 version
- omniblue_diff.py has another model with regular wheels (differential motion)
- omniblue_diff_class.py is refactored and outputs also the tf topic 

## Launch instructions

### Hardware set-up:
- Router must be on, the wifi network *Robots*, and *Robots_5G* (for 5GHz link) must be visible (password: wirelesstrain), Ethernet connexion is also possible.
- Tracking station must be active, make sure that modem, static and mobile beacons are all ON, and the radio link is active (plug the modem to a computer with a MarvelMind Dashboard V7.08 to check status)
- Power the vehicles. Both batteries must be charged, the moment they are plugged, both control boards and the Raspberry Pi will power on.

### Network architecture
At start up, the router grants IP adresses in the following pools:
- The MAC Address *00-0C-29-4E-0B-3A* gets IP *192.168.0.3* and is **MASTER**.
- The MAC Address *90-CC-DF-3D-C7-DC* gets IP *192.168.0.4*. It is intended for the MatLab client
- The MAC Address *08-00-27-02-BE-04* gets IP *192.168.0.5*. It is intended for an external observer (EG. visualization, plotting, map generation, etc.)
- IP addresses in the pool *192.168.0.1X* are granted for the vehicle number X (EG. 192.168.0.12 is for car 2)

### Software deployment
Once connected through SSH to each one of the cars (user: ubuntu password: raspberry), and the ROS MASTER initiated, running the following command line starts the MarvelMind acquisition: *rosrun marvelmind_nav hedge_rcv_bin __ns:=/carX /dev/ttyACM0*. 
Where X must be replaced with the car number. Check the serial ports available in case of problems.

To launch the last version of the code, run *rosrun omniblue_diff_class.py*. after initialisation, the application will only output the battery voltage and the message *"Low battery detected"*. 
In case of this being triggered by the emergency stop, (either through safety button or overcurrent detection), to continue usig the system, stop the application and type the following command line: *cansend can0 403#*. 
A relay should click feeding again current to the motors.


**Car 2 only**: Launching the lidar within the car2 node:  rosrun rplidar_ros rplidarNode __ns:=/car2
transformation for the lidar: rosrun tf static_transform_publisher 0 0 0 0 0 0 /car2/odom laser_frame 40

A virtual machine is also available ...
