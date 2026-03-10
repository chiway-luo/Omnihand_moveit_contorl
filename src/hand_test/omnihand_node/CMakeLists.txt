cmake_minimum_required(VERSION 3.8)
project(omnihand_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(hand_node src/main.cpp src/hand_node.cpp)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_typesupport_cpp REQUIRED)
find_package(rosidl_typesupport_fastrtps_cpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(omnihand_node_msgs REQUIRED)
find_package(omni_hand_driver REQUIRED)

# SDK 需要 C++20
target_compile_features(hand_node PUBLIC c_std_99 cxx_std_20)

# 包含本包头文件
target_include_directories(hand_node PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include)

ament_target_dependencies(
  hand_node
    "rclcpp"
    "std_msgs"
    "rosidl_typesupport_cpp"
    "rosidl_typesupport_fastrtps_cpp"
    "rosidl_default_generators"
    "omnihand_node_msgs"
    "omni_hand_driver"
)

install(TARGETS hand_node
  DESTINATION lib/${PROJECT_NAME})


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

ament_package()
