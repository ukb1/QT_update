#include "rosnode.h"


rosNode::rosNode(QObject* param): QThread(param), Node("TQ")
{
    stop = true;
    value = 0;
    rosSpin();
    status_publis = this->create_publisher<example_interfaces::msg::String>("Status",10);
    _publis = this->create_publisher<example_interfaces::msg::Int32>("Qt_Publis",10);
}

void rosNode::run()
{
    while(stop)
    {
        
        qDebug() << value ;
        value++;
        auto msg = example_interfaces::msg::Int32();
        msg.data = value;
        _publis->publish(msg);
        this->msleep(100);
        emit startChanged(value);
    }  
}

void rosNode::rosSpin()
{
    rclcpp::spin_some(this->get_node_base_interface());
}

void rosNode::statusPublisher(std::string status)
{
    auto msg = example_interfaces::msg::String();
    msg.data = status;
    status_publis->publish(msg);

}
