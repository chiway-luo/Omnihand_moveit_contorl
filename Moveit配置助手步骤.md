# Moveit配置助手 使用步骤

[moveit包官方构建流程](https://moveit.picknik.ai/main/doc/examples/setup_assistant/setup_assistant_tutorial.html)

## 配置依赖
- 安装moveit
```bash
sudo apt install ros-<ros-distro>-moveit
```

## 创建description功能包

- 开始构建之前,需要将sdk中的urdf文件夹复制到任意一个功能包中,并修改其中的urdf文件,将其中的mesh文件路径改为当前功能包的路径
......
- 详细过程不再赘述,可以直接使用我配置好的description包

- 当前运行模型的碰撞几何与 SRDF 已根据实际 O10 模型完成调校。重新生成配置时应以当前 `hand_description` 为基准，不要机械替换碰撞几何，也不要批量关闭自碰撞。

## 配置moveit配置包
> 如果大家不愿意手动配置moveit配置包,也可以直接使用我已经配置好的moveit配置包

- 启动moveit配置助手
```bash
ros2 launch moveit_setup_assistant setup_assistant.launch.py
```
- 在配置助手中选择创建新的moveit配置包
- 选择灵巧手的urdf文件
- 点击加载
- 点击侧边的self-collisions选项,生成自碰撞信息

> 默认保留不同手指之间的碰撞检测。只应基于结构关系和实测证据，禁用相邻或永不碰撞的 link 对。当前 SRDF 额外仅允许 `L_index_dip` 与 `L_thumb_dip` 的 `IntentionalContact`，用于处理 O10 捏合/近接触姿态的起点误判；不要据此关闭其他跨手指碰撞。

> 安全权衡：该 `IntentionalContact` 会让 MoveIt 在整条轨迹中都不再检查这两个末节 link 之间的碰撞，并非只放宽起点的数值容差。规划捏合动作时仍需使用保守目标并在 RViz 中检查轨迹；后续应优先校正碰撞几何，而不是继续增加跨手指豁免。

<img src="image/image_1.png" width="600">

- 配置虚拟关节,将base_link和world连接起来,并设置为固定关节

<img src="image/image_2.png" width="600">

- 配置关节组,根据手指的结构配置关节组,每个手指一个组,再将所有的关节组放到一个总的hand组中

> `hand` 由五个手指子组组成，支持关节空间规划。RViz 出现 `No active joints or end effectors found for group 'hand'` 只表示该组没有可供 6D IK 操作的末端交互标记，不表示规划组无关节或不能规划；目标应通过 MotionPlanning 的关节滑块或手型服务设置，并由半透明目标机器人预览。

<img src="image/image_3.png" width="600">

- 配置默认手势

<img src="image/image_4.png" width="600">

- 定义被动关节

<img src="image/image_5.png" width="600">

- 为ros2_control配置控制器接口,点击添加接口即可

<img src="image/image_6.png" width="600">

- 设置ros2_control控制器,点击自动添加即可

<img src="image/image_7.png" width="600">

- moveit控制器同样设置为自动添加

- 最后点击最下方的生成按钮,生成moveit配置包


## 启动示例程序查看构建效果
> ros2 launch hand_moveit demo.launch.py

当前连接真实灵巧手时使用唯一正式入口：

```bash
ros2 launch hand_control hand_control.launch.py
```

该入口加载的 RViz 配置中 `Goal State Alpha` 为 0.5、`Start State Alpha` 为 0.2。不要同时启动 `hand_test_bag hand_test.launch.py`，否则会争用 `/dev/omnihand_left`。
