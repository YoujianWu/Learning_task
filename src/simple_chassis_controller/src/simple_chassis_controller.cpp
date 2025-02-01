#include "simple_chassis_controller/simple_chassis_controller.h"
#include <pluginlib/class_list_macros.hpp>

namespace simple_chassis_controller
{
bool SimpleChassisController::init(hardware_interface::EffortJointInterface* effort_joint_interface,
                                   ros::NodeHandle& root_nh, ros::NodeHandle& controller_nh)
{
  joint_[LF] = effort_joint_interface->getHandle("left_front_wheel_joint");
  joint_[RF] = effort_joint_interface->getHandle("right_front_wheel_joint");
  joint_[LB] = effort_joint_interface->getHandle("left_back_wheel_joint");
  joint_[RB] = effort_joint_interface->getHandle("right_back_wheel_joint");

  return true;
}

void SimpleChassisController::update(const ros::Time& time, const ros::Duration& period)
{
  ROS_INFO("update");
  double tau = 0.002;  // torque
  // NOTE: DON'T COPY THESE NAIVE TESTING CODES !!! USE INVERSE KINEMATICS !!!
  // NOTE: DON'T COPY THESE NAIVE TESTING CODES !!! USE INVERSE KINEMATICS !!!
  // NOTE: DON'T COPY THESE NAIVE TESTING CODES !!! USE INVERSE KINEMATICS !!!
  joint_[LF].setCommand(tau);
  joint_[RF].setCommand(tau);
  joint_[LB].setCommand(tau);
  joint_[RB].setCommand(tau);
}

PLUGINLIB_EXPORT_CLASS(simple_chassis_controller::SimpleChassisController, controller_interface::ControllerBase)
}  // namespace simple_chassis_controller
