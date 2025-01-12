cmake_minimum_required(VERSION 3.10)
project(my_robot)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        geometry_msgs
        controller_manager
        xacro
)

###################################
## catkin specific configuration ##
###################################


catkin_package(
        CATKIN_DEPENDS
        roscpp
        std_msgs
        geometry_msgs
        controller_manager
        robot_state_publisher
        joint_state_publisher
        xacro
)

include_directories(
        include
        ${catkin_INCLUDE_DIRS}
)

#############
## Install ##
#############

# Mark resource files for installation
install(
        DIRECTORY urdf meshes
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY launch rviz urdf
        DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
