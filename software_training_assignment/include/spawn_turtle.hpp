#ifndef SPAWN_H
#define SPAWN_H

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>

#include "turtlesim/srv/spawn.hpp"

#include <turtle_info.hpp>
#include <visibility.h>
#include <thread>

namespace composition
{
class SpawnTurtle : public rclcpp::Node
{
    public:
        SOFTWARE_TRAINING_PUBLIC
        explicit SpawnTurtle(const rclcpp::NodeOptions &options);

    private:
        rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr srv_client;
        rclcpp::TimerBase::SharedPtr timer;

        SOFTWARE_TRAINING_LOCAL
        void spawn_turtles();
};
}

#endif