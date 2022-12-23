#include "ros.h"

//////////////////////////////////////////////////////////////////////////
void ros::qt_callback()
{
    auto msg = example_interfaces::msg::String();
    msg.data = "deneme";
    RCLCPP_INFO(this->get_logger(),"deneme");
    _publis->publish(msg);
}
//////////////////////////////////////////////////////////////////////////







ros_enable::ros_enable()
{
    _thread = std::thread{std::bind(&ros_enable::enable_pub, this)};
}

void ros_enable::enable_pub()
{
    rclcpp::init(0, nullptr);
    ros_node = std::make_shared<ros>();
    rclcpp::spin(ros_node);
    rclcpp::shutdown();
}   
