cmake_minimum_required(VERSION 3.0.2)
project(simple_chassis_controller)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-Wall -Werror)

find_package(catkin REQUIRED
    COMPONENTS
    roscpp
    roslint
    urdf
    pluginlib

    std_msgs
    nav_msgs
    geometry_msgs
    sensor_msgs
    control_msgs

    controller_manager
    controller_interface
    control_toolbox

    realtime_tools
    effort_controllers
    hardware_interface
    forward_command_controller
    position_controllers

    tf
    tf2
    tf2_ros
    tf2_geometry_msgs

    joint_state_controller
    dynamic_reconfigure

    actionlib
    actionlib_msgs
)

catkin_package(
    INCLUDE_DIRS
    include
    LIBRARIES
    CATKIN_DEPENDS

    roscpp
    roslint
    urdf
    pluginlib

    std_msgs
    nav_msgs
    geometry_msgs
    sensor_msgs
    control_msgs

    controller_manager
    controller_interface
    control_toolbox

    realtime_tools
    effort_controllers
    hardware_interface
    forward_command_controller
    position_controllers

    tf
    tf2
    tf2_ros
    tf2_geometry_msgs

    joint_state_controller
    dynamic_reconfigure

    actionlib
    actionlib_msgs

    DEPENDS
# hero_chassis_controller
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)
include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    # Set manually because Eigen sets a non standard INCLUDE DIR
)

## Declare cpp executables
add_library(${PROJECT_NAME}
    src/${PROJECT_NAME}.cpp
    )

add_dependencies(${PROJECT_NAME}
    ${catkin_EXPORTED_TARGETS}
    )

target_link_libraries(${PROJECT_NAME}
    ${catkin_LIBRARIES}
    )

roslint_cpp()
