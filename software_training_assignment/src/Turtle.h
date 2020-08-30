#ifndef TURTLE_H
#define TURTLE_H

#include "ros/ros.h"

#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "turtlesim/Pose.h"

class Turtle {
    public:
        // ctor
        Turtle(ros::NodeHandle &n, float x, float y, std::string name);

        // kill `name` turtle
        static bool kill(ros::NodeHandle &n, std::string name);

        // turtle position accessors
        turtlesim::Pose getPosition() const;

    protected:
        ros::NodeHandle &n_;
        
        float startX_;
        float startY_;
        std::string name_;

        // position subscriber
        ros::Subscriber poseSubscriber_;
        turtlesim::Pose currentPosition_;

        // position subscriber callback
        void _positionCallback(const turtlesim::Pose &msgIn);

        // spawn `this` Turtle
        bool _spawn();
};

#endif
