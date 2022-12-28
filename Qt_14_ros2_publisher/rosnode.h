#ifndef ROS_H
#define ROS_H

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"
#include <iostream>
#include <chrono>


class ros: public rclcpp::Node
{
public:
    ros():Node("QT_Node") {_publis = this->create_publisher<example_interfaces::msg::String>("Qt_Publis",10); }
    ~ros(){ rclcpp::shutdown(); }
    void qt_callback();

private:
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr _publis;
};


class ros_enable
{
private:
    std::thread _thread;
public:
    ros_enable();
    std::shared_ptr<ros> ros_node;
    void enable_pub();
};

#endif // ROS_H
