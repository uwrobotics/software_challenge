#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <software_training_assignment/GotoAction.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "test_node");

    if (argc != 3)
    {
        ROS_INFO("rosrun software_training_assignment testing x y");
        return 0;
    }

    ros::NodeHandle n;

    actionlib::SimpleActionClient<software_training_assignment::GotoAction> ac ("turtlesim1/goto", true);
    
    ROS_INFO("Waiting for action server to start.");

    ac.waitForServer();

    ROS_INFO("Action server started, sending goal.");
    

    software_training_assignment::GotoGoal goal;

    goal.x = atoll(argv[1]);
    goal.y = atoll(argv[2]);

    ac.sendGoal(goal);

    bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

    if (finished_before_timeout)
    {
        actionlib::SimpleClientGoalState state = ac.getState();
        ROS_INFO("Action finished: %s",state.toString().c_str());
    }
    else
        ROS_INFO("Action did not finish before the time out.");


    ros::ServiceClient client = n.serviceClient<std_srvs::Empty>("turtlesim1/reset_pos");

    ros::service::waitForService("turtlesim1/reset_pos");

    std_srvs::Empty srv;

    if(client.call(srv))
    {
        ROS_INFO("Test resetted");
    }
    else
    {
        ROS_ERROR("Failed to call service reset_pos");
        return 1;
    }

    return 0;
}