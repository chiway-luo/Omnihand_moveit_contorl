/*
 * @Author: huangshiheng@agibot.com
 * @Date: 2025-11-06 14:15:12
 * @LastEditors: huangshiheng
 * @LastEditTime: 2025-11-11 14:49:39
 * @FilePath: omnihand_node/src/main.cpp
 * @Description:
 *
 * Copyright (c) 2025 by huangshiheng@agibot.com, All Rights Reserved.
 */

#include <exception>

#include "rclcpp/rclcpp.hpp"
#include "omnihand_node/hand_node.h"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  try {
    auto left_hand_node = std::make_shared<omnihand::OmniHandProNode>(
      agilink::omnihand::OmniHand2025::kDefaultHandDeviceId,
      agilink::omnihand::HandType::LEFT,
      "/dev/omnihand_left",
      460800);

    // 创建多线程执行器
//     rclcpp::executors::MultiThreadedExecutor executor;

    // 单线程执行器（底层 USB 串口通信需要顺序收发，多线程会导致时序错乱）
    rclcpp::executors::SingleThreadedExecutor executor;

    executor.add_node(left_hand_node);
    executor.spin();
  } catch (const std::exception & error) {
    RCLCPP_FATAL(
      rclcpp::get_logger("omnihand_node"),
      "OmniHand USB node startup failed: %s",
      error.what());
    rclcpp::shutdown();
    return 1;
  }

  rclcpp::shutdown();
  return 0;
}
