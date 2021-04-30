from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
            Node(
                package='turtlesim',
                executable='turtlesim_node',
                parameters=[
                    {"background_r": 128},
                    {"background_g": 128},
                    {"background": 0}
                ]
            ),
            Node(
                package='onboarding_assignment',
                executable='main_node'
            ),
            Node(
                package='onboarding_assignment',
                executable='distance_publisher'),
            Node(
                package='onboarding_assignment',
                executable='server'),
            Node(
                package='action_tutorials_cpp',
                executable='waypoint_action_server')
            
    ])