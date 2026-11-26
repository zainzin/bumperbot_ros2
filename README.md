# bumperbot_ros2

## Build
colcon build --cmake-args -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
source install/setup.bash

## Run
ros2 launch bumperbot_description gazebo.launch.py
