#include <rclcpp/rclcpp.hpp>
#include "example_interfaces/msg/int32.hpp"

class ros: public rclcpp::Node
{
private:
    rclcpp::Publisher<example_interfaces::msg::Int32>::SharedPtr timer_publisher;
    rclcpp::TimerBase::SharedPtr _timer;
    unsigned int _counter;


public:
    ros(): Node("Qt_ros"), _counter(0)
    {
        timer_publisher = this->create_publisher<example_interfaces::msg::Int32>("Timer", 10);
        _timer = this->create_wall_timer(std::chrono::seconds(1),
                                            std::bind(&ros::timerCallback,this));
    }
    void timerCallback()
    {
        _counter++;
        auto msg = example_interfaces::msg::Int32();
        msg.data = _counter;
        timer_publisher->publish(msg);
    }



};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ros>());
    rclcpp::shutdown();

}