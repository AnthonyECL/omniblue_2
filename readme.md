# Bras_Manipulateur

## Desciption

In the first repository, you will find the implementation of the forward geometric model of the Niryo's NED robot in python. Niryo NED here is connected via Modbus TCP, more details are available on the documentation below:
https://docs.niryo.com/dev/modbus/v3.2.0/en/index.html

In the second repository, you will find the algo contains the `forward_geometric_model` node, which is a Publisher/subscriber node, the node subscribes to `mocap_rigid_bodies` to get the poses of the Niryo's NED robot.

Also we defined the workspace of a robotic arm which refers to the range of positions and orientations that the end effector (e.g. the gripper or tool) can reach. The size and shape of the workspace is determined by the design of the robot's joints and links.

The resulting data is used to create a 3D model of the robot's workspace.
