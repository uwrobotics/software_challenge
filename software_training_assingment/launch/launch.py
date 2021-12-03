from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    
    return LaunchDescription([
        Node(
            package='turtlesim',
            executable='turtlesim_node',
        ),
        Node(
            package='software_training_assingment',
            executable='client',
        
        ),
        Node(
            package='software_training_assingment',
            executable='create_turtles',
        
        ),
        Node(
            package='software_training_assingment',
            executable='circ_motion',
        ),


        Node(
            package='software_training_assingment',
            executable='reset_turtles',
        
        ),
        Node(
            package='software_training_assingment',
            executable='rel_dist',
        
        ),
        Node(
            package='software_training_assingment',
            executable='wayward',
        
        )
    ])
