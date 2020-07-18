#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <software_training_assignment/MoveAction.h>
// #include "ros/console.h"

#include <cmath>
#include <cstdlib>
#include <std_srvs/Empty.h>
#include <turtlesim/Kill.h>
#include <turtlesim/Spawn.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <software_training_assignment/resetMovingTurtle.h>
#include <software_training_assignment/Distance.h>

void clearTurtles(ros::NodeHandle & n) {
    ros::ServiceClient resetClient = n.serviceClient<std_srvs::Empty>("reset");
    std_srvs::Empty resetSrv;

    bool resetComplete = false;
    while (!resetComplete) {
        if(resetClient.call(resetSrv)) {
            ROS_INFO_STREAM("Completed reset");
            resetComplete = true;
        } else {
            ROS_INFO_STREAM("Have to make another call");
        }
    }

    ros::ServiceClient killClient = n.serviceClient<turtlesim::Kill>("kill");
    turtlesim::Kill killSrv;
    killSrv.request.name = "turtle1";
    if (killClient.call(killSrv)) {
        ROS_INFO_STREAM("cleared all turtles");
    }
}

void spawnTurtles(ros::NodeHandle & n) {
    ros::ServiceClient spawnClient = n.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn spawnSrv;

    spawnSrv.request.x = 5;
    spawnSrv.request.y = 5;
    spawnSrv.request.theta = 0;
    spawnSrv.request.name = "stationary_turtle";

    if(spawnClient.call(spawnSrv)) {
        ROS_INFO_STREAM(spawnSrv.response);
    } else {
        ROS_INFO_STREAM("Failed to spawn turtle");
    }

    spawnSrv.request.x = 25;
    spawnSrv.request.y = 10;
    spawnSrv.request.theta = 0;
    spawnSrv.request.name = "moving_turtle";

    if(spawnClient.call(spawnSrv)) {
        ROS_INFO_STREAM(spawnSrv.response);
    } else {
        ROS_INFO_STREAM("Failed to spawn turtle");
    }
}
class MovingTurtleReset {
    ros::NodeHandle n;
public:
    MovingTurtleReset(ros::NodeHandle & newHandle) {
        n = newHandle;
        ros::ServiceServer service = n.advertiseService("reset_moving_turtle", &MovingTurtleReset::turtleBehaviourServerCallback, this);
        ros::spinOnce();
    }
    
    bool turtleBehaviourServerCallback(software_training_assignment::resetMovingTurtle::Request &req, 
    software_training_assignment::resetMovingTurtle::Response &res) {
        ros::ServiceClient teleportClient = n.serviceClient<turtlesim::TeleportAbsolute>("moving_turtle/teleport_absolute");
        turtlesim::TeleportAbsolute srv;
        srv.request.x = 25;
        srv.request.y = 10;
        srv.request.theta = 0;

        if(teleportClient.call(srv)) {
            return true;
        } else {
            return false;
        }
    }
};


class DistancePublisher {
    ros::NodeHandle n;
    bool endStationarySubscription;
    bool endMovingSubscription;
    double stationaryTurtleX;
    double stationaryTurtleY;
    double movingTurtleX;
    double movingTurtleY;

    void stationaryCallback(const turtlesim::Pose::ConstPtr& msg) {
        stationaryTurtleX = msg->x;
        stationaryTurtleY = msg->y;
        ROS_INFO_STREAM(stationaryTurtleX);
        ROS_INFO_STREAM(stationaryTurtleY);
        ROS_INFO_STREAM("Finished getting stationary turtle info");
        endStationarySubscription = true;
    }

    void movingCallback(const turtlesim::Pose::ConstPtr& msg) {
        movingTurtleX = msg->x;
        movingTurtleY = msg->y;
        ROS_INFO_STREAM(movingTurtleX);
        ROS_INFO_STREAM(movingTurtleY);
        ROS_INFO_STREAM("Finished getting moving turtle info");
        endMovingSubscription = true;
    }

public: 
    DistancePublisher(ros::NodeHandle & newNode) {
        n = newNode;
        endStationarySubscription = false;
        ros::Subscriber stationarySub = n.subscribe("stationary_turtle/pose", 1000, &DistancePublisher::stationaryCallback, this);
        while(!endStationarySubscription) {
            ros::spinOnce();
        }
        endMovingSubscription = false;
        ros::Subscriber movingSub = n.subscribe("moving_turtle/pose", 1000, &DistancePublisher::movingCallback, this);
        while(!endMovingSubscription) {
            ros::spinOnce();
        }
        publish();
    }

    void publish() {
        ros::Publisher customPub = n.advertise<software_training_assignment::Distance>("distanceData", 1000);
        // while(ros::ok) {
            software_training_assignment::Distance msg;
            msg.xDistance = abs(stationaryTurtleX - movingTurtleX);
            msg.yDistance = abs(stationaryTurtleY - movingTurtleY);
            msg.distance = sqrt(pow(msg.xDistance, 2) + pow(msg.yDistance, 2));
            customPub.publish(msg);
            ros::spinOnce();
        // }
    }
};

class MoveAction {
protected: 
    ros::NodeHandle nh_;
    actionlib::SimpleActionServer<software_training_assignment::MoveAction> as_;
    std::string action_name_;
    software_training_assignment::MoveFeedback feedback_;
    software_training_assignment::MoveResult result_;
    bool success_;
    bool end_;
    float goalX_;
    float goalY_;
public:
    MoveAction(std::string name) :
        as_(nh_, name, boost::bind(&MoveAction::executeCB, this, _1), false),
        action_name_(name)
    {   
        as_.start();
    }

    ~MoveAction(void) {}

    void subscriberCB(const turtlesim::Pose::ConstPtr& msg) {
        float currentX = msg -> x;
        float currentY = msg -> y;
        
        float velocityX;
        if ((currentX - goalX_) > 1) {
            velocityX = -1;
        } else if ((currentX - goalX_) < -1) {
            velocityX = 1;
        } else if (std::fabs(currentX - goalX_) >= 0.01) {
            velocityX = std::fabs(currentX - goalX_);
        } else {
            velocityX = 0;
        }

        float velocityY;
        if ((currentY - goalY_) > 1) {
            velocityY = -1;
        } else if ((currentY - goalY_) < -1) {
            velocityY = 1;
        } else if (std::fabs(currentY - goalY_) >= 0.01) {
            velocityY = std::fabs(currentY - goalY_);
        } else {
            velocityY = 0;
        }

        if (velocityX == 0 && velocityY == 0) {
            end_ = false;
        } else {
            float distance = sqrt(pow(std::fabs(currentY - goalY_),2) + pow(std::fabs(currentX - goalX_),2));
            feedback_.distance = distance;
            as_.publishFeedback(feedback_);
            ros::Publisher velocityPub = nh_.advertise<geometry_msgs::Twist>("moving_turtle/cmd_vel", 1000);
            geometry_msgs::Twist msg;
            geometry_msgs::Vector3 linear;
            linear.x = velocityX;
            linear.y = velocityY;
            linear.z = 0;
            msg.linear = linear;
            
            geometry_msgs::Vector3 angular;
            angular.x = 0;
            angular.y = 0;
            angular.z = 0;
            msg.angular = angular;
            velocityPub.publish(msg);
            ros::spinOnce();
        }

    }
    void executeCB(const software_training_assignment::MoveGoalConstPtr &goal) {
        success_ = true;
        end_ = false;

        ROS_INFO_STREAM(goal);
        goalX_ = goal -> absolutePos[0];
        goalY_ = goal -> absolutePos[1];
        
        ros::Subscriber dataSub = nh_.subscribe("moving_turtle/pose", 1000, &MoveAction::subscriberCB, this);
        ros::Time startTime = ros::Time::now();
        while(!end_) {
            if(as_.isPreemptRequested() || !ros::ok()) {
                ROS_INFO("%s: Preempted", action_name_.c_str());
                // set the action state to preempted
                as_.setPreempted();
                success_ = false;
                break;
            } else {
                ros::spinOnce();
            }
        }
        ros::Time endTime = ros::Time::now();
        ros::Duration duration = endTime - startTime;
        if (success_) {
            result_.time = duration;
            as_.setSucceeded(result_);
        }
    }
};
int main(int argc, char **argv) {
    ros::init(argc, argv, "turtleBehaviour");
    ros::NodeHandle n;

    clearTurtles(n);
    spawnTurtles(n);

    MovingTurtleReset server(n);

    DistancePublisher publisher(n);
    
    MoveAction action("waypointcd");
    return 0;
}