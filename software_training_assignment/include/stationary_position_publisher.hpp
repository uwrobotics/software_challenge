#ifndef STAT_POS_H
#define STAT_POS_HS

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>

#include <software_training_assignment/msg/position.hpp>
#include <turtle_info.hpp>
#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/pose.hpp>

#include <math.h>

namespace composition
{
class StationaryPosPublisher : public rclcpp::Node
{
    public:
        StationaryPosPublisher(const rclcpp::NodeOptions &options);

    private:
        rclcpp::Publisher<software_training_assignment::msg::Position>::SharedPtr publisher;
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr pose_sub;

        void get_pose(const turtlesim::msg::Pose::SharedPtr currentPose);
};
}

#endif