# software_challenge
## Instructions
1. Create a ros package called software_training_assignment
2. Install the turtlesim package(hint: you shouldn't be downloading any source code from github. You should be using a package manager).
3. Create a launch file that launches the turtlesim node​ ​ with a background colour of (r=128, b=0, g=128)
    Hint: ​ http://wiki.ros.org/Names​ and http://wiki.ros.org/roslaunch/XML/group​ are useful. 
    You need to make sure the parameter values are set in the correct ROS namepace
4. Write a node that:
    a. Clears any existing turtles
    b. Spawns a turtle named "stationary_turtle" at x = 5, y = 5
    c. Spawns a second turtle named "moving_turtle" at x = 25, y = 10
    d. Create a service that resets the "moving_turtle" to its starting position. 
        The service response should be whether or not it was successful.
    e. Create a publisher that publishes a custom msg. 
        This custom msgs should have 3 integer fields that correspond with the x and y distances of "stationary_turtle" to "moving turtle", 
        as well as the distance between the two turtles.
    f. Create an action that moves "moving_turtle" to a waypoint in a straight line by publishing geometry_msgs/Twist msgs to ​ turtleX/cmd_vel.​
        The action's goal cd is an absolute position of the waypoint, feedback is distance to the goal, and result is the time it took to reach the goal. 
        You should define a custom action file.
5. Add your node you created to your launch file. Make sure your node doesn't crash if the turtlesim_node has not come up yet.
6. Create a .gitignore file so that only relevant files are committed. The point of this is to
avoid committing all of your IDE specific configuration files.
7. Create a fork of the ​ https://github.com/uwrobotics/software_challenge​ and push your
package to your fork. Make a pr to the original and msg Azum or Hamza with the link.
The root directory of the repo should only contain your package folder.