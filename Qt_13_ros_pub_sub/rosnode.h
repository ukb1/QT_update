#ifndef ROSNODE_H
#define ROSNODE_H

#include <QObject>
#include <QThread>
#include <QTimer>
#include <QMutex>
#include <QDebug>
#include <QMessageBox>
#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/int32.hpp>




class ros: public rclcpp::Node
{
public:
    ros();
    ~ros();
    void qt_callback(int value);
private:
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr _publis;

};



class rosNode: public QThread
{
    Q_OBJECT
private:
    std::thread rosSpinThread;
public:
    rosNode(QObject* param=0);

    void run();
    bool stop;
    QMutex mutex;
    QThread* thread;
    uint16_t value;
    void rosSpin();
    std::shared_ptr<ros> ros_node;

signals:
    void startChanged(int i);
    void ros_publisher();


};




// class  rosEnable : public ros
// {
// private:


// public:

// }



/////////////////////////////////////////////////////////////////////////////////////////////////////




#endif // ROSNODE_H
