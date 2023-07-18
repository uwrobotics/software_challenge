The training challenge consists of the following:

That training relies heavily on components - as this is the newer and better way to go about ROS2 design

Write 6 components that do the following: (Note: Some of the components do not need to be made in the following order)

    Clears any existing turtles

    Create a component that moves 'turtle1' in a circular motion

    Spawns a turtle named "stationary_turtle" at x = 5, y = 5 Spawns a second turtle named "moving_turtle" at x = 25, y = 10

    Create a service that resets the "moving_turtle" to its starting position. The service response should be whether or not it was successful.

    Create a publisher that publishes a custom msg. This custom msgs should have 3 float fields that correspond with the x and y distances of "stationary_turtle" to "moving turtle", as well as the distance between the two turtles.

    Create an action that moves "moving_turtle" to a waypoint in a straight line by publishing geometry_msgs/Twist msgs to turtleX/cmd_vel.The action's goal command is an absolute position of the waypoint, feedback is distance to the goal, and result is the time it took to reach the goal. You should define a custom action file.

Lastly, create a launch file that will start up all the components and the turtlesim node (configure the parameters of the turtlesim node to however you see fit). Ensure that the turtlesim node is launched first as the other components are dependent upon it.


After each package, build with `colcon build`, then run the particular service:
e.g `ros2 run challenge_package circle_turtle_service`, then call the service with `ros2 service call /move_turtle1_circular std_srvs/srv/Trigger`

