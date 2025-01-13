# Learning_task
## 笔记
- 见 [Notes](./doc/notes.md)

## 完成情况

![rviz](./imgs/img1.png)

![gazebo](./imgs/img2.png)

控制器使用了ros官方的diff_drive_controller，见[差速控制器wiki](http://wiki.ros.org/diff_drive_controller)与[仓库](https://github.com/ros-controls/ros_controllers/tree/noetic-devel/diff_drive_controller)，[原理wiki](https://en.wikipedia.org/wiki/Differential_wheeled_robot#Kinematics_of_Differential_Drive_Robots)

根据wiki的yaml例子和自己的urdf小车参数写好yaml，并写好launch就可以用了，注意需要输入的/cmd_vel的命名空间（urdf需要导入gazebo_ros_control插件，[URDF_Design](./doc/URDF_Design.md))

Todo：再练习写几个urdf，cpp版的键盘控制（可能do一半不do了）

