# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = (
    "${prefix}/include".split(";") if "${prefix}/include" != "" else []
)
PROJECT_CATKIN_DEPENDS = "roscpp;std_msgs;tf;tf2;urdf;xacro".replace(";", " ")
PKG_CONFIG_LIBRARIES_WITH_PREFIX = (
    "-lrobot_car".split(";") if "-lrobot_car" != "" else []
)
PROJECT_NAME = "robot_car"
PROJECT_SPACE_DIR = "/home/qyd/Learning_task/qyd_work/car_ws/install"
PROJECT_VERSION = "0.0.0"
