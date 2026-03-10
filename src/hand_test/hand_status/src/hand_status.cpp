#include "rclcpp/rclcpp.hpp"


/*
    需求:接收底层驱动发送的关节角数据,接收话题/agihand/omnihand/left/joint_states
    
*/

using namespace std::chrono_literals; //使用时间命名空间
using namespace std::placeholders; //占位符命名空间

class HandStatus :public rclcpp::Node{
public:
    HandStatus(std::string str1):Node(str1){
        RCLCPP_INFO(this->get_logger(),"namesapce:  node: %s 节点创建成功",str1.c_str());

    }

private:

    //回调函数
    void callback_this(){
    }
};

int main(int argc, char * argv[])
{
    //初始化ros2客户端
    rclcpp::init(argc,argv);

    //调用spin函数,使用自定义类对象指针
    rclcpp::spin(std::make_shared<HandStatus>("HandStatus_node_cpp"));//node_name, (namespace可选)

    //释放资源
    rclcpp::shutdown();
    return 0;
}