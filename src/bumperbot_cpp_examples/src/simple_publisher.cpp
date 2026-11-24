#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <chrono>

using namespace std::chrono_literals;

class SimplePublisher : public rclcpp::Node
{
public:
    SimplePublisher() : Node("simple_publisher"), counter_(0)
    {
        publisher_ = create_publisher<std_msgs::msg::String>("chatter", 10);
        timer_ = create_wall_timer(1s, [this]()
        {
            auto message = std_msgs::msg::String();
            message.data = "Publishing at " + std::to_string(counter_++);
            publisher_->publish(message);
        });
        RCLCPP_INFO(get_logger(), "Publishing at 1 second interval");
    }
private:
    unsigned int counter_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    void publish()
    {
        auto message = std_msgs::msg::String();
        message.data = "Publishing at " + std::to_string(counter_++);
        publisher_->publish(message);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimplePublisher>());
    rclcpp::shutdown();
    return 0;
}