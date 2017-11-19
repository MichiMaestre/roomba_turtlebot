

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include "ros/ros.h"
#include "robot.hpp"

int main(int argc, char **argv) {

	ros::init(argc, argv, "walker");

	ros::NodeHandle n;

	robot turtle;

	ros::Rate loop_rate(10);
	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
	ros::Subscriber sub = n.subscribe("/scan", 1000, &robot::scanCallback, &turtle);


	int count = 0;
  	while (ros::ok()) {
		
		turtle.obstacle(turtle.lasers);


		ros::spinOnce();
    	loop_rate.sleep();
	}
	return 0;
}