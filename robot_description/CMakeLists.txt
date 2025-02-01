cmake_minimum_required(VERSION 3.0.2)
project(robot_description)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    rospy
    controller_interface
    hardware_interface
    forward_command_controller
    pluginlib
)

catkin_package(
        INCLUDE_DIRS
        include
        LIBRARIES
        CATKIN_DEPENDS

        roscpp
        controller_interface
        hardware_interface
        forward_command_controller
        pluginlib
        DEPENDS
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)
add_library(${PROJECT_NAME}
        src/test.cpp
#        include/test/test.h
)

add_dependencies(${PROJECT_NAME}
        ${catkin_EXPORTED_TARGETS}
)

target_link_libraries(${PROJECT_NAME}
        ${catkin_LIBRARIES}
)

#install(FILES test_controller_plugins.xml
#        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})


# Mark resource files for installation

#install(
#        DIRECTORY meshes urdf
#        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#)
#
## Mark other files for installation
#install(
#        DIRECTORY doc
#        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#)