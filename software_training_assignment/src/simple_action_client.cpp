//============================================================================
// simple_action_client.cpp
// Bahar Kholdi-Sabeti
// Feb. 15, 2020
// simple client for Move action
// ============================================================================
#include <ros/ros.h>
#include <software_training_assignment/MoveAction.h>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient<software_training_assignment::MoveAction> Client;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "move_client");
	Client client ("move", true);         // don't need ros::spin()
	client.waitForServer();
	software_training_assignment::MoveGoal goal;
	// define goal
    goal.endLocation = {5,5};   // enter your waypoint

	client.sendGoal(goal);
	client.waitForResult(ros::Duration(100.0));
	if (client.getState()==actionlib::SimpleClientGoalState::SUCCEEDED){
		printf("Current State: %s\n", client.getState().toString().c_str());
	}
	printf("Current State: %s\n", client.getState().toString().c_str());
	return 0;
}
