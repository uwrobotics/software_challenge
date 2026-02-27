#include <cmath>
#include <iostream>
#include <software_training/turtle_publisher.hpp>
#include <string>

using namespace std::chrono_literals;

namespace composition {

turtle_publisher::turtle_publisher(const rclcpp::NodeOptions &options)
    : Node("turtle_publisher", options) {

  auto stationary_turt_callback =
      [this](const turtlesim::msg::Pose::SharedPtr msg) -> void {
    this->x_stationary_turt = msg->x;
    this->y_stationary_turt = msg->y;
  };

  auto moving_turt_callback =
      [this](const turtlesim::msg::Pose::SharedPtr msg) -> void {
    this->x_moving_turt = msg->x;
    this->y_moving_turt = msg->y;
  };

  auto publisher_callback = [this](void) -> void {
    double position_x{std::abs(this->x_stationary_turt - this->x_moving_turt)};
    double position_y{std::abs(this->y_stationary_turt - this->y_moving_turt)};

    auto msg = std::make_unique<software_training::msg::Software>();
    msg->x_pos = position_x;
    msg->y_pos = position_y;
    msg->distance = std::sqrt((position_x * position_x) + (position_y * position_y));

    this->publisher->publish(std::move(msg));
  };

  callbacks =
      this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

  auto callback_option = rclcpp::SubscriptionOptions();
  callback_option.callback_group = callbacks;

  callback_option.topic_stats_options.state =
      rclcpp::TopicStatisticsState::Enable;

  std::string s_name("/statistics/");
  std::string node_name(this->get_name());
  std::string stat_name = s_name + node_name;
  callback_option.topic_stats_options.publish_topic = stat_name.c_str();

  stationary_turt_sub = this->create_subscription<turtlesim::msg::Pose>(
      "/stationary_turtle/pose", QUEUE, stationary_turt_callback,
      callback_option);

  moving_turt_sub = this->create_subscription<turtlesim::msg::Pose>(
      "/moving_turtle/pose", QUEUE, moving_turt_callback, callback_option);

  publisher = this->create_publisher<software_training::msg::Software>(
      "/difference", QUEUE);

  timer = this->create_wall_timer(3s, publisher_callback, callbacks);
}

} // namespace composition

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(composition::turtle_publisher)