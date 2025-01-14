# URDF

URDF:统一机器人描述格式，是一个XML语法框架下用来描述机器人的语言格式。

将 URDF 文件引入 Gazebo 中，Gazebo 根据文件内容解析出机器人各个部分的信息，并在虚拟环境中创建出相应的三维模型。这个过程包括了**物理属性的设定**以及**动力学特性**。此外，URDF 还支持通过插件机制加载外部资源，比如视觉模型、传感器数据流等，使得机器人在模拟中更加真实和动态。

当 Gazebo加载 URDF 文件时，URDF 内容首先会转换为 SDFormat，然后再由Gazebo 处理。URDF 到 SDFormat 的转换通常会自动发生，也就是我们无需观察生成的 SDFormat 文件。为了诊断转换过程中可能出现的任何问题，这条命令可以把 URDF 文件转换为用户可以检查的 SDFormat：

```
gz sdf -p <path to urdf file>
```

## robot

机器人描述文件中的根元素必须是**robot** ，所有其他元素必须封装在其中。

元素：<link>  <joint>   <transmission>  <gazebo>

example:

```xml
<robot name="pr2">
  <!-- pr2 robot links and joints and more -->
</robot>
```

## link

link 元素描述了具有惯性、视觉特征和碰撞属性的刚体，每一个link需要包含inertial、visual、collision三个标签

##### tips:

对于geometry，它是可视化对象的形状，可以是下面的其中一种：

**box**:矩形，元素包含长、宽、高

**cylinder**:圆柱体，元素包含半径、长度

**sphere**:球体，元素包含半径

**mesh**:网格，由文件决定，同时提供 scale ，用于界定其边界。推荐使用 Collada .dae 文件， 也支持.stl文件，但必须为一个本地文件。格式：mesh filename="package://<packagename>/<path>",scale是缩放，不必须

## joint

关节元素描述了关节的运动学和动力学，并指定了关节的安全极限

##### tips:

两个必要元素name和type。其中type要正确选择：**转动关节**: continous 是没有限位的转动关节，可以绕单轴无限旋转 revolute是有限位的转动关节，有一定的旋转角度限制；**平动关节**: prismatic 是沿某一轴滑动的关节；**固定关节**: fixed 是不允许运动的关节

![photo](../imgs/car.png)
