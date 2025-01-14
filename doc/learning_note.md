DynamicX 梯度任务学习笔记

周煜 2025.1.13



Gazebo 实现模型仿真大致流程

1.编写 xacro 文件, 声明相关 link / joint / transmission

2.编写 yaml 配置文件, 声明相关控制器 type

3.编写 launch 文件, 加载 xacro 文件, 加载 yaml 文件, 启动 gazebo 仿真

4.编写 c++ 文件, 实现相关功能
