

#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <sstream>
#include <cstdlib>
#include <string>
#include "ros/ros.h"
#include "robot.hpp"

void robot::scanCallback(const sensor_msgs::LaserScan::ConstPtr& laser) {
    for (int i = 0; i < laser->ranges.size(); i++) {
      std::cout << laser->ranges[i] << std::endl;;
    }
}