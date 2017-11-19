#ifndef ROBOT_H_ // NOLINT
#define ROBOT_H_

#include <sensor_msgs/LaserScan.h>
#include "ros/ros.h"

class robot {
	public:
		void scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser);

};

#endif