#include "ros/ros.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/Pose.h"
#include "software_training_assignment/resetTurtle.h"
#include "software_training_assignment/distance.h"
#include "software_training_assignment/SeekTurtleAction.h"
#include "geometry_msgs/Twist.h"
#include "actionlib/server/simple_action_server.h"
#include <cmath>

//This publisher is to be initalized with gemoetery_msgs/Twist !!
ros::Publisher SeekTurtlePub; //Global since Main needs access to this

constexpr double RESET_X = 25.0;
constexpr double RESET_Y = 10.0;


struct Waypoint
{
    float x = 0;
    float y = 0;
    float distance = 0;
    float angle = 0;
};

static Waypoint movingTurtleWP; //static to keep it file-scope

float distance(float x, float y)
{
    return pow(pow(x,2) + pow(y,2), 1/float(2));
}

float arctanAbsolute(float x, float y)
{
    float DEGREES_IN_QUADRANT = 90;
    float arctangent = atan(x/y)*M_PI;
    if(y > 0 && x < 0)
    {
        arctangent = -arctangent+DEGREES_IN_QUADRANT*1; //Quadrant 2
    }
    else if(y < 0 && x < 0)
    {
       arctangent = arctangent+DEGREES_IN_QUADRANT*2; //Quadrant 3
    }
    else if(y < 0 && x > 0)
    {
        arctangent = -arctangent+DEGREES_IN_QUADRANT*3; //Quadrant 4
    }

    return arctangent;
}

void calculateDistance(Waypoint targetWaypoint, Waypoint currentWaypoint, Waypoint &resultWaypoint)
{
    resultWaypoint.x = targetWaypoint.x - currentWaypoint.x;
    resultWaypoint.y = targetWaypoint.y - currentWaypoint.y;
    resultWaypoint.distance = distance(resultWaypoint.x, resultWaypoint.y);
    resultWaypoint.angle = arctanAbsolute(resultWaypoint.x, resultWaypoint.y);
}

void updateDistanceMsg(ros::NodeHandle &n, Waypoint DistanceStruct)
{
    ros::Publisher publisher = n.advertise<software_training_assignment::distance>("Distances",1000);
    software_training_assignment::distance msg;
    msg.x = DistanceStruct.x;
    msg.y = DistanceStruct.y;
    msg.dist = DistanceStruct.distance;
    publisher.publish(msg);
}


/******CLEAR & SPAWN TURTLE FUNCTIONS******/
bool clearTurtle(std::string name) //clears the existing turtle
{
    turtlesim::Kill killService; //Service to kill the turtle
    killService.request.name = name;
    return ros::service::call("kill", killService); //Makes sure the turtle dies before exiting the loop

}


bool spawnTurtle(std::string name, double x, double y, double angle)
{
    turtlesim::Spawn spawnService;
    spawnService.request.name = name;
    spawnService.request.x = x;
    spawnService.request.y = y;
    spawnService.request.theta = angle;
    return ros::service::call("spawn", spawnService);
}

/******CLEAR & SPAWN TURTLE FUNCTIONS END******/

bool resetTurtlePosition(software_training_assignment::resetTurtle::Request &request, software_training_assignment::resetTurtle::Response &response)
{
    
    std::string name = request.name;  //QUESTION: Why do I not need to dereference this??
    return(clearTurtle(name) && spawnTurtle(name, RESET_X, RESET_Y, 0));
}

/***TUTORIAL FOR REFERENCE: Actionlib implement an actionserver 7.1******/
typedef actionlib::SimpleActionServer<software_training_assignment::SeekTurtleAction> Server;
void move_turtle_callBack(const software_training_assignment::SeekTurtleGoalConstPtr &goal, Server *actionServer)
{
    software_training_assignment::SeekTurtleFeedback feedback;
    software_training_assignment::SeekTurtleResult result;

    geometry_msgs::Twist msg;
    
    float timeInterval = 1; //arbitary time interval?
    ros::Rate rate(1/timeInterval);
    float totalTime = 10;
    float deltaX = movingTurtleWP.x - goal->x;
    float deltaY= movingTurtleWP.y - goal->y;
    float deltaDistance = distance(deltaX, deltaY);

    bool successful = true;
    
    for(int time = 0; time < totalTime; time += timeInterval)
    {
        if(actionServer->isPreemptRequested() || !ros::ok)
        {
            actionServer->setPreempted();
            successful = false;
        }

        msg.angular.z = arctanAbsolute(deltaX, deltaY);
        msg.linear.x = deltaDistance/totalTime; //linear speed
        SeekTurtlePub.publish(msg);
        feedback.distance = distance(deltaX, deltaY);

        actionServer->publishFeedback(feedback);
        
        rate.sleep(); //sleep for time interval
    }

    result.time = totalTime;
    if(successful)
    {
        actionServer->setSucceeded(result);
    }

}

void updateMovingTurtleFromCallback(const turtlesim::Pose::ConstPtr &msg)
{
    movingTurtleWP.x = msg->x;
    movingTurtleWP.y = msg->y;
    movingTurtleWP.angle = msg->theta;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtle_setter");
    ros::NodeHandle n;
    while(!clearTurtle("turtle1"));
    while(!spawnTurtle("stationary_turtle", 5, 5, 0));
    while(!spawnTurtle("moving_turtle", 25, 10, 0));

    Waypoint stationaryTurtleWP = {5,5,0,0};


    movingTurtleWP = {25,10,0,0};
    ros::Subscriber movingTurtleWPSubscriber = n.subscribe("/moving_turtle/pose", 1000, updateMovingTurtleFromCallback);

    /****ActionServer****/
    //this syntax I got off a ROS tutorial.
    Server as(n, "MoveTurtleToWaypoint", boost::bind(&move_turtle_callBack, _1, &as), false);
    as.start();
    
    SeekTurtlePub = n.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel", 1000); //Publish to the commanded velocity var

    ros::ServiceServer service = n.advertiseService("reset_turtle", resetTurtlePosition);
    while(ros::ok())
    {
        Waypoint distanceResultWP;
        calculateDistance(stationaryTurtleWP, movingTurtleWP, distanceResultWP);
        updateDistanceMsg(n,distanceResultWP);


        ros::spinOnce();
    }
    

}
