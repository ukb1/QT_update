#ifndef ROSNODE_H
#define ROSNODE_H

#include "project_type.h"

#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int8.hpp"
#include "example_interfaces/msg/string.hpp"
#include "std_msgs/msg/int16_multi_array.hpp"



class RosNode: public rclcpp::Node, public QObject
{
    Q_OBJECT
    Q_PROPERTY(std::string joyName READ getJoyName WRITE setJoyName NOTIFY joyNameChanged)
public:
    RosNode();
private:
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr joy_name_sub;
    rclcpp::Publisher<example_interfaces::msg::Int8>::SharedPtr     joy_udrl_pub;
    rclcpp::Publisher<example_interfaces::msg::Int8>::SharedPtr     joy_xrtc_pub;
    rclcpp::Publisher<std_msgs::msg::Int16MultiArray>::SharedPtr     ball_pub;

    std::string m_joyName;

public:
    RosNode();
    ~RosNode();
    std::thread _thread;
    void rosSpin();
    Q_INVOKABLE void joyudrlCallback(int8_t state);
    Q_INVOKABLE void joyxrtcCallbask(int8_t state);
    Q_INVOKABLE void ballCallback(int16_t x, int16_t y);





    std::string getJoyName() const;
    void setJoyName(const std::string &newJoyName);
signals:
    void joyNameChanged();
};

#endif // ROSNODE_H
