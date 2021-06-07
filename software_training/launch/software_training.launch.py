from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    """Generate launch description with multiple components."""
    return LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
            name='turtlesim_node'
        ),
        ComposableNodeContainer(
            name='container1',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='software_training',
                    plugin='software_training::clear_turtles_server',
                    name='clear_turtles_server'),
                ComposableNode(
                    package='software_training',
                    plugin='software_training::spawn_turtles_server',
                    name='spawn_turtles_server'),
                ComposableNode(
                    package='software_training',
                    plugin='software_training::reset_moving_turtle_server',
                    name='reset_moving_turtle_server'),
                ComposableNode(
                    package='software_training',
                    plugin='software_training::move_to_waypoint_action_server',
                    name='move_to_waypoint_action_server')
            ],
            output='screen',
        ),
        ComposableNodeContainer(
            name='container2',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='software_training',
                    plugin='software_training::move_turtle1_in_circle_publisher',
                    name='move_turtle1_in_circle_publisher')
            ],
            output='screen',
        ),
        ComposableNodeContainer(
            name='container3',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='software_training',
                    plugin='software_training::turtle_distance_publisher',
                    name='turtle_distance_publisher')
            ],
            output='screen',
        )
    ])
