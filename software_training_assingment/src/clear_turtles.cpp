#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>
#include <turtlesim/srv/kill.hpp>
using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);


  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("clear_turtles");
  rclcpp::Client<turtlesim::srv::Kill>::SharedPtr client =
    node->create_client<turtlesim::srv::Kill>("kill");

  auto request = std::make_shared<turtlesim::srv::Kill::Request>();
  request->name = "turtle1";
  //request->a = atoll(argv[1]);
  //request->b = atoll(argv[2]);

  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Turtle Killed");
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
  }

  rclcpp::shutdown();
  return 0;
}
