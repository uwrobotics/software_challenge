#pragma once

#include <rclcpp/rclcpp.hpp>
#include <turtlesim/msg/pose.hpp>
#include <swtraining/msg/distance.hpp>
#include <swtraining/software_training_visibility.h>

#include <chrono>
#include <cstdlib>
#include <memory>


namespace composition{
    class turtledistance : public rclcpp::Node{
        public:
            SOFTWARE_TRAINING_PUBLIC
            turtledistance(const rclcpp::NodeOptions &options);
        private:
            rclcpp::TimerBase::SharedPtr distTimer;
            rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr stSub;
            rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr mtSub;
            rclcpp::Publisher<swtraining::msg::Distance>::SharedPtr distPub;
            double stx;
            double sty;
            double mtx;
            double mty;
            SOFTWARE_TRAINING_LOCAL
            void timerCB();
            SOFTWARE_TRAINING_LOCAL
            void mtCB(const turtlesim::msg::Pose::SharedPtr res);
            SOFTWARE_TRAINING_LOCAL
            void stCB(const turtlesim::msg::Pose::SharedPtr res);
    };
}