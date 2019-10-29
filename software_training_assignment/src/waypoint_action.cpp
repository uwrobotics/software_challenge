#include "waypoint_action.h"

WaypointAction::WaypointAction(std::string name) :
  server(nh_, name, boost::bind(&WaypointAction::executeCB, this, _1), false), action_name_(name)
{
  server.start();
}

WaypointAction::~WaypointAction(void)
{
}

void WaypointAction::executeCB(const actionlib_tutorials::WaypointGoalConstPtr &goal)
{
  // helper variables
  ros::Rate r(1);
  bool success = true;

  // push_back the seeds for the Waypoint sequence
  feedback_.sequence.clear();
  feedback_.sequence.push_back(0);
  feedback_.sequence.push_back(1);

  // publish info to the console for the user
  ROS_INFO("%s: Executing, creating Waypoint sequence of order %i with seeds %i, %i", action_name_.c_str(), goal->order, feedback_.sequence[0], feedback_.sequence[1]);

  // start executing the action
  for(int i=1; i<=goal->order; i++)
  {
    // check that preempt has not been requested by the client
    if (server.isPreemptRequested() || !ros::ok())
    {
      ROS_INFO("%s: Preempted", action_name_.c_str());
      // set the action state to preempted
      server.setPreempted();
      success = false;
      break;
    }
    feedback_.sequence.push_back(feedback_.sequence[i] + feedback_.sequence[i-1]);
    // publish the feedback
    server.publishFeedback(feedback_);
    // this sleep is not necessary, the sequence is computed at 1 Hz for demonstration purposes
    r.sleep();
  }

  if(success)
  {
    result_.sequence = feedback_.sequence;
    ROS_INFO("%s: Succeeded", action_name_.c_str());
    // set the action state to succeeded
    server.setSucceeded(result_);
  }
}
