#include "rclcpp/rclcpp.hpp"
#include "motion_interfaces/srv/reset_service.hpp"
#include "turtlesim/srv/teleport_absolute.hpp"

using namespace std::chrono_literals;

void reset(const std::shared_ptr<motion_interfaces::srv::ResetService::Request> request, 
                std::shared_ptr<motion_interfaces::srv::ResetService::Response> response){
        
    const float x = 5.55;
    const float y = 5.55;
    const float theta = 0.0;
    
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("reset_client");
    rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr client =
                node->create_client<turtlesim::srv::TeleportAbsolute>("/moving_turtle/teleport_absolute");

    auto teleport_request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    teleport_request->x = x;
    teleport_request->y = y;
    teleport_request->theta = theta;

    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
    }

    auto result = client->async_send_request(teleport_request);
    if (rclcpp::spin_until_future_complete(node, result) ==
        rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: true");
        response->success = true;
    } else {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: true");
        response->success = false;
    }

}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "init server");

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("reset_server");

  rclcpp::Service<motion_interfaces::srv::ResetService>::SharedPtr service =
    node->create_service<motion_interfaces::srv::ResetService>("reset_turtle", &reset);

  rclcpp::spin(node);
  rclcpp::shutdown();
}