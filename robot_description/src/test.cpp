//
// Created by ham on 2025/1/15.
//

#include "test/test.h"
#include <pluginlib/class_list_macros.hpp>
//基于基类 controller_interface::ControllerBase 创建衍生类 test_controller::TestController,

namespace test_controller
{
    bool TestController::init(hardware_interface::EffortJointInterface* effort_joint_interface,
                                       ros::NodeHandle& n)
    {
//        base_link2${wheel_name}_wheel用的是joint的名字
        front_left_joint_  = effort_joint_interface->getHandle("base_link2front_left_wheel");
        front_right_joint_ = effort_joint_interface->getHandle("base_link2front_right_wheel");
        back_left_joint_   = effort_joint_interface->getHandle("base_link2back_left_wheel");
        back_right_joint_  = effort_joint_interface->getHandle("base_link2back_right_wheel");
        return true;
    }

    void TestController::update(const ros::Time& time, const ros::Duration& period)
    {
        double tau = 0.001;  // torque
        front_left_joint_.setCommand (tau);
        front_right_joint_.setCommand(tau);
        back_left_joint_.setCommand  (tau);
        back_right_joint_.setCommand (tau);
    }
//  导出注册插件，参数一：子类， 参数二：父类，
//  记得要在 cmakelist 文件中添加库：add_library
//  使用controllermanger动态加载控制器
    PLUGINLIB_EXPORT_CLASS(test_controller::TestController, controller_interface::ControllerBase)
}
