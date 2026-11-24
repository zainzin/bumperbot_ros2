cmake_minimum_required(VERSION 3.20)
project(bumperbot_cpp_examples)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rcl_interfaces REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(simple_publisher src/simple_publisher.cpp)
add_executable(simple_subscriber src/simple_subscriber.cpp)
add_executable(simple_parameter src/simple_parameter.cpp)

target_link_libraries(simple_publisher PRIVATE rclcpp::rclcpp std_msgs::std_msgs)
target_link_libraries(simple_subscriber PRIVATE rclcpp::rclcpp std_msgs::std_msgs)
target_link_libraries(simple_parameter PRIVATE rclcpp::rclcpp rcl_interfaces::rcl_interfaces)

install(TARGETS
        simple_publisher
        simple_subscriber
        simple_parameter
        DESTINATION lib/${PROJECT_NAME}
)

ament_package()
