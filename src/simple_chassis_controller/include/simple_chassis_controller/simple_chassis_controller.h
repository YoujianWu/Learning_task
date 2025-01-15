#pragma once

#include <controller_interface/controller.h>
#include <hardware_interface/joint_command_interface.h>

namespace simple_chassis_controller
{
const int LF{ 0 }, RF{ 1 }, LB{ 2 }, RB{ 3 };

class SimpleChassisController : public controller_interface::Controller<hardware_interface::EffortJointInterface>
{
public:
  SimpleChassisController() : joint_(4){};
  ~SimpleChassisController() override = default;

  bool init(hardware_interface::EffortJointInterface* effort_joint_interface, ros::NodeHandle& root_nh,
            ros::NodeHandle& controller_nh) override;

  void update(const ros::Time& time, const ros::Duration& period) override;

private:
  int state_{};
  ros::Time last_change_;
  std::vector<hardware_interface::JointHandle> joint_;
};
}  //  namespace simple_chassis_controller
