ARG ROS_DISTRO=melodic

FROM ros:$ROS_DISTRO

MAINTAINER Kawin Nikomborirak concavemail@gmail.com

RUN bash -c "mkdir -p /catkin_ws/src/koda"
COPY . /catkin_ws/src/koda
COPY .rosinstall /catkin_ws/src/.rosinstall

RUN bash -c \
        'apt-get update \
        && wstool update -t /catkin_ws/src \
        && rosdep update \
        && source /opt/ros/$ROS_DISTRO/setup.bash \
        && rosdep install -iry --from-paths /catkin_ws/src \
        && cd /catkin_ws \
        && catkin_make \
        && echo "source /catkin_ws/devel/setup.bash" >> /root/.bashrc \
        && apt-get install -y tmux \
        && apt-get install -y vim \
        '
