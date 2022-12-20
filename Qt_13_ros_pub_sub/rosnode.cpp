#include "rosnode.h"




ros::ros(): Node("QT_node")
{
    _publis = this->create_publisher<example_interfaces::msg::Int32>("Qt_Publis",10);
}

ros::~ros()
{
    rclcpp::shutdown();
}

void ros::qt_callback()
{
    auto msg = example_interfaces::msg::Int32();
    msg.data = 65;
//    RCLCPP_INFO(this->get_logger(),"deneme");
    _publis->publish(msg);
}


/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/


rosNode::rosNode(QObject* param): QThread(param), stop(true), value(0)
{
    rosSpinThread =  std::thread{std::bind(&rosNode::rosSpin, this)};
}

void rosNode::run()
{
    while(stop)
    {
        qDebug() << value ;
        value++;
        if(value==100) value=0;
        this->msleep(100);
        emit startChanged(value);
    }  
}

void rosNode::rosSpin()
{
    rclcpp::init(0, nullptr);
    ros_node = std::make_shared<ros>();
    rclcpp::spin(ros_node);
    rclcpp::shutdown();

}
