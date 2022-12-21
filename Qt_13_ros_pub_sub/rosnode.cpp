#include "rosnode.h"




// ros::ros(): Node("QT_node")
// {
//     _publis = this->create_publisher<example_interfaces::msg::Int32>("Qt_Publis",10);
// }

// ros::~ros()
// {
//     rclcpp::shutdown();
// }




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


rosNode::rosNode(QObject* param): QThread(param), Node("TQ"), stop(true), value(0)
{
    rosSpinThread =  std::thread{std::bind(&rosNode::rosSpin, this)};
    _publis = this->create_publisher<example_interfaces::msg::Int32>("Qt_Publis",10);

}

rosNode::~rosNode()
{
    rclcpp::shutdown();
}

void rosNode::run()
{
    while(stop)
    {
        qDebug() << value ;
        value++;
        qt_callback(value);
        this->msleep(100);
        emit startChanged(value);
    }  
}

void rosNode::rosSpin()
{
    // ros_node = std::make_shared<rosNode>();
    rclcpp::spin(this->get_node_base_interface());
}


void rosNode::qt_callback(int value)
{
    auto msg = example_interfaces::msg::Int32();
    msg.data = value;
//    RCLCPP_INFO(this->get_logger(),"deneme");
    _publis->publish(msg);
}
