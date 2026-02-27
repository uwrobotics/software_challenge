import launch 
from launch_ros.actions import Node, ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    """Generate launch description with multiple components."""
    turtlesim_node = Node(
        package='turtlesim',
        executable='turtlesim_node',
        name='sim'
    )

    container = ComposableNodeContainer(
            name='software_training_container',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='software_training',
                    plugin='composition::turtle_service_request_node',
                    name='turtle_request'),
                ComposableNode(
                    package='software_training',
                    plugin='composition::spawn_turtle_nodelet',
                    name='turtle_spawn'),
                ComposableNode(
                    package='software_training',
                    plugin='composition::cmd_vel_moving_turt_publisher',
                    name='cmd_vel_publisher'),
                ComposableNode(
                    package='software_training',
                    plugin='composition::reset_moving_turtle_service',
                    name='turtle_service'),
                ComposableNode(
                    package='software_training',
                    plugin='composition::turtle_publisher',
                    name='turtle_pub'),
                ComposableNode(
                    package='software_training',
                    plugin='composition::moving_turtle_action_server',
                    name='turtle_action_server'),
            ],
            output='screen',
    )

    return launch.LaunchDescription([turtlesim_node, container])