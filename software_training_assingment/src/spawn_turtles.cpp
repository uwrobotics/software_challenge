#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <cstdlib>
#include <memory>
#include <turtlesim/srv/spawn.hpp>
using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);


  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("spawn_turtles");
  rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr client =
    node->create_client<turtlesim::srv::Spawn>("spawn");
  std::string name[2] = {"stationary_turtle", "moving_turtle"};
  int x[2] = {5, 25};
  int y[2] = {5,10};
  for (int i = 0; i < 2; i++)
  {
	  auto request = std::make_shared<turtlesim::srv::Spawn::Request>();
	  request->name = name[i];
	  request->x = x[i];
	  request-> y = y[i];
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
	    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Turtle Created");
	  } else {
	    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
	  }
  
  }

  

  rclcpp::shutdown();
  return 0;
}
