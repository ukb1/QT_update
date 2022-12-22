#ifndef ROSNODE_H
#define ROSNODE_H

#include <QObject>
#include <QThread>
// #include <QTimer>
// #include <QMutex>
#include <QDebug>
#include <QMessageBox>
#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/int32.hpp>
#include <example_interfaces/msg/string.hpp>


class rosNode: public QThread, public rclcpp::Node
{
    Q_OBJECT
private:
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr status_publis;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr text_publis;
    rclcpp::Subscription<example_interfaces::msg::Int32>::SharedPtr timer_subs;


public:
    rosNode(QObject* param=0);
    ~rosNode() { rclcpp::shutdown();}

    void run();
    bool stop;
    uint16_t value;
    void timerCallback(const example_interfaces::msg::Int32::SharedPtr timer);

signals:
    void timerChanged(int i);

public slots:
    void statusPublisher(std::string status);
    void textPublisher(std::string text);
};




#endif // ROSNODE_H
