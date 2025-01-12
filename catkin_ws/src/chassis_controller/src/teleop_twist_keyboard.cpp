//
// Created by wiselook on 2024/12/12.
//

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <cstdio>
#include <csignal>
#include <unistd.h>
#include <termios.h>

#include <map>

std::string msg = "Reading from the keyboard  and Publishing to Twist!\n"
                  "---------------------------\n"
                  "Moving around:\n"
                  "q    w    e\n"
                  "a    s    d\n"
                  "z    x    c\n"
                  "\n"
                  "CTRL-C then press any key to quit\n";

// Map for movement keys
std::map<char, std::vector<float>> moveBindings{
  { 'q', { 1, 1, 0 } },   { 'w', { 1, 0, 0 } },     { 'e', { 1, -1, 0 } }, { 'a', { 0, 0, 1 } },
  { 's', { 0, 0, 0 } },   { 'd', { 0, 0, -1 } },    { 'z', { -1, 1, 0 } }, { 'x', { -1, 0, 0 } },
  { 'c', { -1, -1, 0 } }, { 'Q', { 1.9, 1.9, 0 } }, { 'W', { 1, 0, 0 } },  { 'E', { 1, -1, 0 } },
  { 'A', { 0, 1, 0 } },   { 'S', { 0, 0, 0 } },     { 'D', { 0, -1, 0 } }, { 'Z', { -1, 1, 0 } },
  { 'X', { -1, 0, 0 } },  { 'C', { -1, -1, 0 } },   { 'f', { 0, 0, 1 } },  { 'g', { 0, 0, -1 } },
  { 'F', { 0, 0, 1 } },   { 'G', { 0, 0, -1 } },
};

// For non-blocking keyboard inputs
int getch(void)
{
  int ch;
  struct termios oldt;
  struct termios newt;

  // Store old settings, and copy to new settings
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;

  // Make required changes and apply the settings
  newt.c_lflag &= ~(ICANON | ECHO);
  newt.c_iflag |= IGNBRK;
  newt.c_iflag &= ~(INLCR | ICRNL | IXON | IXOFF);
  newt.c_lflag &= ~(ICANON | ECHO | ECHOK | ECHOE | ECHONL | IEXTEN);
  newt.c_lflag |= ISIG;
  newt.c_cc[VMIN] = 1;
  newt.c_cc[VTIME] = 0;
  tcsetattr(fileno(stdin), TCSANOW, &newt);

  // Get the current character
  ch = getchar();

  // Reapply old settings
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

  return ch;
}

int main(int argc, char** argv)
{
  // teleop_twist_keyboard node init.
  ros::init(argc, argv, "teleop_twist_keyboard");
  ros::NodeHandle nh;

  // Init var
  double x(0), y(0), th(0);
  char key(' ');
  double speed = 4.0;
  double turn = 2.5;

  printf("%s", msg.c_str());
  printf("currently:\tspeed %.2f\tturn %.2f", speed, turn);

  // cmd_vel publisher init
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1);

  geometry_msgs::Twist twist;

  while (ros::ok())
  {
    // Get the pressed key
    key = static_cast<char>(getch());

    // If the key corresponds to a key in moveBindings
    if (moveBindings.count(key) == 1)
    {
      // Grab the direction data
      x = moveBindings[key][0];
      y = moveBindings[key][1];
      th = moveBindings[key][2];
    }
    // increase/decrease speed or turn
    else if (key == 'j' || key == 'J' || key == 'k' || key == 'K')
    {
      switch (key)
      {
        case 'j':
          speed *= 0.9;
          break;
        case 'J':
          speed *= 1.1;
          break;
        case 'k':
          turn *= 0.9;
          break;
        case 'K':
          turn *= 1.1;
          break;
      }
      printf("currently:  speed %.2f\tturn %.2f\n", speed, turn);
    }
    // stop
    else
    {
      x = 0;
      y = 0;
      th = 0;
    }

    // Update the Twist message
    twist.linear.x = x * speed;
    twist.linear.y = y * speed;
    twist.linear.z = 0;

    twist.angular.x = 0;
    twist.angular.y = 0;
    twist.angular.z = th * turn;

    // Publish cmd_vel
    cmd_vel_pub.publish(twist);
    ros::spinOnce();
  }
  return 0;
}
