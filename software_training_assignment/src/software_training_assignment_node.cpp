//============================================================================
// software_training_assignment_node.cpp
// Bahar Kholdi-Sabeti
// Feb. 15, 2020
// software training assignment for UW Robotics Team

// Task 4:
// a) clears any turtles - automatic
// b) spawns a turtle named stationary_turtle - automatic
// c) spawns moving_turtle - automatic
// d) creates a service that resets the moving_turtle - run service called my_reset:
//				in terminal: rosservice call my_reset
// e) creates publisher - echo coord message
//  			in terminal: rostopic echo coord
// f) creates action that moves moving_turtle to waypoint- run using client node
//	called simple_action_client
//				in terminal: rosrun software_training_assignment simple_action_client
// 	You can also echo feedback and result by echoing Move.action
//				in terminal: rostopic echo /move/feedback
//							 rostopic echo /move/result
//
// can launch this node with rosrun software_training_assignment software_training_assignment_node
// or launch this AND turtlesim with
// roslaunch software_training_assignment turtlesim.launch
//============================================================================

#include "ros/ros.h"
#include "turtlesim/Color.h"
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "std_srvs/Empty.h"
#include "std_msgs/String.h"
#include "turtlesim/Pose.h"
#include "math.h"
#include "software_training_assignment/Disp.h"
#include <actionlib/server/simple_action_server.h>
#include <software_training_assignment/MoveAction.h>
#include <geometry_msgs/Twist.h>

float xTurtle1 = -1;
float yTurtle1 = -1;
float thetaTurtle1 = -1;
float xTurtle2 = -1;
float yTurtle2 = -1;
float turtleTime = -1;   // initialize turtleTime as -1 so that if it's -1 we know that it hasn't been set
typedef actionlib::SimpleActionServer<software_training_assignment::MoveAction> Server;

// updates moving_turtle's pose
void poseCallback(const turtlesim::PoseConstPtr& msg)
{
	xTurtle1 = msg->x;
	yTurtle1 = msg->y;
	thetaTurtle1 = msg->theta;
}

// updates stationary_turtle's pose
void poseCallback2(const turtlesim::PoseConstPtr& msg){
	xTurtle2 = msg->x;
	yTurtle2 = msg->y;
}

// resets turtlesim screen
void reset(){
	ros::NodeHandle nh;
	// Wait until the reset service is available
	ros::service::waitForService("reset");
	ros::ServiceClient resetClient = nh.serviceClient<std_srvs::Empty>("/reset");
	resetClient.waitForExistence();
	std_srvs::Empty srv;
	if (!(resetClient.call(srv))){             // calls service, if statement for debugging
		ROS_ERROR("Error: reset didn't work");
	}
}

// kills turtle1
bool kill(std::string name)
{
	ros::NodeHandle nh;
	// Wait until the kill service is available
	ros::service::waitForService("kill");
	ros::ServiceClient killClient = nh.serviceClient<turtlesim::Kill>("/kill");
	turtlesim::Kill srv;
	srv.request.name = name;
	if (killClient.call(srv)){              // calls service
		return true;
	}
	else{
		ROS_ERROR("Error: killing didn't work");
		return false;
	}
}

// spawns new turtle
bool spawn(int x, int y, int theta, std::string name)
{
	ros::NodeHandle nh;
	// Wait until the spawn service is available
	ros::service::waitForService("spawn");
	ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("/spawn");
	turtlesim::Spawn srv;
	srv.request.x = x;
	srv.request.y = y;
	srv.request.theta = theta;
	srv.request.name = name;
	if (spawnClient.call(srv)){              // calls service
		return true;
	}
	else{
		ROS_ERROR("Error: spawn didn't work");
		return false;
	}
}

// kills turtle1 and spawns moving turtle
bool myReset(std_srvs::Empty::Request &req, std_srvs::Empty::Response &resp)
{
	ROS_INFO_STREAM("my_reset srv called");
	if (kill("moving_turtle")){
		return spawn(25, 10, 0, "moving_turtle");
	}
}

// resets moving turtle for part 4d
// returns whether it was successful or not
void reset_moving(){
	ros::NodeHandle nh;
	ros::ServiceClient my_resetClient = nh.serviceClient<turtlesim::Kill>("/my_reset");
	turtlesim::Kill srv;
	if (!(my_resetClient.call(srv))){              // calls service, if statement for debugging
		ROS_ERROR("Error: my_reset didn't work");
	}
}

// find angle to steer to depending on which quadrant
// the goal is in
// could possibly create a bug for angles close to the
// edges of quadrants
double findAngle(double xGoal, double yGoal){
	if (yGoal<yTurtle1){
		if (xGoal<xTurtle1){
			return -3.14 + atan((yGoal - yTurtle1)/ (xGoal - xTurtle1));
		}
		else{
			return atan((yGoal - yTurtle1)/ (xGoal - xTurtle1));
		}
	}
	else{
		if (xGoal<xTurtle1){
			return 3.14 + atan((yGoal - yTurtle1)/ (xGoal - xTurtle1));
		}
		else{
			return atan((yGoal - yTurtle1)/ (xGoal - xTurtle1));
		}
	}
}

// moves turtle to waypoint using action Move.action
// VERY INCONSISTENT
void execute(const software_training_assignment::MoveGoalConstPtr& goal, Server* as)
{
	ros::NodeHandle nh;
	double xGoal = goal->endLocation[0];
	double yGoal = goal->endLocation[1];
	double dist = sqrt(pow((xGoal-xTurtle1), 2)+pow((yGoal-yTurtle1), 2));
	double steering_angle = findAngle(xGoal, yGoal);

	if (turtleTime == -1){   // initialize time
		turtleTime = ros::Time::now().toSec();
	}
	software_training_assignment::MoveFeedback feedback;
	software_training_assignment::MoveResult result;

	// a large angle tolerance allows the turtle to have enough time to 
	// decellerate to 0 after it's done turning
	while (abs(((double)thetaTurtle1)-steering_angle)>0.05){     // where 0.1 is angle tolerance	
		feedback.distance = dist;
		as->publishFeedback(feedback);
		// move turtle
		ros::Publisher velocity_publisher = nh.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel", 10);
		geometry_msgs::Twist vel_msg;
		vel_msg.linear.x = 0;
		vel_msg.linear.y = 0;
		vel_msg.linear.z = 0;
		vel_msg.angular.x = 0;
		vel_msg.angular.y = 0;
		vel_msg.angular.z = 0.1; // make it turn hella slow so 
		// we don't have to worry too much about decellerating 
		velocity_publisher.publish(vel_msg);
		ROS_INFO("Steering angle: %f, turtle angle: %f", steering_angle, ((double)thetaTurtle1));
		ros::spinOnce();
	}
	while (dist>1){     // where 1 is distance tolerance		
		steering_angle = -100;
		// update moving_turtle location
		ros::Subscriber mt_pose = nh.subscribe<turtlesim::Pose>     // updates moving turtle pose
		("/moving_turtle/pose",10, &poseCallback);
		// update distance to goal
		dist = sqrt(pow((xGoal-xTurtle1), 2)+pow((yGoal-yTurtle1), 2));
		// updates feedback as distance to goal
		feedback.distance = dist;
		as->publishFeedback(feedback);
		// move turtle
		ros::Publisher velocity_publisher = nh.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel", 10);
		geometry_msgs::Twist vel_msg;
		vel_msg.linear.x = 2;
		vel_msg.linear.y = 0;
		vel_msg.linear.z = 0;
		vel_msg.angular.x = 0;
		vel_msg.angular.y = 0;
		vel_msg.angular.z = 0;     // decellerates to 0
		velocity_publisher.publish(vel_msg);
		ROS_INFO("I am moving, turtle angle: %f", ((double)thetaTurtle1));
		ros::spinOnce();
	}
	// reached goal
	ROS_INFO("I am at my goal :)");
	// returns result as time it took to reach goal
	result.time = ros::Time::now().toSec() - turtleTime;
	as->setSucceeded(result);
	turtleTime = -1;

	ros::Publisher velocity_publisher = nh.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel", 10);
	geometry_msgs::Twist vel_msg;
	vel_msg.linear.x = 0;
	vel_msg.linear.y = 0;
	vel_msg.linear.z = 0;
	vel_msg.angular.x = 0;
	vel_msg.angular.y = 0;
	vel_msg.angular.z = 0;
	velocity_publisher.publish(vel_msg);
	ros::spinOnce();
}

// updates coord custom msg
void updateDisp(){
	ros::NodeHandle nh;
	ros::Rate loop_rate(10);
	// publisher for distances between 2 turtles
	ros::Publisher coord_pub = nh.advertise<software_training_assignment::Disp>("coord", 1000);
	
	// num of sent msgs
	int count = 0;
	while (ros::ok())
	{
		// updates Disp msg
		software_training_assignment::Disp msg;

		double xDist = abs(xTurtle2 - xTurtle1);
		double yDist = abs(yTurtle2 - yTurtle1);
		double dist = sqrt(pow(xDist, 2)+pow(yDist, 2));

		msg.xDisp = xDist;
		msg.yDisp = yDist;
		msg.disp = dist;

		coord_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++count;
	}
}

// main function
int main(int argc, char **argv) {
	ros::init(argc, argv, "software_training_assignment_node");
	ros::NodeHandle nh;

	reset();     // resets everything to start config
	kill("turtle1");      // kills turtle1 because we don't like him
	// but also because he's not on the list of instructions
	spawn(5, 5, 0, "stationary_turtle"); // makes "stationary_turtle" @ (5,5)
	spawn(25, 10, 0, "moving_turtle"); // makes "moving_turtle" @ (25,10)

	// Register service
	ros::ServiceServer server = nh.advertiseService("my_reset", &myReset);

	ros::Subscriber mt_pose = nh.subscribe<turtlesim::Pose>     // subscriber for moving turtle
	("/moving_turtle/pose",10, &poseCallback);
	ros::Subscriber st_pose = nh.subscribe<turtlesim::Pose> // subscriber for stationary turtle
	("/stationary_turtle/pose",10, &poseCallback2);

	// set up action
	///////////////////////////////////////////////////////////////////////////////////////
	actionlib::SimpleActionServer<software_training_assignment::MoveAction> as(nh, "move", boost::bind(&execute, _1, &as), false);
	as.start();
	///////////////////////////////////////////////////////////////////////////////////////
	// done setting up action

	// updates coord custom msg
	updateDisp();

	return 0;
}
