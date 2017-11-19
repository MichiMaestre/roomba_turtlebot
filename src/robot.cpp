

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "ros/ros.h"
#include "robot.hpp"

void robot::scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser) {
    robot::lasers.clear();
    for (int i = 0; i < laser->ranges.size(); i++) {
    	robot::lasers.push_back(laser->ranges[i]);
    }
}


bool robot::obstacle(std::vector<double> laserscans) {
	double min = 65.0;
	for (int i = 0; i < laserscans.size(); i++) {
	    if (laserscans[i] < min) {
	      	min = laserscans[i];
	    }
	}
	// std::cout << "Min: " << min << std::endl;

	if (min < 0.55) 
		return true;
	else 
		return false;
}