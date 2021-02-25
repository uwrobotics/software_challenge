#include "ros/ros.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "software_training_assignment/tostart.h"
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "software_training_assignment/toWaypointAction.h"

class STA {
  private:
    ros::NodeHandle n;
  public:
    void euthanize(std::string name) {
        ros::service::waitForService("kill");
        ros::ServiceClient client = n.serviceClient<turtlesim::Kill>("/kill");
        turtlesim::Kill srv;
        srv.request.name = name;
        if (client.call(srv))
        {
          ROS_INFO("Kill confirmed");
        }
        else
        {
          ROS_ERROR("Kill failed");
        }
    }

    void birth(std::string name, float x, float y, float theta) {
        ros::service::waitForService("spawn");
        ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("/spawn");
        turtlesim::Spawn srv;
        srv.request.x = x;
        srv.request.y = y;
        srv.request.theta = theta;
        srv.request.name = name;
        if (client.call(srv))
        {
          ROS_INFO("Birth confirmed");
        }
        else
        {
          ROS_ERROR("Birth failed");
        }
    }

    void toStart(std::string name) {
        ros::service::waitForService("tostart");
        ros::ServiceClient client = n.serviceClient<software_training_assignment::tostart>("/tostart");
        software_training_assignment::tostart srv;
        srv.request.name = name;
        if (client.call(srv))
        {
          ROS_INFO("toStart success");
        }
        else
        {
          ROS_ERROR("toStart failed");
        }
    }
};

software_training_assignment::toWaypointGoal makeGoal(float x, float y)
{
  software_training_assignment::toWaypointGoal goal;
  goal.x = x;
  goal.y = y;
  return goal;
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "sw_training"); 
  STA sta;
  sta.euthanize("turtle1");
  sta.birth("stationary_turtle", 5.0, 5.0, 0.0);
  sta.birth("moving_turtle", 25.0, 10.0, 0.0);

  ros::Duration(1).sleep();
  sta.toStart("moving_turtle");

  ros::Duration(1).sleep();

  actionlib::SimpleActionClient<software_training_assignment::toWaypointAction> ac("m", true);
  ac.waitForServer();
  
  ac.sendGoal(makeGoal(0.0,0.1));
  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
    ROS_INFO("Action did not finish before the time out.");
  
  return 0;
}