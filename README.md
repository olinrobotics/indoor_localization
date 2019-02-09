# indoor_localization
**A ROS Package using Apriltags & IMU to Estimate Pose Indoors**

This package combines the `usb_cam`, `apriltags2_ros`, `phidgets_imu`, and
`robot_pose_ekf` packages to produce a robot pose estimation using visual
odometry through apriltags and inertial odometry from a phidgets IMU.

## documentation

### Apriltag Setup

TODO: Coming soon.

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
