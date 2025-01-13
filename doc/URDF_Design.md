# URDF Design

## Link与Joint区别

- Link可见Joint不可见
- Joint=关节，链接两个Link，一个parent link一个child link

## Collision
碰撞箱，模型较简单时与visual一致，复杂时简化collision

## Transmission

定义传动关系，描述joint和acutor之间的关系

```xml
<transmission name="${wheel_name}_transmission">
            <type>transmission_interface/SimpleTransmission</type>
            <joint name="car_base_${wheel_name}">
                <hardwareInterface>hardware_interface/VelocityJointInterface</hardwareInterface>
            </joint>
            <actuator name="${wheel_name}_motor">
                <mechanicalReducction>1</mechanicalReducction><!--传动比定为1-->
            </actuator>
 </transmission>
```

需在transmission中定义关节接口类型（Velocity或Effort等，取决于实机和控制器），还可以设定电机传动比

## Xacro

- Xacro为urdf提供模板（宏），方便参数修改与减少代码量
  例如

  ```xml
  <xacro:macro name="wheel_car_joint" params="wheel_name front_back left_right">
          <link name="${wheel_name}">
              <visual>
                  <xacro:cylinder_geometry length="${wheel_length}" radius="${wheel_radius}"/>
                  <xacro:default_origin xyz="${wheel_origin_xyz}" rpyaw="${wheel_origin_rpy}" />
                  <material name="black"/>
              </visual>
              <collision>
                  <xacro:cylinder_geometry length="${wheel_length}" radius="${wheel_radius}"/>
                  <xacro:default_origin xyz="${wheel_origin_xyz}" rpyaw="${wheel_origin_rpy}" />
              </collision>
              <xacro:default_inertial mass="1.0"/>
          </link>
  
          <joint name="car_base_${wheel_name}" type="continuous">
              <origin xyz="${left_right*(wheel_length+car_width)/2.0} ${front_back*car_length*0.6/2.0} 0.0" rpy="0.0 0.0 0.0"/>
              <!--利用left_right和front_back正负决定位置-->
              <parent link="car_link"/>
              <child link="${wheel_name}"/>
              <axis xyz="1.0 0.0 0.0"/>
          </joint>
  
          <gazebo reference="${wheel_name}">
              <material>Gazebo/Black</material>
              <mu1>100000</mu1>            <!--静摩擦-->
              <mu2>100000</mu2>            <!--动摩擦-->
          </gazebo>
  <!--传动-->
          <transmission name="${wheel_name}_transmission">
              <type>transmission_interface/SimpleTransmission</type>
              <joint name="car_base_${wheel_name}">
                  <hardwareInterface>hardware_interface/VelocityJointInterface</hardwareInterface>
              </joint>
              <actuator name="${wheel_name}_motor">
                  <mechanicalReducction>1</mechanicalReducction><!--传动比定为1-->
              </actuator>
          </transmission>
      </xacro:macro>
  ```

  可以在宏定义调用其他的宏和property，同时进行运算等操作（利用xacro运算不用手动算数值，填好参数即可）


## Gazebo_ros_control

在urdff加上下面这段代码使用gazebo_ros_control插件，不然控制器加不进去

```xml
<gazebo>
    <plugin name="gazebo_ros_control" filename="libgazebo_ros_control.so">
        <robotNamespace>/</robotNamespace>
    </plugin>
</gazebo>
```

同时可能需要设置gazebo参数，例如可能会出现p参数没定义，需要再yaml中设置，要注意json格式，保证参数的命名空间对得上

```json
gazebo_ros_control:
  pid_gains:
    car_base_back_left_wheel:
        p: 1.0
        i: 0.0
        d: 0.0
    car_base_back_right_wheel:
        p: 1.0
        i: 0.0
        d: 0.0
    car_base_front_left_wheel:
        p: 1.0
        i: 0.0
        d: 0.0
    car_base_front_right_wheel:
        p: 1.0
        i: 0.0
        d: 0.0
```

