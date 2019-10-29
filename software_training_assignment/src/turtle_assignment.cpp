#include <ros/ros.h>
#include "turtlesim/Spawn.h"
#include "turtlesim/Kill.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/Pose.h"
#include "software_training_assignment/Reset.h"
#include "software_training_assignment/Distance.h"
//#include "waypoint_action.h"

// Globals
software_training_assignment::Distance dist_msg;

bool reset(software_training_assignment::Reset::Request&, software_training_assignment::Reset::Response &res){
  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportAbsolute>("moving_turtle/teleport_absolute");
  turtlesim::TeleportAbsolute tel_srv;
  tel_srv.request.x = 25.0;
  tel_srv.request.y = 5.0;
  tel_srv.request.theta = 0.0;

  if(client.call(tel_srv)){
    ROS_INFO("moving_turtle moved back to x: 25.0, y: 10.0 theta: 0.0");
    res.success = true;
    return true;
  }
  ROS_INFO("Failed to reset moving_turtle");
  res.success = false;
  return false;
}

void poseCallback(const turtlesim::Pose::ConstPtr& msg){
  dist_msg.x_dist = msg->x - 5.0; // Calculate x distance from stationary_turtle
  dist_msg.y_dist = msg->y - 5.0; // Calculate y distance from stationary_turtle
  ROS_INFO("x: %f  y: %f", dist_msg.x_dist, dist_msg.y_dist);
}

int main(int argc, char** argv){
    ros::init(argc, argv, "turtle_assignment");
    ros::NodeHandle n;

    ros::ServiceClient client = n.serviceClient<turtlesim::Kill>("kill");
    turtlesim::Kill kill_srv;
    kill_srv.request.name = "turtle1";
    if(client.call(kill_srv)){
      ROS_INFO("Cleared turtle1");
    }
    else{
      ROS_ERROR("Failed to call service turtlesim/Kill");
      return 1;
    }

    client = n.serviceClient<turtlesim::Spawn>("spawn");
    turtlesim::Spawn spawn_srv;

    for(int i = 0; i < 2; i++){
      if(i == 0){
        spawn_srv.request.x = 5.0;
        spawn_srv.request.y = 5.0;
        spawn_srv.request.name = "stationary_turtle";
      }
      else{
        spawn_srv.request.x = 25.0;
        spawn_srv.request.y = 10.0;
        spawn_srv.request.name = "moving_turtle";
      }
      spawn_srv.request.theta = 0.0;
      if (client.call(spawn_srv)){
        ROS_INFO("Name of new turtle: %s", spawn_srv.response.name.c_str());
      }
      else{
        ROS_ERROR("Failed to call service turtlesim/Spawn");
        return 1;
      }
    }

    ros::ServiceServer service = n.advertiseService("reset_moving_turtle", reset);
    ros::Subscriber sub = n.subscribe("moving_turtle/pose", 1, poseCallback);
    ros::Publisher dist_pub = n.advertise<software_training_assignment::Distance>("dist_btwn_turtles", 1);
    ros::Rate loop_rate(30);

    while (ros::ok()){
      dist_pub.publish(dist_msg);
      ros::spinOnce();
      loop_rate.sleep();
    }

    //ros::spin();

    return 0;
}
