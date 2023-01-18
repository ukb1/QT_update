#include "rosnode.h"

RosNode::RosNode(): Node("joystick"), m_joyName("EMS")
{
    _thread      = std::thread{
                       std::bind(&RosNode::rosSpin, this)
                    };
    joy_name_sub = this->create_subscription<example_interfaces::msg::String>
                    ("joyName", 10, std::bind(&RosNode::setJoyName, this, std::std::placeholders::_1));


}

~RosNode()
{
    rclcpp::shutdown();
}

void RosNode::rosSpin()
{
    rclcpp::init(0,nullptr);
    rclcpp::spin(this->get_node_base_interface());
    rclcpp::shutdown();

}

std::string RosNode::getJoyName() const
{
    return m_joyName;
}

void RosNode::setJoyName(const std::string &newJoyName)
{
    if (m_joyName == newJoyName)
        return;
    m_joyName = newJoyName;
    emit joyNameChanged();
}
