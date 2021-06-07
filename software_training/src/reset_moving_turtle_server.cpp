#include "software_training/reset_moving_turtle_server.hpp"

namespace software_training {

reset_moving_turtle_server::reset_moving_turtle_server(const rclcpp::NodeOptions& options) : rclcpp::Node("reset_moving_turtle_server", options) {
    service = this->create_service<software_training::srv::Success>("reset_moving_turtle", 
                                                                   std::bind(&reset_moving_turtle_server::reset_moving_turtle, this, std::placeholders::_1, std::placeholders::_2));
    teleport_turtle_client = this->create_client<turtlesim::srv::TeleportAbsolute>("/moving_turtle/teleport_absolute");
}

void reset_moving_turtle_server::reset_moving_turtle(const std::shared_ptr<software_training::srv::Success::Request> request,
                                                     std::shared_ptr<software_training::srv::Success::Response> response) {
    (void)request;

    if(!teleport_turtle_client->wait_for_service(2s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            response->success = false;
            return;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available after trying for 2s. Exiting.");
        response->success = false;
        return;
    }

    auto teleport_request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    teleport_request->x = START_X;
    teleport_request->y = START_Y;
    teleport_request->theta = 0;

    auto result = teleport_turtle_client->async_send_request(teleport_request);

    response->success = true;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "moving_turtle reset");
}

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(software_training::reset_moving_turtle_server)