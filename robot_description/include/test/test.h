//
// Created by ham on 2025/1/15.
//

#ifndef ROBOT_DESCRIPTION_TEST_H
#define ROBOT_DESCRIPTION_TEST_H

#include <controller_interface/controller.h>
#include <hardware_interface/joint_command_interface.h>

namespace test_controller
{
    class TestController : public controller_interface::Controller<hardware_interface::EffortJointInterface>
    {
    public:
        //  构造函数
        TestController() = default;
        //  析枸函数
        ~TestController() override = default;

//        bool init(hardware_interface::EffortJointInterface* effort_joint_interface, ros::NodeHandle& root_nh,
//                  ros::NodeHandle& controller_nh) override;
        bool init(hardware_interface::EffortJointInterface* effort_joint_interface, ros::NodeHandle& n) override;
        void update(const ros::Time& time, const ros::Duration& period) override;

        hardware_interface::JointHandle front_left_joint_, front_right_joint_, back_left_joint_, back_right_joint_;

    private:
        int state_{};
        ros::Time last_change_;
    };
}

#endif
