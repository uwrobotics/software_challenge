import launch
from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer, Node
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    return launch.LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim_node'
        ),
        ComposableNodeContainer(
            name='container',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package="swtraining",
                    plugin="composition::drawCircle",
                    name="drawCircle"
                ),
                ComposableNode(
                    package="swtraining",
                    plugin="composition::spawnturtles",
                    name="spawnturtles"
                ),
                ComposableNode(
                    package="swtraining",
                    plugin="composition::waypoint",
                    name="waypoint"
                ),
                ComposableNode(
                    package="swtraining",
                    plugin="composition::turtledistance",
                    name="turledistance"
                ),
                ComposableNode(
                    package="swtraining",
                    plugin="composition::resetturtle",
                    name="resetturtle"
                ),
                ComposableNode(
                    package='swtraining',
                    plugin='composition::clearturtles',
                    name="clearturtles"
                )
            ],
            output='screen',
        )               
    ])

