# 搭建机器人模型

本包写了一个简单的小车模型，使用`roslaunch robot_description load_test_controller.launch`后，小车会往前做匀加速直线运动

## urdf建模：

- 语法：

```xml
<robot name="">
<!--（选填）机器人-->

    <link name="">
<!--    （必填）连杆-->

        <inertial>
<!--         （选填）惯性特性-->
            <origin xyz="0 0 0" rpy="0 0 0" />
<!--           （选填）惯性参考系的参考坐标，定义在重心处；xyz为坐标轴的平移量；rpy为旋转量-->         
            <mass value="" />                       
<!--          （必填）质量-->
            <inertia ixx="" iyy="" izz="" ixy="" ixz="" iyz="" />  
<!--          （必填）惯性张量：描述刚体转动惯性，iaa为对a轴的转动惯量，iab为惯性积-->
        </inertial>
      
        <visual name="">                        
<!--          （必填）可视化-->
            <origin xyz="0 0 0" rpy="0 0 0" />  
<!--          （选填）可视化-->
            <geometry>                          
<!--              （必填）几何描述，可以用stl文件构建复杂的模型-->
                <box size="" />                        
<!--              长方体-->
                <cylinder radius="" length="" />       
<!--              圆柱体-->
                <sphere radius="" />                   
<!--              球-->
                <mesh filename="" scale="1" />         
<!--              网格，由本地文件决定，可以是collada.dae或.stl-->
            </geometry>
            <material name="">                  
<!--              （选填）可视化材料-->
                <color rgba="0.5 0.5 0.5 1" />  
<!--              （选填）颜色，rgba：rbg和透明度alpha，范围[0, 1]-->
                <texture filename="" />         
<!--              （选填）材料属性，文件决定-->
            </material>
        </visual>
      
        <collision name="">                   
<!--          （选填）碰撞箱，用于简化物理模型-->
            <origin xyz="0 0 0" rpy="0 0 0" /> 
<!--          （选填）碰撞组件相对于连杆的参考坐标系-->
            <geometry>                         
<!--              （必填）几何描述 -->
                <box size="" />
                <cylinder radius="" length="" />
                <sphere radius="" />
                <mesh filename="" scale="1" />
            </geometry>
        </collision>
    </link>
    
    <joint name="" type="">                      
<!--      （选填）关节-->
        <origin xyz="0 0 0" rpy="0 0 0" />       
<!--      （选填）是从父连杆到子连杆的转换，默认全为0-->
        <parent link="" />                       
<!--      （必填）父连杆，一个父连杆可以有多个子连杆-->
        <child link="" />                        
<!--      （必填）子连杆，一个子连杆只能有一个父连杆  -->
        <axis xyz="1 0 0" />                     
<!--      （选填）关节轴，旋转关节、平移关节平面关节都有着不同的关节轴-->
        <calibration rising="" falling=""/>      
<!--      （选填）joint的参考位置，rising为关节正方向运动时，参考位置触发上升沿，falling则为触发下降沿-->
        <dynamics damping="0" friction="0" />    
<!--      （选填）动力学模型，用于仿真，damping为关节阻尼值，friction为关节的物理静摩擦值-->
        <limit lower="" upper="" effort="" velocity="" />    
<!--      （仅旋转和棱柱关节需要）限位，lower、upper为上下限，effort为最大力，velocity为最大速度-->
        <mimic joint="" multiplier="1" offset="0" />
<!--      （选填）此标记用于指定定义的关节模拟另一个现有关节-->
        <safety_controller soft_lower_limit="0" soft_upper_limit="0" k_position="0" k_velocity="0" />
<!--      （选填）soft_lower（upper）_limit（可选，默认为 0）为安全控制器开始限制关节位置的下（上）关节边界，-->
<!--      k_position（可选，默认为 0）指定位置和速度限制之间关系的属性。-->
<!--      k_velocity（必需）指定 effort 和 velocity limits 之间关系的属性。-->
    </joint>
</robot>
```

## 加载控制器到机器人模型中

步骤：

1. 编写机器人基础的urdf模型

2. 设置xacro的\<transmission>组件

   \<transmission>作用:用于描述关节与驱动器之间的关系，每个关节都需要对应的transmission

   例子：

    ```xml
    <transmission name="simple_trans">
        <type>transmission_interface/SimpleTransmission</type>
    <!--（必填）定义transmission的类型  -->
      
        <joint name="foo_joint">  
    <!-- （必填）定义关节的驱动类型-->
            <hardwareInterface>EffortJointInterface</hardwareInterface>
    <!--     指定硬件接口，注意，当在Gazebo中加载此传动系统是，值应为EffortJointInterface-->
    <!--     而在RobotHW中加载此传动系统时，值应为hardware_interface/EffortJointInterface-->
        </joint>
      
        <actuator name="foo_motor">
            <mechanicalReduction>50</mechanicalReduction>
    <!--     可选，指定关节制动器之间机械减速比，并非所有传动系统都需要此标签-->
            <hardwareInterface>EffortJointInterface</hardwareInterface>
    <!--     可选，指定硬件接口-->
        </actuator>
      
    </transmission>
    ```

   目前，只有 ros_control project 用到了\<transmission>组件

   在本包中，车有四个关节，都是**接受力矩指令的驱动器**（EffortJointInterface）

3. 编写控制器controller

    - 不同的controller可以完成对不同模块的控制。例如完成对关节力的控制、速度控制等等。请求下层的硬件资源，并提供PID控制器，读取底层硬件资源的状态，发送控制指令。

    - ros_control提供了很多的控制器，可以直接使用，或者重写自己的控制器

   官方wiki：https://github.com/ros-controls/ros_control/wiki/controller_interface

4. 编写硬件接口HardwareInterface

    本文没有写自己的HardwareInterface，是直接使用了HardwareInterface::EffortJointInterface

5. 加载控制器

    在package.xml文件中加入：

    ```xml
    <!--添加控制器-->
    <export>
        <controller_interface plugin="${prefix}/test_controller_plugins.xml"/>
    </export>
   ```

    在launch文件中加入：

    ```xml
   <launch>
     <!-- 加载 controller.yaml 文件 -->
     <rosparam file="$(find robot_description)/config/controllers.yaml" command="load"/>
        
     <!-- 使用 controller_manger 加载插件，对应着controller.yaml 文件 -->
     <node name="controller_spawner" pkg="controller_manager" type="spawner" respawn="false"
           output="screen" args="controller/test_controller controller/joint_state_controller">
     </node>
   </launch>
   ```





## 报错及解决 

- 问题1：报错：

    `[WARN] [1736931126.445399, 29.125000]: Controller Spawner couldn't find the expected controller_manager ROS interface.`

  控制器生成程序找不到预期的Controller_manager ROS接口(被这个报错硬控了两天。。。)

  原因1：报错时，在urdf文件中，plugin加载的是`<plugin name="ros_control" filename="libgazebo_ros_control.so">`，
  应该改成`<plugin name="rm_ros_control" filename="librm_robot_hw_sim.so">`

  原因2：同时，在package.xml文件里，没有加入：

  ```xml
  <export>
    <controller_interface plugin="${prefix}/test_controller_plugins.xml"/>
  </export>
  ```

  来加载和卸载控制器

- 问题2：单独加载模型没问题，加入控制器后模型加载错误

  原因：控制器给的力矩过大，导致模型扭曲

  解决：减小力矩的输入

- 问题3：`catkin build`后总是报warning

  解决：先`catkin clean`后再重新`catkin build`


  检查控制器是否被加载：`rosservice call controller_manager/list_controller_types`

