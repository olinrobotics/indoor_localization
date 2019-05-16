#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <tf/transform_datatypes.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "tf_to_odom");
  ros::NodeHandle node;
  ros::Publisher odom_pub = node.advertise<nav_msgs::Odometry>("/gps/odom", 10);
  ros::Rate rate(100);
  tf2_ros::Buffer tfBuffer;
  tf2_ros::TransformListener tfListener(tfBuffer);

  while (node.ok()) {
    geometry_msgs::TransformStamped transformStamped;

    try {
      transformStamped =
          tfBuffer.lookupTransform("board_bundle", "tag_cam", ros::Time(0));
    } catch (tf2::TransformException &ex) {
      ROS_WARN("%s", ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }

    geometry_msgs::Twist vel_msg;
    nav_msgs::Odometry odom;
    odom.header.stamp = ros::Time::now();
    odom.pose.pose.position.x = transformStamped.transform.translation.x;
    odom.pose.pose.position.y = transformStamped.transform.translation.y;
    odom.pose.pose.position.z = -transformStamped.transform.translation.z;

    tf::Quaternion q1(transformStamped.transform.rotation.x,
                      transformStamped.transform.rotation.y,
                      transformStamped.transform.rotation.z,
                      transformStamped.transform.rotation.w);
    tf::Matrix3x3 m(q1);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    tf2::Quaternion q2;
    q2.setRPY(pitch, roll, -yaw + 3.14159);
    q2.normalize();

    odom.pose.pose.orientation.w = q2[3];
    odom.pose.pose.orientation.x = q2[0];
    odom.pose.pose.orientation.y = q2[1];
    odom.pose.pose.orientation.z = q2[2];
    odom.header.frame_id = "map";
    odom.child_frame_id = "tag_cam";

    odom_pub.publish(odom);

    rate.sleep();
  }
}
