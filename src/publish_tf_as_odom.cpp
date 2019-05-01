#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>

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
          tfBuffer.lookupTransform("ac226_bundle", "tag_cam", ros::Time(0));
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
    odom.pose.pose.position.z = transformStamped.transform.translation.z;
    odom.pose.pose.orientation.w = transformStamped.transform.rotation.w;
    odom.pose.pose.orientation.x = transformStamped.transform.rotation.x;
    odom.pose.pose.orientation.y = transformStamped.transform.rotation.y;
    odom.pose.pose.orientation.z = transformStamped.transform.rotation.z;
    odom.header.frame_id = "april_tags";
    odom.child_frame_id = "tag_cam";

    odom_pub.publish(odom);

    rate.sleep();
  }
}
