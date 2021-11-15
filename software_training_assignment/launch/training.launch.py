import launch
from launch_ros.actions import Node


from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    return launch.LaunchDescription([
        Node(
            package='turtlesim',
            namespace='turtlesim2',
            executable='turtlesim_node',
            name='turtlesim'
        ),
        Node(
            package='software_training_assignment',
            namespace='composition',
            executable='spawn',
            name='spawn'
        )])