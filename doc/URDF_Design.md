# URDF Design

## Link与Joint区别

- Link可见Joint不可见
- Joint=关节，链接两个Link，一个parent link一个child link

## Collision
碰撞箱，模型较简单时与visual一致，复杂时简化collision

## Xacro

- Xacro为urdf提供模板（宏），方便参数修改与减少代码量

## Gazebo_ros_control

在urdff加上下面这段代码使用gazebo_ros_control插件，不然控制器加不进去

```xml
<gazebo>
    <plugin name="gazebo_ros_control" filename="libgazebo_ros_control.so">
        <robotNamespace>/</robotNamespace>
    </plugin>
</gazebo>
```
