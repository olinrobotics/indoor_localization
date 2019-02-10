# indoor_localization
**A ROS Package using Apriltags & IMU to Estimate Pose Indoors**

This package combines the `usb_cam`, `apriltags2_ros`, `phidgets_imu`, and
`robot_pose_ekf` packages to produce a robot pose estimation using visual
odometry through apriltags and inertial odometry from a phidgets IMU.

<img src="https://lh3.googleusercontent.com/m0Ykfy91ntdrElv0zQsmRbcyToA7B030SjSNDUEAqF0V-TBBp22sIONzeZSk9cf4XrJ1rSnGme0l9_Z7hL6ZK4JieUNf8Jmu4OVROjuCXHxnrPAlGvGXjvmVJRl8bfSSRRRzfeOn4YTmzr-HxJKfPZ_eo9RTPrdWHqpM87-ZoKEeIzHj6c-Mz17NlHR3Gi6f0j8pNRpp3LedLFIY15a9Odvi7bs8JAz8CVMDGixeChgzR0LcyFUoK1xnqowSGZK0Hcvx5KWZW5yL515DFHWBDlUDOvmA-IvYPtmNwv6eiA1CNWzZJSmzTXt5UjhHRuGFL4ZBLSNoZblCYSUpSIqxMlhHmIDXHKIABUolg_7cywyT4l_PwBQYS90w-nZedjmBhcVEtoOIctdRgbj88T_p9pWOcwVj2URV0I5JOv4vrze91rM07283deZnWH4CRVRvMlT1rD2ezLSd5DZ9sPp0UfMozmY82_mI8W3wPCsLI9qJct2tZL6U4XnamNfFQkn8oCoqXSlOjz56Kj6wjtlg-0QH_ISbcpkyHYgpIojW3ydITKfMpKTf1nEuEcX663rC8DVna_pQXN3B60SH9cZmgCaaheox8Cp8uCgRI-_mkWiZvvzeDTObAJkVUvxnTR_5IxG5EkRrJJtq-N0VeSB-Xuo8x6Ux4W4=w1279-h959-no" width=300/>

_Image 1: example development platform with Phidget IMU and Webcam_

## documentation

### Apriltag Setup

1. Print out 17.5 in * 17.5 in tags with a pixel-width border around them from the 36h11 april tag set ([link](https://github.com/AprilRobotics/apriltag-imgs). The file used in testing is included in the repository as `ceilingtag.ai`([link](https://github.com/olinrobotics/indoor_localization/blob/master/ceilingtag.ai)).

2. Place tags on ceiling tiles above the area in which the platform will operate. 

* Placement is limited to blank ceiling tiles that can be fully removed, as successfully attaching the tags requires taping to the backside of the tiles. All tags must be placed in line with a single coordinate system. 
* In AC227 (as of Spring 2019), the tags are oriented with the x-axis pointed away from the doorway and the y-axis pointed towards the rear of the room. 

<img src="https://github.com/olinrobotics/learning-resources/blob/kalman/kalman_filter/images/full_tags.jpg" width=300/>

_Image 2: example of ceiling tile-mounted april tags_

### Apriltag Calibration

Follow the instructions for apriltag bundle calibration ([link](http://wiki.ros.org/apriltags2_ros/Tutorials/Bundle%20calibration)). 

* Ensure that you measure the tags that you have printed, as the printer may not recreate them in your specified size. 
* After running the rosbag command, make sure that you move the resulting .bag file into the correct folder such that the Matlab script can find it.
* In step 2, when running the Matlab script, if you receive an error saying that Matlab cannot find the file specified, make sure that the names match up between the script and the file.
* Use the output from the file to update `indoor_localization/config/apriltags.yaml`.

### Camera Calibration

Follow the instructions for monocular camera calibration ([link](http://wiki.ros.org/camera_calibration/Tutorials/MonocularCalibration)).

* Upon creating the .yml file in step 7, move the file to `indoor_localization/camera_info/<camera_name.yml>`, Then update the `camera_info_url` parameter in `camera.launch`. 
* The image_rect node is already launched in `camera.launch`, so you don't have to worry about image rectification.

### Authors

This package was built by Connor Novak (20') and Kawin Nikomborirak (21') for
the Ground Robotic Autonomous Vehicle Laboratory
([link](https://github.com/olinrobotics/gravl/wiki)).
