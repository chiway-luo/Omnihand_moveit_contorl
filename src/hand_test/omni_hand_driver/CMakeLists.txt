cmake_minimum_required(VERSION 3.8)
project(omni_hand_driver)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

# SDK 预构建安装路径
set(OMNIHAND_SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../Omnihand-2025-SDK/build/install")

# 创建 IMPORTED 库目标
add_library(omnihand2025 SHARED IMPORTED)
set_target_properties(omnihand2025 PROPERTIES
  IMPORTED_LOCATION "${OMNIHAND_SDK_DIR}/lib/libomnihand2025.so"
  INTERFACE_INCLUDE_DIRECTORIES "${OMNIHAND_SDK_DIR}/include"
)

# 安装 SDK 头文件
install(DIRECTORY ${OMNIHAND_SDK_DIR}/include/
  DESTINATION include/omni_hand_driver)

# 安装 SDK 共享库
install(FILES
  ${OMNIHAND_SDK_DIR}/lib/libomnihand2025.so
  ${OMNIHAND_SDK_DIR}/lib/libusbcanfd.so
  DESTINATION lib)

# 安装 libusbcanfd 的版本号符号链接
install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink
  libusbcanfd.so \$ENV{DESTDIR}\${CMAKE_INSTALL_PREFIX}/lib/libusbcanfd.so.1.0.10)")

# 导出 CMake 配置，让下游包通过 find_package(omni_hand_driver) 找到库
ament_export_include_directories(include/omni_hand_driver)
ament_export_libraries(omnihand2025 usbcanfd)

ament_package()
