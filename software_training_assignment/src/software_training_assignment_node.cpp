/* 
Software Training Assignment
Author: Sepehr Ghavam
Date: June 24, 2020
Email: sepehr.ghavam@protonmail.com
*/


#include <chrono>
#include <thread>
#include "ros/ros.h"
#include "ros/master.h"
#include <turtlesim/TeleportAbsolute.h>
#include <actionlib/server/simple_action_server.h>
#include "std_srvs/Empty.h"
#include "geometry_msgs/Twist.h"
#include <turtlesim/Spawn.h>
#include <turtlesim/Kill.h>
#include <turtlesim/Pose.h>
#include <actionlib/server/simple_action_server.h>
#include "software_training_assignment/ResetMovingTurtle.h"
#include "software_training_assignment/TurtleDist.h"
#include "software_training_assignment/MoveTurtleAction.h"

using namespace std;

typedef actionlib::SimpleActionServer<software_training_assignment::MoveTurtleAction> Server;

// ------------------------------------------------------------------------------------------

class Turtle{
  public:
    // Really these should be private member variables, exposed for reading by a get_pose() function...
    int x;
    int y;
    
    void update_position(const turtlesim::Pose msg){
      x = msg.x;
      y = msg.y;
    }
};


// ------------------------------------------------------------------------------------------
// Move Turtle Action

class MoveTurtleAction{
  protected:
  
    Turtle mov_turtle;
    ros::NodeHandle nh;

    actionlib::SimpleActionServer<software_training_assignment::MoveTurtleAction> as_;
    // actionlib:: 
    std::string action_name_;

    // create messages that are used to published feedback/result
    software_training_assignment::MoveTurtleFeedback feedback;
    software_training_assignment::MoveTurtleResult result;

  public:
    MoveTurtleAction(string name) : 
      as_(nh, name, boost::bind(&MoveTurtleAction::move_to_waypoint, this, _1), false), action_name_(name)
    {
      as_.start();
    }

    ~MoveTurtleAction(void){}

    void move_to_waypoint(const software_training_assignment::MoveTurtleGoalConstPtr &goal)
    {

      ros::Subscriber mov_turtle_sub = nh.subscribe("moving_turtle/pose", 1, &Turtle::update_position, &mov_turtle);

      ROS_INFO("Target set: (%i,%i)", (int)goal->x_target, (int)goal->y_target);

      // // helper variables
      ros::Rate r(1);
      bool success = false;

      software_training_assignment::MoveTurtleFeedback feedback;
      software_training_assignment::MoveTurtleResult result;

      double distance_to_target;

      auto time_start = std::chrono::high_resolution_clock::now();

      // publish cmd_vel for moving_turtle
      ros::Publisher publish_turtle_move = nh.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel", 1);
      geometry_msgs::Twist move_msg;
      
      move_msg.linear.x = mov_turtle.x - goal->x_target;
      move_msg.linear.y = mov_turtle.y - goal->y_target;
      move_msg.linear.z = 0.0;
      move_msg.angular.x = 0.0;
      move_msg.angular.y = 0.0;
      move_msg.angular.z = 0.0;

      publish_turtle_move.publish(move_msg);

      // start executing the action
      while(!success) {
        distance_to_target = sqrt(((double)goal->x_target * (double)goal->x_target + (double)goal->y_target * (double)goal->y_target));
        
        feedback.distance_to_target = distance_to_target;
        success = ((int)mov_turtle.x - (int)goal->x_target == 0 && ((int)mov_turtle.y - (int)goal->y_target == 0 ));
      }
      if(success){
        ROS_INFO("Target hit!");
        auto time_end = std::chrono::high_resolution_clock::now();

        result.time_to_target = (double)std::chrono::duration_cast<std::chrono::seconds>(time_end - time_start).count(); 

        as_.setSucceeded(result);
      }
    }
};

// ------------------------------------------------------------------------------------------

bool kill_turtle(string name){

  ros::NodeHandle node_handle;
  ros::ServiceClient killClient = node_handle.serviceClient<turtlesim::Kill>("kill");

  turtlesim::Kill::Request req;
  turtlesim::Kill::Response resp;

  req.name = name;

  bool success = killClient.call(req, resp);

  if(success) {
    ROS_INFO_STREAM( "Killed turtle " << name);
    return true;
  } else {
    ROS_ERROR_STREAM( "Failed to spawn.");
    return false;
  }
}


bool spawn_turtle(string name, int x, int y, int theta){

  ros::NodeHandle node_handle;
  ros::ServiceClient spawnClient = node_handle.serviceClient<turtlesim::Spawn>("spawn");

  turtlesim::Spawn::Request req;
  turtlesim::Spawn::Response resp;
  
  req.x = x;
  req.y = y;
  req.theta= theta;
  req.name= name ;
  
  bool success = spawnClient.call(req, resp);
  
  if(success) {
    ROS_INFO_STREAM( "Spawned a turtle named " << resp.name);
    return true;
  } else {
    ROS_ERROR_STREAM( "Failed to spawn.");
    return false;
  }
}


bool reset_moving_turtle(software_training_assignment::ResetMovingTurtle::Request  &req, software_training_assignment::ResetMovingTurtle::Response &res){

  ros::NodeHandle node_handle;
  ros::ServiceClient teleClient = node_handle.serviceClient<turtlesim::TeleportAbsolute>("moving_turtle/teleport_absolute");

  turtlesim::TeleportAbsolute::Request tele_req;
  turtlesim::TeleportAbsolute::Response tele_resp;
  
  // Yes I know this is bad.
  tele_req.x = 25;
  tele_req.y = 10;
  tele_req.theta = 0;

  bool success = teleClient.call(tele_req, tele_resp);
  
  if(success) {
    ROS_INFO_STREAM("Reset moving_turtle to starting position (25,10)");
    res.success = true;
    return true;
  } else {
    ROS_ERROR_STREAM("Failed to reset moving_turtle to starting position.");
    res.success = false;
    return false;
  }  
}


software_training_assignment::TurtleDist get_turtle_distances(Turtle mov_turtle, Turtle stat_turtle){
  
  software_training_assignment::TurtleDist msg;

  msg.x = (int)(mov_turtle.x - stat_turtle.x);
  msg.y = (int)(mov_turtle.y - stat_turtle.y);
  msg.mag = sqrt(((double)msg.x * (double)msg.x + (double)msg.y * (double)msg.y));

  return msg;
}


int main (int argc, char* argv[]) {
  // 
  
  ros::init(argc, argv, "spawn_turtle");
  ros::NodeHandle nh;

  // Check if turtlesim node is alive, if not, do nothing.
  ros::V_string v;
  ros::master::getNodes(v);

  while(!(std::find(v.begin(), v.end(), "/turtlesim") != v.end()))
  {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    ROS_INFO_STREAM( "Couldn't find /turtlesim node...");
  }

  // Clear all existing turtles
  kill_turtle("turtle1");

  // Probably unnecessary
  std_srvs::Empty clear;
  ros::service::call("clear", clear);

  // Spawn turtle named "stationary_turtle" @ (5,5)
  spawn_turtle("stationary_turtle", 5, 5, 0);
  
  // Spawn 2nd turtle named "moving_turtle" @ (25,10)
  spawn_turtle("moving_turtle", 25, 10, 0);

  // Create service that resets "moving_turtle" to its starting position. Service should return success/failure
  ros::ServiceServer service = nh.advertiseService("reset_moving_turtle", reset_moving_turtle);
  ros::Rate loop_rate(10);  

  // Create publisher that publishes a custom message. Custom message should have 3 int fields: (a,b,c)
  // a - x-distance of moving_turtle to stationary_turtle
  // b - y-distance of moving_turtle to stationary_turtle
  // c - magnitude of vector (a,b) between 
  ros::Publisher turtle_pub = nh.advertise<software_training_assignment::TurtleDist>("turtle_dist", 1);

  MoveTurtleAction move_turtle_act("MoveTurtle");

  Turtle mov_turtle;
  Turtle stat_turtle;

  ros::Subscriber mov_turtle_sub = nh.subscribe("moving_turtle/pose", 1, &Turtle::update_position, &mov_turtle);
  ros::Subscriber stat_turtle_sub = nh.subscribe("stationary_turtle/pose", 1, &Turtle::update_position, &stat_turtle);
  // Create action that moves "moving_turtle"
  
  while(ros::ok()){
    software_training_assignment::TurtleDist msg = get_turtle_distances(mov_turtle, stat_turtle);

    turtle_pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
}