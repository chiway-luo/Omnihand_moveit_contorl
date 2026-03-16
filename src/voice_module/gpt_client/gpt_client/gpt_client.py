import json
import rclpy
from rclpy.node import Node
from openai import OpenAI
import os
from pydantic import BaseModel
from pydantic import Field
from typing import Literal
from omnihand_node_msgs.srv import SetHandShape
from std_msgs.msg import String

"""
    需求:调用openai接口,根据语音输入和预设的手型数据,向服务端发送手型变换请求
    流程:
        1.包含头文件
        2.初始化ros2客户端
        3.自定义节点类
            3-1创建ai客户端
            3-2创建ros2客户端(set_shape)
            3-3创建话题订阅方,监听语音模块的输出,并在回调函数中调用ai客户端发送请求,获取手型变换结果后调用ros2客户端发送请求
        4.调用spin函数,并传入节点对象指针
        5.释放资源

    目前没有实现语音模块的编写
    使用 ros2 topic pub /text std_msgs/String "data: '给我的好朋友竖一个中指'"   来模拟语音模块的输出
"""


class HandPoseReply(BaseModel):
    hand_shape: Literal["default","catch","full","joke","ok","point"] = Field(
        description="必须从给定手型列表中选择一个"
    )
    interaction_text: str = Field(
        description="与用户交互时输出的一段文本"
    )

class GptClient(Node):
    def __init__(self,str1):
        super().__init__(str1)
        self.openai_client = OpenAI(#创建deepseek客户端对象
            api_key=os.getenv("DEEPSEEK_API_KEY"),
            base_url="https://api.deepseek.com",
        )
        self.client_ = self.create_client(SetHandShape,"hand_shape/set_shape")  # 创建ROS2客户端
        self.sub_ = self.create_subscription(String, "/text", self.voice_callback, 10)  # 创建订阅者
    
    
    #发送请求函数
    def send_request(self, msg: str):
        response = self.openai_client.chat.completions.create(  # 发送请求（JSON模式）
            model="deepseek-chat",
            messages=[
                {"role": "system", "content": "根据用户意图选择一个手型，并生成对应的交互文本。"
                 "请严格以JSON格式回复，包含hand_shape和interaction_text两个字段。"
                 "hand_shape只能从以下选项中选一个: default, catch, full, joke, ok, point"},
                {"role": "user", "content": msg + "/请告诉我应该使用哪个手型，并生成一段与用户交互的文本。"},
            ],
            response_format={"type": "json_object"},
        )
        raw = response.choices[0].message.content  # 获取JSON字符串
        result = HandPoseReply(**json.loads(raw))   # 解析为Pydantic模型
        print(result.hand_shape)
        print(result.interaction_text)
        if not self.client_.wait_for_service(timeout_sec=5.0):  # 等待服务可用
            self.get_logger().error("服务方链接失败")
            return 
        self.client_.call_async(SetHandShape.Request(shape=result.hand_shape))  # 发送请求
        return

    def voice_callback(self, msg: String):
        self.send_request(msg.data)
        rclpy.spin_once(self)  # 处理一次ROS2事件循环


def main():
    # 初始化ros2客户端
    rclpy.init()

    # 创建节点并发送一次请求
    node = GptClient("gptclient")
    node.send_request("竖一个中指")

    # 释放资源
    rclpy.shutdown()

if __name__ == "__main__":
    main()