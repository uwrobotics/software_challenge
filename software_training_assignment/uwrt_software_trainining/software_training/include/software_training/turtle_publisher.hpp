#ifndef TURTLE_PUBLISHER_HPP_
#define TURTLE_PUBLISHER_HPP_

#include <memory>

#include <rclcpp/rclcpp.hpp>

#include <software_training/msg/software.hpp>
#include <software_training/visibility.h>
#include <turtlesim/msg/pose.hpp>

namespace composition {

class turtle_publisher : public rclcpp::Node {
public:
  SOFTWARE_TRAINING_PUBLIC
  explicit turtle_publisher(const rclcpp::NodeOptions &options);

private:
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr stationary_turt_sub;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr moving_turt_sub;
  rclcpp::Publisher<software_training::msg::Software>::SharedPtr publisher;
  rclcpp::TimerBase::SharedPtr timer;
  rclcpp::CallbackGroup::SharedPtr callbacks;

  float x_stationary_turt{0.0f};
  float y_stationary_turt{0.0f};
  float x_moving_turt{0.0f};
  float y_moving_turt{0.0f};

  float total_distance{0.0f};

  static const unsigned int QUEUE{10};
};
} // namespace composition

#endif // TURTLE_PUBLISHER_HPP_