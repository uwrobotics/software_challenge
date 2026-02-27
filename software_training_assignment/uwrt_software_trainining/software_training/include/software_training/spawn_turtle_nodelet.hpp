#ifndef SPAWN_TURTLE_NODELET_HPP_
#define SPAWN_TURTLE_NODELET_HPP_

#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <software_training/visibility.h>
#include <turtlesim/srv/spawn.hpp>

namespace composition {

class spawn_turtle_nodelet : public rclcpp::Node {
public:
  SOFTWARE_TRAINING_PUBLIC
  explicit spawn_turtle_nodelet(const rclcpp::NodeOptions &options);

private:
  rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr client;
  rclcpp::TimerBase::SharedPtr timer;

  SOFTWARE_TRAINING_LOCAL
  void spawn_turtle();

  static const unsigned int NUMBER_OF_TURTLES{2};

  struct turtle_info {
    float x_pos;
    float y_pos;
    float rad;
  };

  std::vector<std::string> turtle_names{"stationary_turtle", "moving_turtle"};
  std::vector<turtle_info> turtle_bio{{5.0, 5.0, 0.0}, {25.0, 10.0, 0.0}};

  std::map<std::string, turtle_info> turtle_description;
};

} // namespace composition

#endif // SPAWN_TURTLE_NODELET_HPP_