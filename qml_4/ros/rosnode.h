#ifndef ROS_NODE_H
#define ROS_NODE_H

#include "rclcpp/rclcpp.hpp"
//#include "std_msgs/msg/int16_multi_array.hpp"
#include "example_interfaces/msg/string.hpp"
#include "geometry_msgs\\msg\\twist.hpp"
#include "project_type.h"

class RosNode: public QObject , public rclcpp::Node
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)

public:
    RosNode();
    ~RosNode();


    QString getName() const;
    void setName(const QString &newName);
    void setJoyName(const example_interfaces::msg::String::SharedPtr msg);
    Q_INVOKABLE void buttonCallback(int number);
    Q_INVOKABLE void ballStateCallback(int x, int y);

signals:
    void nameChanged();

private:
    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr  joy_name_sub;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr button_pub;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr ball_pub;
    
    void rosSpin();
    std::thread spin_thread;
    std::string joy_name;

    QString name;
};



#endif
