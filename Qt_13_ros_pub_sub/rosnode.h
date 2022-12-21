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

class rosNode: public QThread, rclcpp::Node
{
    Q_OBJECT
private:
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr _publis;

public:
    void qt_callback(int value);
    rosNode(QObject* param=0);
    ~rosNode() { rclcpp::shutdown();}

    void run();
    bool stop;
    uint16_t value;
    void rosSpin();

signals:
    void startChanged(int i);
};




#endif // ROSNODE_H
