#include "software_training/spawn_turtles_server.hpp"

namespace software_training {

spawn_turtles_server::spawn_turtles_server(const rclcpp::NodeOptions& options) : rclcpp::Node("spawn_turtles_server", options) {
    service = this->create_service<software_training::srv::Success>("spawn_turtles", 
                                                                   std::bind(&spawn_turtles_server::spawn_turtles, this, std::placeholders::_1, std::placeholders::_2));
    spawn_turtle_client = this->create_client<turtlesim::srv::Spawn>("/spawn");
}

void spawn_turtles_server::spawn_turtles(const std::shared_ptr<software_training::srv::Success::Request> request,
                                         std::shared_ptr<software_training::srv::Success::Response> response) {
    (void)request;

    if(!spawn_turtle_client->wait_for_service(2s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            response->success = false;
            return;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service not available after trying for 2s. Exiting.");
        response->success = false;
        return;
    }

    for (turtle_descriptor& turtle: turtle_descriptions) {
        auto spawn_request = std::make_unique<turtlesim::srv::Spawn::Request>();
        spawn_request->x = turtle.x;
        spawn_request->y = turtle.y;
        spawn_request->theta = 0;
        spawn_request->name = turtle.name;

        auto result = spawn_turtle_client->async_send_request(std::move(spawn_request));
    }

    response->success = true;
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "All turtles spawned");
}

}

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(software_training::spawn_turtles_server)