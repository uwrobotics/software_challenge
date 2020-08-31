#include "ros/ros.h"

#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>

#include "software_training_assignment/MoveTurtleAction.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "move_turtle_action_tester");

    ros::NodeHandle n;

    float x, y;
    n.getParam("/move_turtle_action_tester/x", x);
    n.getParam("/move_turtle_action_tester/y", y);

    actionlib::SimpleActionClient<software_training_assignment::MoveTurtleAction> actionClient("move_turtle_action_server", true);
    
    ROS_INFO("Waiting for action server to start.");
    actionClient.waitForServer(); // will wait for infinite time

    // send a goal to the action
    ROS_INFO("Action server started, sending goal.");
    software_training_assignment::MoveTurtleGoal goal;
    goal.x = x;
    goal.y = y;
    actionClient.sendGoal(goal);

    // wait for the action to return
    bool finished_before_timeout = actionClient.waitForResult(ros::Duration(30.0));

    if (finished_before_timeout) {
        actionlib::SimpleClientGoalState state = actionClient.getState();
        ROS_INFO("Action finished: %s", state.toString().c_str());
    } else {
        ROS_INFO("Action did not finish before the time out.");
    }

    return 0;
}
