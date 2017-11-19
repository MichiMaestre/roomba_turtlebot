

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include "ros/ros.h"
#include "ros/console.h"
#include "robot.hpp"

int main(int argc, char **argv) {

	ros::init(argc, argv, "walker");

	ros::NodeHandle n;

	robot turtle;
	geometry_msgs::Twist velocity;

	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
	ros::Subscriber sub = n.subscribe("/scan", 100, &robot::scanCallback, &turtle);

	ros::Rate loop_rate(10);

  	while (ros::ok()) {
		
		if (!turtle.obstacle(turtle.lasers)) {
			ROS_INFO("All clear");

			velocity.linear.x = 0.2;
			velocity.angular.z = 0.0;

		}
		if (turtle.obstacle(turtle.lasers)) {
			ROS_INFO("Obstacle");

			velocity.linear.x = 0.0;
			velocity.angular.z = 0.2;
		}

		pub.publish(velocity);

		ros::spinOnce();
    	loop_rate.sleep();
	}
	return 0;
}