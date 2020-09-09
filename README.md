# ros-bloom-test
A simple ROS workspace to test ROS bloom with packages dependent on other packages in the same workspace.

The purpose of this repository is to test bloom-generate to create debian packages when a package depends on another package of the same workspace.

## Contents
The repository contains two simple ROS packages: my_package_msgs and my_package.

my_pacakge_msgs contains the definition of a very simple "Counter" message and my_pacakge contains a node that publishes a "my_package_msgs/Counter" message once per second.

## Usage
To test this repository follow the instructions on how to install ros and create an empty workspace. Then execute the following commands:

- cd ~/catkin_ws/src
- git clone https://github.com/MartinPeris/ros-bloom-test.git
- rospack profile
- cd ros-bloom-test/my_package
- bloom-generate rosdebian

The output should be something similar to:

```
==> Generating debs for ubuntu:xenial for package(s) ['my_package']
No homepage set, defaulting to ''
Could not resolve rosdep key 'my_package_msgs'
Try to resolve the problem with rosdep and then continue.
Continue [Y/n]? 
```
