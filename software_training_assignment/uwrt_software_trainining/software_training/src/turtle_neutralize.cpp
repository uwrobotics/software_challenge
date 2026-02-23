#include <software_training/turtle_neutralize.hpp>

using namespace std::chrono_literals;

namespace composition {

turtle_service_request_node::turtle_service_request_node(
    const rclcpp::NodeOptions &options)
    : Node("turtle_service_request_node", options) {
  client = this->create_client<turtlesim::srv::Kill>("/kill");
  timer = this->create_wall_timer(
      2s, std::bind(&turtle_service_request_node::kill, this));
}

void turtle_service_request_node::kill() {

  this->timer->cancel();

  if (!client->wait_for_service(2s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(this->get_logger(),
                   "Interrupted while waiting for service. Exiting!");
      return;
    }
    RCLCPP_INFO(this->get_logger(), "Service not available after waiting");
    return;
  }

  for (std::string &name : turtle_names) {
    auto request = std::make_shared<turtlesim::srv::Kill::Request>();
    request->name = name;

    auto callback =
        [this](rclcpp::Client<turtlesim::srv::Kill>::SharedFuture response)
        -> void {
      (void)response;
      RCLCPP_INFO(this->get_logger(), "Turtle Killed");
    };

    auto result = client->async_send_request(request, callback);
  }
}

} // namespace composition

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::turtle_service_request_node)