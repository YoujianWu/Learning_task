# 搭建机器人模型

## 建模：

### urdf：

-语法：

```text
<robot name> （选填）机器人
    <link name> （必填）连杆
        <inertial>  （选填）惯性特性
            <origin xyz="0 0 0" rpy="0 0 0" />   （选填）惯性参考系的参考坐标，定义在重心处；xyz为坐标轴的平移量；rpy为旋转量
            <mass value />                       （必填）质量
            <inertia ixx iyy izz ixy ixz iyz />  （必填）惯性张量：描述刚体转动惯性，iaa为对a轴的转动惯量，iab为惯性积
        </inertial>
        <visual name>                        （必填）可视化
            <origin xyz="0 0 0" rpy="0 0 0" />  （选填）可视化
            <geometry>                          （必填）几何描述，可以用stl文件构建复杂的模型
                <box size />                        长方体
                <cylinder radius length />          圆柱体
                <sphere radius />                   球
                <mesh filename scale="1" />         网格，由本地文件决定，可以是collada.dae或.stl
            </geometry>
            <material name>                  （选填）可视化材料
                <color rgba="0.5 0.5 0.5 1" />  （选填）颜色，rgba：rbg和透明度alpha，范围[0, 1]
                <texture filename />            （选填）材料属性，文件决定
            </material>
        </visual>
        <collision name>                   （选填）碰撞箱，用于简化物理模型
            <origin xyz="0 0 0" rpy="0 0 0" />    （选填）碰撞组件相对于连杆的参考坐标系
            <geometry>                            （必填）几何描述 
                <box size />
                <cylinder radius length />
                <sphere radius />
                <mesh filename scale="1" />
            </geometry>
        </collision>
    </link>
    
    <joint name type>                      （选填）关节
        <origin xyz="0 0 0" rpy="0 0 0" />       （选填）是从父连杆到子连杆的转换，默认全为0
        <parent link />                          （必填）父连杆，一个父连杆可以有多个子连杆
        <child link />                           （必填）子连杆，一个子连杆只能有一个父连杆  
        <axis xyz="1 0 0" />                     （选填）关节轴，旋转关节、平移关节平面关节都有着不同的关节轴
        <calibration rising falling/>            （选填）joint的参考位置，rising为关节正方向运动时，参考位置触发上升沿，falling则为触发下降沿
        <dynamics damping="0" friction="0" />    （选填）动力学模型，用于仿真，damping为关节阻尼值，friction为关节的物理静摩擦值
        <limit lower upper effort velocity />    （仅旋转和棱柱关节需要）限位，lower、upper为上下限，effort为最大力，velocity为最大速度
        <mimic joint multiplier="1" offset="0" />（选填）此标记用于指定定义的关节模拟另一个现有关节
        <safety_controller soft_lower_limit="0" soft_upper_limit="0" k_position="0" k_velocity="0" />
                                                 （选填）soft_lower（upper）_limit（可选，默认为 0）为安全控制器开始限制关节位置的下（上）关节边界，
                                                       k_position（可选，默认为 0）指定位置和速度限制之间关系的属性。
                                                       k_velocity（必需）指定 effort 和 velocity limits 之间关系的属性。
    </joint>
</robot>
```

## 加载控制器到机器人模型里



