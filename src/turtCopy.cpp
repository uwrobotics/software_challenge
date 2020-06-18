/**
* Software Training Assignment Turtle Node
*
* Created by: Kiran Surendran
*
*/

//Header Files
#include <ros/ros.h>
#include <std_msgs/Int64.h>
#include <std_srvs/Empty.h>
#include <turtlesim/Pose.h>
#include <turtlesim/Kill.h>
#include <turtlesim/Spawn.h>
#include <turtlesim/TeleportAbsolute.h>
#include <geometry_msgs/Twist.h>
#include <string>
#include <cmath>
#include <software_training_assignment/ResetTurtle.h>
#include <software_training_assignment/Dist.h>
#include <software_training_assignment/TurtleSeekerAction.h>
#include <actionlib/server/simple_action_server.h>

typedef actionlib::SimpleActionServer<software_training_assignment::TurtleSeekerAction> Server;
#define PI 3.14159265
//Function Declarations
int killTurtle(std::string name);
int spawnTurtle(std::string name, float x, float y, float theta);
int teleportTurtle(std::string name, float x, float y, float theta);
bool resetMovingTurtle(software_training_assignment::ResetTurtle::Request &req, software_training_assignment::ResetTurtle::Response &res);

//Global Vars 
//SIDENOTE: I would do it the class way, but it just seems overkill for this usecase
float movX=25;
float movY=10;
ros::Subscriber mTurt;
ros::Publisher turtle_pub; 
void turtleCallback(const turtlesim::Pose::ConstPtr &msg){
	movX = msg->x;
	movY = msg->y;
}

float findVectorMagnitude(float x, float y){
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

float findAngularVelocity(float x, float y, float t){
	float theta = atan(x/y);
	float quad = PI/2;
	
	if(x==0 && y==0){	//At position
		return 0;
	}
	
	if(x==0){		//Directly above or below
		if(y>0){
		theta = -quad;
		}else{
		theta = quad;
		}
	}else 
	if(y==0){		//Directly left or right
		if(x>0){
		theta = 2 * quad;
		}else{
		theta = 0;
		}
	}else
	

	if(x>0){
		if(y>0){
		//Quadrant 1: +x, +y
		theta = -quad - theta;
		}else{
		//Quadrant 4: +x, -y
		theta = quad + theta;
		}
	}
	else{
		if(y>0){
		//Quadrant 2: -x, +y
		theta = -quad + theta;
		}else{
		//Quadrant 3: -x, -y
		theta = quad - theta;
		}
	}
	return (theta/t);
}



void execute(const software_training_assignment::TurtleSeekerGoalConstPtr& goal, Server* as){
	software_training_assignment::TurtleSeekerFeedback feedback;
	software_training_assignment::TurtleSeekerResult result;
	geometry_msgs::Twist msg;
	ros::Rate r(1);

  	float vecX = movX - goal->x;
	float vecY = movY - goal->y;
	float t = 5;
	
	float linV = findVectorMagnitude(vecX, vecY) / t;
	float angV = findAngularVelocity(vecX, vecY, 1);
	
	msg.angular.z = angV;
	turtle_pub.publish(msg);
	msg.angular.z = 0;
 	r.sleep();	
	for(int i=0; i<t; i++){
		msg.linear.x = linV;
		turtle_pub.publish(msg);
		feedback.d=linV;
		as->publishFeedback(feedback);
		r.sleep();
	}
	result.time = 1.0 + t;
	as->setSucceeded(result);
}

int main(int argc, char **argv){
	int success=0;
	ros::init(argc, argv, "custom_turtle");  //Initialize ROS
	ros::NodeHandle n;		          //Create handle to process node
	ros::Rate loop_rate(1);
	while(success!=1){
		loop_rate.sleep();
		success = killTurtle("turtle1");
	}
	success = spawnTurtle("stationary_turtle", 5.0, 5.0, 0.0);
	success = spawnTurtle("moving_turtle",4,3,0.0);
	Server server(n, "turtle_seek", boost::bind(&execute, _1, &server), false);
	server.start();
	ros::ServiceServer service = n.advertiseService("reset_turtle",resetMovingTurtle);
	mTurt = n.subscribe("/moving_turtle/pose", 1000,turtleCallback);
	turtle_pub = n.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel", 1000);
	ros::Publisher dist_pub = n.advertise<software_training_assignment::Dist>("distances", 1000);

	while(ros::ok()){
		software_training_assignment::Dist dist; //Instantiate message	
		dist.xdist = movX-5.0;	 	         //Calc xdist from stationary turtle
		dist.ydist = movY-5.0;			 //Calc ydist from stationary turtle
		dist.absdist = findVectorMagnitude(dist.xdist, dist.ydist);	//Find total distance
		ROS_INFO("Absolute dist[%f]", dist.absdist);
		dist_pub.publish(dist);			//Publish message
		loop_rate.sleep();
		ros::spinOnce();			//Spin Up for service to callback
	}	
	return 0;
}


int killTurtle(std::string name){
	/**
	* Kills turtle, removing it from the screen
	*/
	
	turtlesim::Kill srv;	//Init service class
	srv.request.name = name; //Fill request parameters
	if(ros::service::call("kill",srv)){
		ROS_INFO("Succesful Call");
	}else{
	 	ROS_ERROR("Unsuccesful Call");
		return 0;
	}
	return 1;
}

int spawnTurtle(std::string name, float x, float y, float theta){
	/**
	* Spawns a turtle
	*/
  	turtlesim::Spawn srv;	//Init service class
	
	//Fill request parameters	
	srv.request.name = name;
	srv.request.x = x;
	srv.request.y = y;
	srv.request.theta = theta;
 
	if(ros::service::call("spawn",srv)){
		ROS_INFO("Succesful Call");
	}else{
	 	ROS_ERROR("Unsuccesful Call");
		return 0;
	}
	return 1;
}


int teleportTurtle(std::string name, float x, float y, float theta){
	/**
	* Teleports a turtle
	*/
  	turtlesim::TeleportAbsolute srv;	//Init service class
	
	//Fill request parameters
	name.append("/teleport_absolute");
	srv.request.x = x;
	srv.request.y = y;
	srv.request.theta = theta;
 
	if(ros::service::call(name,srv)){
		ROS_INFO("Succesful Call");
	}else{
	 	ROS_ERROR("Unsuccesful Call");
		return 0;
	}
	return 1;
}


bool resetMovingTurtle(software_training_assignment::ResetTurtle::Request &req, software_training_assignment::ResetTurtle::Response &res){
	/**
	* Kills turtle, removing it from the screen
	*/

	std_srvs::Empty srv;	//Init service class
	
 
	if(teleportTurtle("/moving_turtle", 10, 10, 0)){
		ROS_INFO("Succesful Call");
		ros::service::call("/clear",srv);
		res.success=true;
	}else{
	 	ROS_ERROR("Unsuccesful Call");
		res.success=false;
	}
	return true;

	/* Using kill and spawn to 'teleport' the turtle
	std::string name = "moving_turtle";
	if(killTurtle(name) && spawnTurtle(name, 25.0, 10.0, 0.0)){
		res.success=true;
	}else{
		res.success=false;
	}
	return true;
	*/
}



