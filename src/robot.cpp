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
 *@file robot.cpp
 *@author Miguel Maestre Trueba
 *@brief Class robot definition code
 */


#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "ros/ros.h"
#include "robot.hpp"


/**
 * @brief Reads the LaserScan information from geometry_msgs
 * @param laser contains all the laser readings in the current iteration
 */
void robot::scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser) {
    robot::lasers.clear();
    for (int i = 0; i < laser->ranges.size(); i++) {
    	// Store all the laser reading in the vector
    	robot::lasers.push_back(laser->ranges[i]);
    }
}

/**
 * @brief Function that reads all the laser readings, selects the minimum and checks if there is obstacle near the robot or not
 * @param laserscans is the vector that contains all the laser reading caught by subscriber 
 * @return true if there is obstacle or false if there is not obstacle
 */
bool robot::obstacle(std::vector<double> laserscans) {
	// Select minimum from all the laser readings 
	double min = 65.0;
	for (int i = 0; i < laserscans.size(); i++) {
	    if (laserscans[i] < min) {
	      	min = laserscans[i];
	    }
	}
	// std::cout << "Min: " << min << std::endl;

	// Check if there is obstacle near the robot or not and return false or true
	if (min < 0.55) 
		return true;
	else 
		return false;
}