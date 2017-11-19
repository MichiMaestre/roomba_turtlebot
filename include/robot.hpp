#pragma once

#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Twist.h>
#include <vector>
#include "ros/ros.h"

class robot {
	public:
		std::vector<double> lasers;
		void scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser);

		bool obstacle(std::vector<double> laserscans);

		// geometry_msgs::Twist velocity(double linear_vel, double angular_vel);
};