/*
Action server for moving the turtle 
*/

#include <ros/ros.h> 
#include <actionlib/server/simple_action_server.h>
//Subscribe to the geometry_msgs/Twist topic 
#include <geometry_msgs/Twist.h>

bool moveTurtle(int x, int y){
    

    return success; 
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "moveTurtle"); 
    ros::NodeHandle nh; 

    //Create the action
    actionlib::SimpleActionServer<actionlib> as;
    std::string action_name  = "moveTurtle"; 

    //Create messages to be published to feedback and result
    actionlib::Feedback feedback; 
    actionlib::Result result; 

    //Get the pointer to the action goal 
    const actionlib::GoalConstPtr &goal; 
    //Set the end destination for the action
    int x = goal->x; 
    int y = goal->y; 

    //Subscribe to the turtleX/cmd_vel topic
    ros::Subscriber sub = nh.subscribe("cmd_vel", 10, moveTurtle);
    //Access the message type parameters
    geometry_msgs::Twist::vector3::x = x; 

    //Create the action server 
    as(nh, action_name); 
    as.start(); 

    ros::spin(); 

    return 0; 
}