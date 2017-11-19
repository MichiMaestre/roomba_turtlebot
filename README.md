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

![gazebo](https://github.com/MichiMaestre/roomba-turtlebot/blob/master/images/gazebo.png)

## Recording and inspecting bag files

To record using rosbag, we have to launch `roomba.launch`but with the argument _rosbagFlag_ as true. If called as false or not called at all, the data will not be recorded.

* To record data:

```
cd ~/ros_ws
source devel/setup.bash
roslaunch roomba_turtlebot roomba.launch rosbagFlag:=true
```
This will record the data in the `~/.ros` folder. To access it and see its information:

```
cd ~/.ros
rosbag info roomba_bag.bag
```

* If the data recording is not needed, just launch:

`roslaunch roomba_turtlebot roomba.launch` or `roslaunch roomba_turtlebot roomba.launch rosbagFlag:=false`

## Bag file playback

Once the bag file is generated, we can replay it by running the following command in the directory where the bag file is*:

`rosbag play roomba_bag.bag`

*(Since Gazebo should not be running for the replay, `roscore` has to be launched in a first terminal)
