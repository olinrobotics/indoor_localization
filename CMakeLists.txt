cmake_minimum_required (VERSION 2.8.3)
project (indoor_localization)

find_package (catkin REQUIRED COMPONENTS
  roscpp
  nav_msgs
  geometry_msgs
  tf2_ros
  )

catkin_package (CATKIN_DEPENDS)
include_directories( ${catkin_INCLUDE_DIRS})

add_executable (tf_to_odom src/publish_tf_as_odom)
target_link_libraries (tf_to_odom ${catkin_LIBRARIES})
