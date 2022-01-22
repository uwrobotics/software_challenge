import launch 
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

from launch_ros.actions import Node
from launch_ros.descriptions import ComposableNode
from launch_ros.actions import ComposableNodeContainer
from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, EmitEvent, ExecuteProcess,
                            LogInfo, RegisterEventHandler, TimerAction)
from launch.conditions import IfCondition
from launch.event_handlers import (OnExecutionComplete, OnProcessExit,
                                OnProcessIO, OnProcessStart, OnShutdown)
from launch.events import Shutdown
from launch.substitutions import (EnvironmentVariable, FindExecutable,
                                LaunchConfiguration, LocalSubstitution,
                                PythonExpression)


def generate_launch_description():
    """Generate launch description with multiple components."""

    container = ComposableNodeContainer(
            name='node_container',
            namespace='',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='software_training_assignment',
                    plugin='composition::clear_turtles',
                    name='clear_turtles',
                    ),
                ComposableNode(
                    package='software_training_assignment',
                    plugin='composition::spawn_turtle_nodelet',
                    name='turtle_spawn',
                    ),
                ComposableNode(
                    package='software_training_assignment',
                    plugin='composition::turtle_circle_publisher',
                    name='turtle_circle',
                    ),
                ComposableNode(
                    package='software_training_assignment',
                    plugin='composition::turtle_publisher',
                    name='turtle_publisher',
                    ),
                ComposableNode(
                    package='software_training_assignment',
                    plugin='composition::reset_moving_turtle',
                    name='reset_moving_turtle',
                    ),        
            ],
            output='screen',
    )
    turtlesimlaunch = ComposableNodeContainer(
            package='turtlesim',
            namespace='turtlesim1',
            executable='turtlesim_node',
            name='turtle1',
            composable_node_descriptions=[]
    )

    # spawn_turtle = ExecuteProcess(
    #         cmd=[[
    #             FindExecutable(name='ros2'),
    #             ' service call ',
    #             turtlesim_ns,
    #             '/spawn ',
    #             'turtlesim/srv/Spawn ',
    #             '"{x: 2, y: 2, theta: 0.2}"'
    #         ]],
    #         shell=True
    #     )

    # task1 =  RegisterEventHandler(
    #         OnProcessStart(
    #             target_action=turtlesim_node,
    #             on_start=[
    #                 LogInfo(msg='Turtlesim started, spawning turtle'),
    #                 spawn_turtle
    #             ]
    #         )
    #     )
    # task2 =  RegisterEventHandler(
    #         OnProcessStart(
    #             target_action=turtlesim_node,
    #             on_start=[
    #                 LogInfo(msg='Turtlesim started, spawning turtle'),
    #                 spawn_turtle
    #             ]
    #         )
    #     ),
    

    return launch.LaunchDescription([container,turtlesimlaunch])