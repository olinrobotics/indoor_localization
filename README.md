# indoor_localization
**A ROS Package using Apriltags & IMU to Estimate Pose Indoors**

This package combines the `usb_cam`, `apriltags2_ros`, `phidgets_imu`, and
`robot_pose_ekf` packages to produce a robot pose estimation using visual
odometry through apriltags and inertial odometry from a phidgets IMU.

## documentation

### Apriltag Setup

1. Print out 17.5 in * 17.5 in tags with a pixel-width border around them from the 36h11 april tag set ([link](https://github.com/AprilRobotics/apriltag-imgs)]
2. Place tags on ceiling tiles above the area in which the platform will operate. Placement is limited to blank ceiling tiles that can be fully removed, as successfully attaching the tags requires taping to the backside of the tiles. All tags must be placed in  with the x-axis pointed away from the doorway and the y-axis pointed towards the rear of the room. Many ceiling tiles cannot be fully removed due to piping.
<img src="https://github.com/olinrobotics/learning-resources/blob/kalman/kalman_filter/images/full_tags.jpg" width=250/>

### Apriltag Calibration

Follow the instructions for apriltag bundle calibration
([link](http://wiki.ros.org/apriltags2_ros/Tutorials/Bundle%20calibration)). In
step 2, when running the Matlab script, if you receive an error saying that
Matlab cannot find the file specified, make sure that the names match up between
the script and the file. Use the output from the file to update
`indoor_localization/config/apriltags.yaml`.

### Camera Calibration

Follow the instructions for monocular camera calibration
([link](http://wiki.ros.org/camera_calibration/Tutorials/MonocularCalibration)).
Upon creating the .yml file in step 7, move the file to `indoor_localization/
camera_info/<camera_name.yml>`, Then update the `camera_info_url` parameter in
`camera.launch`. The image_rect node is already launched in `camera.launch`, so
you don't have to worry about image rectification.

### Authors

This package was built by Connor Novak (20') and Kawin Nikomborirak (21') for
the Ground Robotic Autonomous Vehicle Laboratory
([link](https://github.com/olinrobotics/gravl/wiki)).
