#include <software_training/cmd_vel_moving_turt_publisher.hpp>

using namespace std::chrono_literals;

namespace composition {

cmd_vel_moving_turt_publisher::cmd_vel_moving_turt_publisher(
    const rclcpp::NodeOptions &options)
    : Node("cmd_vel_moving_turt_publisher", options) {

  auto publisher_callback = [this](void) -> void {
    auto message = std::make_unique<geometry_msgs::msg::Twist>();
    message->linear.x = coordinates::linear::x;
    message->linear.y = coordinates::linear::y;
    message->linear.z = coordinates::linear::z;

    message->angular.x = coordinates::angular::x;
    message->angular.y = coordinates::angular::y;
    message->angular.z = coordinates::angular::z;

    this->publisher->publish(std::move(message));
  };

  // create the publisher
  // also create a QoS object with a history/depth of 10 calls
  this->publisher = this->create_publisher<geometry_msgs::msg::Twist>(
      "/turtle1/cmd_vel", rclcpp::QoS(QUEUE));

  this->timer = this->create_wall_timer(100ms, publisher_callback);
}

} // namespace composition

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::cmd_vel_moving_turt_publisher)