# software_challenge

## Usage:
1. Add package to your workspace, `cd` into your workspace, run `source ./devel/setup.bash`, `catkin_make`
2. Start the turtlesim and my_turtle nodes by running:
	```
	roslaunch software_training_assignment launcher.launch
	```
3. To use the reset "moving_turtle" service run:
	```
	rosservice call /reset_moving_turtle
	```
4. To get information about the distances between the "stationary_turtle" and "moving_turtle" run:
	```
	rostopic echo /turtle_distance
	```
5. To use the "moving_turtle" action run:
	```
	rosrun software_training_assignment MoveTurtleActionTester _x:=2 _y:=5
	```

Replace the x and y parameters to whatever you would like to move the "moving_turtle".
