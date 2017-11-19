/** MIT License
Copyright (c) 2017 Miguel Maestre Trueba
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *
 *@copyright Copyright 2017 Miguel Maestre Trueba
 *@file walker.cpp
 *@author Miguel Maestre Trueba
 *@brief Main algorithm for walker assignment
 */

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <cstdlib>
#include <string>
#include "ros/ros.h"
#include "ros/console.h"
#include "robot.hpp"

/**
 * @brief The main function is where the walker node is created and the velocity commands published
 * @param argc 
 * @param argv
 * @return 0 if everything works correctly
 */
int main(int argc, char **argv) {

	// Create node and handler
	ros::init(argc, argv, "walker");

	ros::NodeHandle n;

	robot turtle;
	geometry_msgs::Twist velocity;

	// Publisher
	ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 1000);
	// Subscriber
	ros::Subscriber sub = n.subscribe("/scan", 100, &robot::scanCallback, &turtle);

	ros::Rate loop_rate(10);

  	while (ros::ok()) {
		
		// If there is no obstacle, move forward
		if (!turtle.obstacle(turtle.lasers)) {
			ROS_INFO("All clear");

			velocity.linear.x = 0.2;
			velocity.angular.z = 0.0;

		}

		// If there is obstacle, rotate until there is no obstacle
		if (turtle.obstacle(turtle.lasers)) {
			ROS_INFO("Obstacle");

			velocity.linear.x = 0.0;
			velocity.angular.z = 0.2;
		}

		// Publish the velocity commands
		pub.publish(velocity);

		ros::spinOnce();
    	loop_rate.sleep();
	}
	return 0;
}