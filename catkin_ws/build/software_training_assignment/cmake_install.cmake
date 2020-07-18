# Install script for directory: /home/joshua/software_challenge/catkin_ws/src/software_training_assignment

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/joshua/software_challenge/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assignment/msg" TYPE FILE FILES "/home/joshua/software_challenge/catkin_ws/src/software_training_assignment/msg/Distance.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assignment/srv" TYPE FILE FILES "/home/joshua/software_challenge/catkin_ws/src/software_training_assignment/srv/resetMovingTurtle.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assignment/action" TYPE FILE FILES "/home/joshua/software_challenge/catkin_ws/src/software_training_assignment/action/Move.action")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assignment/msg" TYPE FILE FILES
    "/home/joshua/software_challenge/catkin_ws/devel/share/software_training_assignment/msg/MoveAction.msg"
    "/home/joshua/software_challenge/catkin_ws/devel/share/software_training_assignment/msg/MoveActionGoal.msg"
    "/home/joshua/software_challenge/catkin_ws/devel/share/software_training_assignment/msg/MoveActionResult.msg"
    "/home/joshua/software_challenge/catkin_ws/devel/share/software_training_assignment/msg/MoveActionFeedback.msg"
    "/home/joshua/software_challenge/catkin_ws/devel/share/software_training_assignment/msg/MoveGoal.msg"
    "/home/joshua/software_challenge/catkin_ws/devel/share/software_training_assignment/msg/MoveResult.msg"
    "/home/joshua/software_challenge/catkin_ws/devel/share/software_training_assignment/msg/MoveFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assignment/cmake" TYPE FILE FILES "/home/joshua/software_challenge/catkin_ws/build/software_training_assignment/catkin_generated/installspace/software_training_assignment-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/joshua/software_challenge/catkin_ws/devel/include/software_training_assignment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/joshua/software_challenge/catkin_ws/devel/share/roseus/ros/software_training_assignment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/joshua/software_challenge/catkin_ws/devel/share/common-lisp/ros/software_training_assignment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/joshua/software_challenge/catkin_ws/devel/share/gennodejs/ros/software_training_assignment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/joshua/software_challenge/catkin_ws/devel/lib/python2.7/dist-packages/software_training_assignment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/joshua/software_challenge/catkin_ws/devel/lib/python2.7/dist-packages/software_training_assignment")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/joshua/software_challenge/catkin_ws/build/software_training_assignment/catkin_generated/installspace/software_training_assignment.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assignment/cmake" TYPE FILE FILES "/home/joshua/software_challenge/catkin_ws/build/software_training_assignment/catkin_generated/installspace/software_training_assignment-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assignment/cmake" TYPE FILE FILES
    "/home/joshua/software_challenge/catkin_ws/build/software_training_assignment/catkin_generated/installspace/software_training_assignmentConfig.cmake"
    "/home/joshua/software_challenge/catkin_ws/build/software_training_assignment/catkin_generated/installspace/software_training_assignmentConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/software_training_assignment" TYPE FILE FILES "/home/joshua/software_challenge/catkin_ws/src/software_training_assignment/package.xml")
endif()

