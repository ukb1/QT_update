#include "rosnode.h"


rosNode::rosNode(QObject* param): QThread(param) /*QObject(param)*/, Node("TQ")
{
    stop = true;
    value = 0;
    rosSpin();
    status_publis = this->create_publisher<example_interfaces::msg::String>("Status",10);
    text_publis = this->create_publisher<example_interfaces::msg::String>("Text",10);
    timer_subs = this->create_subscription<example_interfaces::msg::Int32>("Timer",10, std::bind(&rosNode::timerCallback,this, std::placeholders::_1) );

    // _publis = this->create_publisher<example_interfaces::msg::Int32>("Qt_Publis",10);
}

void rosNode::run()
{
    rclcpp::spin(this->get_node_base_interface());

    

/*
Bu kısım kendi içinde bir sayaçbaşlatıp bu sayaçtan bir sinyal üretiyordu
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
*/
  
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

void rosNode::textPublisher(std::string text)
{
    auto msg = example_interfaces::msg::String();
    msg.data = text;
    text_publis->publish(msg);
}


void rosNode::timerCallback(const example_interfaces::msg::Int32::SharedPtr timer)
{
    int value = timer->data;
    emit timerChanged(value);

}
