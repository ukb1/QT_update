#include "rosnode.h"


rosNode::rosNode(QObject* param): QThread(param), Node("TQ"), stop(true), value(0)
{
    rosSpin();
    _publis = this->create_publisher<example_interfaces::msg::Int32>("Qt_Publis",10);

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
    rclcpp::spin_some(this->get_node_base_interface());
}

void rosNode::qt_callback(int value)
{
    auto msg = example_interfaces::msg::Int32();
    msg.data = value;
    _publis->publish(msg);
}
