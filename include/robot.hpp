#pragma once

#include <sensor_msgs/LaserScan.h>
#include <vector>
#include "ros/ros.h"

class robot {
	public:
		std::vector<double> lasers;
		void scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser);

		bool obstacle(std::vector<double> laserscans);
};