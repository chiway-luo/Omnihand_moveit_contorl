cmake_minimum_required(VERSION 3.13)
project(omnihand_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
# find dependencies
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_typesupport_cpp REQUIRED)
find_package(rosidl_typesupport_fastrtps_cpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(omnihand_node_msgs REQUIRED)

# Use the official prebuilt SDK copied directly into this ROS package.  The SDK
# is never built here, and no path outside omnihand_node is required.
set(OMNIHAND_SDK_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(OMNIHAND_SDK_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

foreach(required_sdk_file
    "libomnihand.so"
    "libomnihand.so.1"
    "libomnihand.so.1.1.8"
    "libusbcanfd.so"
    "libusbcanfd.so.1"
    "libusbcanfd.so.1.0.12"
    "libCANFDNET.so"
    "libcanbus.so"
    "libusb-1.0.so"
    "libusb-1.0.so.0"
    "libusb-1.0.so.0.3.0")
  if(NOT EXISTS "${OMNIHAND_SDK_LIB_DIR}/${required_sdk_file}")
    message(FATAL_ERROR
      "Missing packaged OmniHand SDK library: ${OMNIHAND_SDK_LIB_DIR}/${required_sdk_file}")
  endif()
endforeach()

if(NOT EXISTS "${OMNIHAND_SDK_INCLUDE_DIR}/omnihand/omnihand_2025.h")
  message(FATAL_ERROR
    "Missing packaged OmniHand SDK headers: ${OMNIHAND_SDK_INCLUDE_DIR}/omnihand")
endif()

add_library(omnihand_sdk SHARED IMPORTED)
set_target_properties(omnihand_sdk PROPERTIES
  IMPORTED_LOCATION "${OMNIHAND_SDK_LIB_DIR}/libomnihand.so"
  INTERFACE_INCLUDE_DIRECTORIES "${OMNIHAND_SDK_INCLUDE_DIR}")

add_executable(hand_node src/main.cpp src/hand_node.cpp)


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
)


# The imported target also supplies the SDK include directory.  Keep
# the plain signature because ament_target_dependencies() uses it on Humble.
target_link_libraries(hand_node omnihand_sdk)

# Build against the package-local SDK.  At install time, keep the complete SDK
# runtime in a node-private directory so its bundled libusb cannot shadow the
# system library for unrelated ROS processes.  Old-style DT_RPATH is intentional
# here: it also covers libusbcanfd's indirect dependency on the bundled libusb.
target_link_options(hand_node PRIVATE "LINKER:--disable-new-dtags")
set_target_properties(hand_node PROPERTIES
  BUILD_RPATH "${OMNIHAND_SDK_LIB_DIR}"
  INSTALL_RPATH "\$ORIGIN")

install(TARGETS hand_node
  DESTINATION lib/${PROJECT_NAME})

# Preserve the complete official runtime closure and its versioned symlinks.
install(DIRECTORY "${OMNIHAND_SDK_LIB_DIR}/"
  DESTINATION lib/${PROJECT_NAME}
  USE_SOURCE_PERMISSIONS)

install(DIRECTORY "${OMNIHAND_SDK_INCLUDE_DIR}/"
  DESTINATION include)

install(FILES
  "${CMAKE_CURRENT_SOURCE_DIR}/sdk/VERSION"
  "${CMAKE_CURRENT_SOURCE_DIR}/sdk/README.upstream.md"
  "${CMAKE_CURRENT_SOURCE_DIR}/sdk/UPSTREAM.md"
  DESTINATION share/${PROJECT_NAME}/sdk)

ament_export_include_directories(include)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # The packaged SDK headers are immutable third-party code and keep upstream style.
  file(GLOB_RECURSE OMNIHAND_SDK_HEADER_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/include/omnihand/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/omnihand_server/*.h")
  set(AMENT_LINT_AUTO_FILE_EXCLUDE ${OMNIHAND_SDK_HEADER_FILES})
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
