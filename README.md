### Roomba Turtlebot

## Overview



## Dependencies

* ROS Kinetic
* Catkin
* roscpp package
* std_msgs package
* genmsg package
* geometry_msgs package

## How to build

* Create a catkin workspace if it was not created previously:

```
mkdir ros_ws
cd ros_ws
mkdir src
catkin_make
```
* Clone the repository and build the package:
```
cd ros_ws
cd src
git clone https://github.com/MichiMaestre/roomba-turtlebot.git
cd ..
catkin_make
```

## How to run

* To run the package, just run the next two commands:

```
cd ~/ros_ws
source devel/setup.bash
roslaunch roomba_turtlebot roomba.launch
```

Gazebo will start with the corridor map and a turtlebot moving around as it is supposed: turning when it detects an obstacle or moving forward when there is no obstacle.

![gazebo](image)


