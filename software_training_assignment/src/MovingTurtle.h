#ifndef MOVING_TURTLE_H
#define MOVING_TURTLE_H

#include "ros/ros.h"

#include <actionlib/server/simple_action_server.h>

#include "turtlesim/TeleportAbsolute.h"

#include <geometry_msgs/Twist.h>

#include "software_training_assignment/ResetMovingTurtle.h"
#include "software_training_assignment/MoveTurtleAction.h"

#include "Turtle.h"

// Singleton "moving_turtle" class
class MovingTurtle : public Turtle {
    public:
        // instance accessor
        static MovingTurtle* getInstance(ros::NodeHandle &n);

    private:
        // moving turtle reset service
        ros::ServiceServer resetService_;

        // moving turtle cmd_vel publisher
        ros::Publisher cmd_vel_pub_;

        // moving turtle action server
        actionlib::SimpleActionServer<software_training_assignment::MoveTurtleAction> actionServer_;

        // action parameters
        software_training_assignment::MoveTurtleResult result_;
        software_training_assignment::MoveTurtleFeedback feedback_;

        // ctor
        MovingTurtle(ros::NodeHandle &n);

        // reset service callback
        bool _resetCallback(software_training_assignment::ResetMovingTurtle::Request &req, software_training_assignment::ResetMovingTurtle::Response &res);

        // move action callback
        void _moveCallBack(const software_training_assignment::MoveTurtleGoalConstPtr &goal);
};

#endif
