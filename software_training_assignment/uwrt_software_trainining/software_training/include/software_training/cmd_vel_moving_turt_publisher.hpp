#ifndef CMD_VEL_MOVING_TURT_PUBLISHER_HPP_
#define CMD_VEL_MOVING_TURT_PUBLISHER_HPP_

#include <chrono>
#include <cstdlib>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <software_training/visibility.h>

namespace composition {

class cmd_vel_moving_turt_publisher : public rclcpp::Node {

public:
  SOFTWARE_TRAINING_PUBLIC
  explicit cmd_vel_moving_turt_publisher(const rclcpp::NodeOptions &options);

private:
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
  rclcpp::TimerBase::SharedPtr timer;

  static constexpr unsigned int QUEUE{10};

  struct coordinates {
    struct linear {
      static constexpr float x = 2.0; 
      static constexpr float y = 0.0;
      static constexpr float z = 0.0;
    };
    struct angular {
      static constexpr float x = 0.0;
      static constexpr float y = 0.0;
      static constexpr float z = 2.0; 
    };
  };
};

} // namespace composition

#endif //  CMD_VEL_MOVING_TURT_PUBLISHER_HPP_
