#include "ros/ros.h"
#include "std_msgs/String.h"

#include <iostream>
#include <sstream>

#include "ros_shared_library_tutorials/add.hpp"
#include "ros_prebuild_shared_library_tutorials/hello.hpp"

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Rate loop_rate(10);

  std::cout << "add result:" << add(1, 2) << std::endl;
  hello();

  int count = 0;
  while (ros::ok()) {
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
