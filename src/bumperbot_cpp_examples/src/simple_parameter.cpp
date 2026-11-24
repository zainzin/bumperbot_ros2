//
// Created by zain on 11/22/26.
//
#include "rclcpp/rclcpp.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"
#include <string>
#include <vector>

class SimpleParameter : public rclcpp::Node
{
public:
    SimpleParameter() : Node("simple_parameter")
    {
        declare_parameter<int>("simple_int_param", 28);
        declare_parameter<std::string>("simple_string_param", "Zain");
        parameters_callback_handle_ = add_on_set_parameters_callback([this](const std::vector<rclcpp::Parameter> & parameters)
        {
            RCLCPP_INFO(get_logger(), "Param override");
            rcl_interfaces::msg::SetParametersResult result;
            for (const auto & parameter : parameters)
            {
                if (parameter.get_name() == "simple_int_param" && parameter.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER)
                {
                    RCLCPP_INFO_STREAM(get_logger(), "Param simple_int_param override to new value " << parameter.as_int());
                    result.successful = true;
                }
                if (parameter.get_name() == "simple_string_param" && parameter.get_type() == rclcpp::ParameterType::PARAMETER_STRING)
                {
                    RCLCPP_INFO_STREAM(get_logger(), "Param simple_string_param override to new value " << parameter.as_string());
                    result.successful = true;
                }
            }
            return result;
        });
    }
private:
    OnSetParametersCallbackHandle::SharedPtr parameters_callback_handle_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimpleParameter>());
    rclcpp::shutdown();
    return 0;
}