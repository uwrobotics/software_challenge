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
#define PI 3.14159265

typedef actionlib::SimpleActionServer<software_training_assignment::TurtleSeekerAction> Server;

//Global Vars 
//SIDENOTE: I would do it the class way, but it just seems overkill for this
float movX=25;				//moving_turtle x-coord
float movY=10;				//moving_turtle y-coord
float currTheta=0;			//moving_turlte z-coord
ros::Subscriber moving_turtle_pose;			//Subscriber to Pose of moving_turtle
ros::Publisher turtle_seeker_pub; 				//Publisher for TurtleSeekerAction

float findVectorMagnitude(float x, float y){
	//Finds magnitude of a 2-dimensional vector given its components
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

float findAngularVelocity(float x, float y, float t){
	/**
	* Finds the required angular velocity to move angle 
	* from currTheta to direction of given 2-dimensional vector
	*/
	float theta = atan(x/y);	
	float quad = PI/2;			//90 degrees in rads, value of a quadrant
	
	if(x==0 && y==0){	//At position
		return -1 *currTheta;
	}
	
	if(x==0){		//Directly above or below
		theta = (y/sqrt(pow(y,2))) * -quad;
	}else 
	if(y==0){		//Directly left or right
		theta = quad + (x/sqrt(pow(x,2))) * quad;
	}else
	if(x>0){
		if(y>0){
		//Turtle at Quadrant 1: +x, +y
		theta = -quad - theta;
		}else{
		//Turtle at Quadrant 4: +x, -y
		theta = quad + theta;
		}
	}
	else{
		if(y>0){
		//Turtle at Quadrant 2: -x, +y
		theta = -quad + theta;
		}else{
		//Turtle at Quadrant 3: -x, -y
		theta = quad - theta;
		}
	}
	return ((theta -currTheta)/t);
}



void execute(const software_training_assignment::TurtleSeekerGoalConstPtr& goal, Server* as){
	/**
	* Simple action that moves turtle to given absolute position
	*
	* 1. Determine vector between turtle and waypoint
	* 2. Determine required linear and angular velocity to get to waypoint
	* 3. Execute angular velocity command to rotate turtle towards the correct direction
	* 4. Execute linear velocity command to move turtle forward towards waypoint
	* 5. Action Complete
	*/
	
	//Instantiation
	software_training_assignment::TurtleSeekerFeedback feedback;
	software_training_assignment::TurtleSeekerResult result;
	geometry_msgs::Twist msg;
	ros::Rate r(1);
	
	//1.
  	float vecX = movX - goal->x; 	//Calculate x component of vector
	float vecY = movY - goal->y;	//Calculate y componenet of vector
	float t = 5;			//Time it will take to execute linear velocity command (choice was arbritary)
	bool done = true;		//Checks if task was done successfully (not preempted, roscore not shutdown)
	
	//2.
	float distanceVec = findVectorMagnitude(vecX, vecY);	//Find magnitude of distance vector
	float linV = distanceVec / t;				//Calculate required linear velocity
	float angV = findAngularVelocity(vecX, vecY, 1);	/*Calculate required angular velocity to be executed for 1 second
								  (1sec is arbritary, but must be accounted for during sleep)
								*/
	
	//3.
	msg.angular.z = angV;					//Set angular velocity of message
	turtle_seeker_pub.publish(msg);				//Publish message
	msg.angular.z = 0;					//Set angular velocity of message
 	r.sleep();						//Wait for command to execute (waits 1sec)	
	
	//4.
	for(int i=0; i<t; i++){
		if(as->isPreemptRequested() || !ros::ok()){
		 	as->setPreempted();
			done = false;
		}
		msg.linear.x = linV;				//Set linear velocity of message
		turtle_seeker_pub.publish(msg);			//Publish message	
		feedback.d = findVectorMagnitude((movX - goal->x), (movY - goal->y));	//Set feedback to vector magnitude
		as->publishFeedback(feedback);			//Publish feedback
		r.sleep();					//Wait for command to execute (waits 1sec)
	}
	result.time = 1.0 + t;					/*Set result time to total time taken by 
								  adding time taken by linear and angular commands
								*/
	if(done){
		as->setSucceeded(result);				//Set Success
	}
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
	
 
	if(teleportTurtle("/moving_turtle", 25, 10, 0)){
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

void turtleCallback(const turtlesim::Pose::ConstPtr &msg){
	//Callback for moving_turtle Subscriber
	//Sets values to global variables
	movX = msg->x;
	movY = msg->y;
	currTheta = msg->theta;
}
	
int main(int argc, char **argv){
	int success=0;
	ros::init(argc, argv, "custom_turtle");  //Initialize ROS
	ros::NodeHandle n;		          //Create handle to process node
	ros::Rate loop_rate(1);			 //Initialize loop_rate for publishing distance message (keep as 1 to work with action)
	while(success!=1){			//While kill turtle is not a success i.e. turtlesim node is not up
		loop_rate.sleep();		/*Wait 1 sec to let turtlesim node to popup 
						(not needed but makes it simple in most cases)*/
		success = killTurtle("turtle1");	//Attempt to kill turtle1
	}
	success = spawnTurtle("stationary_turtle", 5.0, 5.0, 0.0); 	//Spawn stationary_turtle
	success = spawnTurtle("moving_turtle",25,10,0.0);			//Spawn moving_turtle
	
	//ActionServer
	Server server(n, "turtle_seek", boost::bind(&execute, _1, &server), false);	//Instantiate ActionServer
	server.start();									//Start ActionServer
	turtle_seeker_pub = n.advertise<geometry_msgs::Twist>("/moving_turtle/cmd_vel", 1000);	//Publish to moving_turtle cmd_vel

	ros::ServiceServer service = n.advertiseService("reset_turtle",resetMovingTurtle);	//Advertise reset_turtle service
	moving_turtle_pose = n.subscribe("/moving_turtle/pose", 1000,turtleCallback);		//Subscribe to moving_turtle pose
	ros::Publisher dist_pub = n.advertise<software_training_assignment::Dist>("distances", 1000); //Publish custom distance message

	while(ros::ok()){
		software_training_assignment::Dist dist; //Instantiate message	
		dist.xdist = movX-5.0;	 	         //Calculate xdist from stationary turtle
		dist.ydist = movY-5.0;			 //Calculate ydist from stationary turtle
		dist.absdist = findVectorMagnitude(dist.xdist, dist.ydist);	//Find total distance
		//ROS_INFO("Absolute dist[%f]", dist.absdist);
		dist_pub.publish(dist);			//Publish message
		loop_rate.sleep();
		ros::spinOnce();			//Spin Up for service to callback
	}	
	return 0;
}
