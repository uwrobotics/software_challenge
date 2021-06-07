#include "software_training/clear_turtles_server.hpp"

namespace software_training {

clear_turtles_server::clear_turtles_server(const rclcpp::NodeOptions& options) : rclcpp::Node("clear_turtles_server", options) {
    service = this->create_service<software_training::srv::Success>("clear_turtles", 
                                                                   std::bind(&clear_turtles_server::clear_turtles, this, std::placeholders::_1, std::placeholders::_2));
    kill_turtles_client = this->create_client<turtlesim::srv::Kill>("/kill");
}

void clear_turtles_server::clear_turtles(const std::shared_ptr<software_training::srv::Success::Request> request,
                                         std::shared_ptr<software_training::srv::Success::Response> response) {
    (void)request;

    if(!kill_turtles_client->wait_for_service(2s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            response->success = false;
            return;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available after trying for 2s. Exiting.");
        response->success = false;
        return;
    }

    for (auto& turtle_name: TURTLE_NAMES) {
        auto kill_request = std::make_shared<turtlesim::srv::Kill::Request>();
        kill_request->name = turtle_name;

        auto result = kill_turtles_client->async_send_request(kill_request);
    }

    response->success = true;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "All turtles cleared");
}

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(software_training::clear_turtles_server)