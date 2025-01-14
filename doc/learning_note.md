## DynamicX 梯度任务学习笔记

周煜 2025.1.13



### Gazebo 实现模型仿真大致流程

##### 1.编写 xacro 文件, 声明相关 link / joint / transmission

xacro 即 XML macro, 善用xacro:macro 标签可提高代码复用率

include 其他 xacro 文件时尽量避免使用$(find xxx),疑似会找到其他工程文件中的同名文件

若要使用 gazebo 仿真,记得加上 gazebo 标签,加载 gazebo_ros_control 插件



##### 2.编写 yaml 配置文件, 声明相关控制器 type

记得 CMakeLists 导入相关软件包



##### 3.编写 launch 文件, 加载 xacro 文件, 加载 yaml 文件, 启动 gazebo 仿真

##### 4.编写 c++ 文件, 实现相关功能



### 常见问题

##### Controller Spawner couldn't find the expected controller_manager ROS interface.

检查 gazebo_ros_control 插件是否加载

joint_state_publish 要记得启动

launch文件的启动顺序可能会影响gazebo

gazebo_ros_control / hardwareinterface 标签一定要写对
