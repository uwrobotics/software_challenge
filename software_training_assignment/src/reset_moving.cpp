#include "reset_moving.hpp"

using namespace std::placeholders;
using namespace std::chrono_literals;

namespace composition
{

ResetMoving::ResetMoving(const rclcpp::NodeOptions & options)
    : Node("reset_moving")
{
    this->teleport_cli = this->create_client<turtlesim::srv::TeleportAbsolute>("moving_turtle/teleport_absolute");

    RCLCPP_INFO(this->get_logger(), "HERE RESET");

    this->teleport_srv = this->create_service<software_training_assignment::srv::ExampleService>
            ("moving_turtle_reset", 
            std::bind(&ResetMoving::reset_moving_turtle, this, _1, _2)); 
}


void ResetMoving::reset_moving_turtle(
    const std::shared_ptr<software_training_assignment::srv::ExampleService::Request> request,
    std::shared_ptr<software_training_assignment::srv::ExampleService::Response> response)
{
    if (!teleport_cli->wait_for_service(2s)) 
    {
        RCLCPP_INFO(this->get_logger(), "Try again");
        response->output = false;
        return;
    }

    std::shared_ptr<turtlesim::srv::TeleportAbsolute::Request> teleport_request = 
        std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();

    teleport_request->x = turtles.find("moving_turtle")->second[0];
    teleport_request->y = turtles.find("moving_turtle")->second[1];
    teleport_request->theta = 0;

    RCLCPP_INFO(this->get_logger(), "x: " + std::to_string(teleport_request->x) + 
        " y: " + std::to_string(teleport_request->y));
    
    auto end = [this] (rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedFuture future)
        -> void {
            RCLCPP_INFO(this->get_logger(), "done");
            rclcpp::shutdown();
        };

    auto result = teleport_cli->async_send_request(teleport_request, end);
    RCLCPP_INFO(this->get_logger(), "sent");

    response->output = true;
}

}

RCLCPP_COMPONENTS_REGISTER_NODE(composition::ResetMoving)