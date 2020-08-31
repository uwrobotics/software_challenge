#include "MovingTurtle.h"

#include "turtlesim/Pose.h"

#define _USE_MATH_DEFINES
#include <cmath>

MovingTurtle* MovingTurtle::getInstance(ros::NodeHandle &n) {
    // lazy instantiation
    static MovingTurtle instance_(n);
    return &instance_;
}

// ctor
MovingTurtle::MovingTurtle(ros::NodeHandle &n) :
    Turtle(n, 25, 10, "moving_turtle"),
    resetService_(n.advertiseService("reset_moving_turtle", &MovingTurtle::_resetCallback, this)),
    cmd_vel_pub_(n.advertise<geometry_msgs::Twist>(name_ + "/cmd_vel", 1000)),
    actionServer_(n, "move_turtle_action_server", boost::bind(&MovingTurtle::_moveCallBack, this, _1), false) {

        // start action server
        actionServer_.start();
}

bool MovingTurtle::_resetCallback(software_training_assignment::ResetMovingTurtle::Request &req, software_training_assignment::ResetMovingTurtle::Response &res) {
    // init teleport service client
    ros::ServiceClient teleportClient = n_.serviceClient<turtlesim::TeleportAbsolute>(name_ + "/teleport_absolute");
    turtlesim::TeleportAbsolute teleportSrv;

    // set request to starting position
    teleportSrv.request.x = startX_;
    teleportSrv.request.y = startY_;
    teleportSrv.request.theta = 0;

    // attempt teleportation
    res.success = teleportClient.call(teleportSrv);
    return res.success;
}

void MovingTurtle::_moveCallBack(const software_training_assignment::MoveTurtleGoalConstPtr &goal) {
    ros::Rate loop_rate(1);

    ros::Time startTime = ros::Time::now();

    // setup message parameters
    geometry_msgs::Twist msg;
    msg.linear.y = 0;
    msg.linear.z = 0;
    msg.angular.x = 0;
    msg.angular.y = 0;

    turtlesim::Pose currPosition = getPosition();
    float deltaX = goal->x - currPosition.x;
    float deltaY = goal->y - currPosition.y;
    
    // publish rotation request

    float angleToGoal = atan(deltaY / deltaX);
    if (deltaX >= 0) {
        angleToGoal -= currPosition.theta;
    } else {
        angleToGoal -= (currPosition.theta - M_PI);
    }

    msg.linear.x = 0;
    msg.angular.z = angleToGoal;
    cmd_vel_pub_.publish(msg);

    loop_rate.sleep();
    
    // publish movement request

    float distanceToGoal = sqrt(pow(deltaX, 2) + pow(deltaY, 2));
    
    msg.linear.x = distanceToGoal;
    msg.angular.z = 0;
    cmd_vel_pub_.publish(msg);

    loop_rate.sleep();

    // set result and feedback
    result_.time = ros::Time::now() - startTime;
    feedback_.distance = distanceToGoal;
    
    // publish action feedback, and result
    actionServer_.publishFeedback(feedback_);
    actionServer_.setSucceeded(result_);
}
