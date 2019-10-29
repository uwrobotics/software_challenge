#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include "software_training_assignment/WaypointAction.h"

#ifndef WAYPOINT_ACTION_H
#define WAYPOINT_ACTION_H

class WaypointAction
{
protected:

  ros::NodeHandle nh_;
  ros::Publisher twist_pub;
  actionlib::SimpleActionServer<software_training_assignment::WaypointAction> server; // NodeHandle instance must be created before this line. Otherwise strange error occurs.
  std::string action_name_;
  // create messages that are used to published feedback/result
  actionlib_tutorials::WaypointFeedback feedback_;
  actionlib_tutorials::WaypointResult result_;


public:

  WaypointAction(std::string name) :
    server(nh_, name, boost::bind(&WaypointAction::executeCB, this, _1), false), action_name_(name);

  ~WaypointAction(void);

  void executeCB(const actionlib_tutorials::WaypointGoalConstPtr &goal);
};

#endif
