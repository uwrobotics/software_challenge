from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='turtlesim',
            namespace='',
            executable='turtlesim_node',
        ),
        Node(
            package='challenge_package',
            namespace='',
            executable='clear_turtle_listener',
        ),
        Node(
            package='challenge_package',
            namespace='',
            executable='circle_turtle_service',
        ),
        Node(
            package='challenge_package',
            namespace='',
            executable='spawn_turtle_service',
        ),
        Node(
            package='challenge_package',
            namespace='',
            executable='reset_turtle_service',
        ),
        Node(
            package='challenge_package',
            namespace='',
            executable='dist_publisher',
        ),
        Node(
            package='challenge_package',
            namespace='',
            executable='move_action_server',
        ),
    ])