//
// Created by zain on 11/19/26.
//

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class SimpleSubscriber : public rclcpp::Node
{
public:
    SimpleSubscriber() : Node("simple_subscriber")
    {
        subscriber_ = create_subscription<std_msgs::msg::String>("chatter", 10, [this](std_msgs::msg::String message)
        {
            RCLCPP_INFO(get_logger(), message.data.c_str());
        });
    }
    private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleSubscriber>());
    rclcpp::shutdown();
    return 0;
}