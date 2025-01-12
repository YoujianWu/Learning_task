# 学习总结
## 如何用urdf编写模型
### 1编写link
### 2用joint连接link
### 3为每个joint添加actuator
### 4添加gazebo_ros_control插件
## 如何加载控制器
### 1写yaml控制器参数文件
### 2在launch文件中上传参数和启动控制器
## 运行效果图
![效果图](https://github.com/QiuYDvv/picture/blob/master/2025-01-12 13-44-23屏幕截图.png)
## 使用命令
### 1启动仿真和加载控制器
```shell
roscore
mon launch robot_car robot.launch 
```
### 2驱动小车运动命令
```shell
rostopic pub /controller/left_front_wheel_controller/command std_msgs/Float64 "data: 1.0" 
```
