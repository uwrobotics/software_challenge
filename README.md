# software_challenge

Usage:
1. Add package to your workspace,cd into your workspace, source ./devel/setup.bash, catkin build
2. Start the turtlesim and custom_turtle nodes by running:
	roslaunch software_training_assignment turtle_launcher.launch
3. To use the reset moving_turtle service run:
	rosservice call /reset_turtle
4. To get information about distances between the turtles run:
	rostopic echo /distances
5. To use the moving_turtle action run:
	rosrun software_training_assignment action_tester _x:=2 _y:=4
   Replace the x and y parameters to wherever you would like to move the turtle.
   The action will run correctly multiple times in a row.
   To change the time taken during the linear motion, see the custom_turtle.cpp file, change the t value.
	
