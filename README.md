# Learning_task
本仓库用来发布DynamicX控制组梯度的学习任务，具体任务安排在tasks文件夹里面，目的是为了帮助梯度队员快速上手并掌握相关知识。

- 禁止copy第三方库来交作业
- 禁止对遇到的问题模棱两可（分清楚各种概念，不会的就要问，多想多问）
- 不会的问题要学会谷歌找解决方法（有方法就试试，不要怕搞坏电脑环境，坏了再说）
- 这个仓库包含了所有成员的学习成果，也可以当作大家的学习笔记仓库，自己搞不懂的概念可以看看别人的笔记，想要上传笔记直接开PR就好，直接联系仓库管理者审核。（也可以自己开一个仓库，自己写点笔记，推上github保存，以后忘了可以回来看。



<
[urdf tag详解](https://zhuanlan.zhihu.com/p/83280676)

[pre-commit](https://rm-control-docs.netlify.app/dev_guide/code_style#pre-commit-%E6%A0%BC%E5%BC%8F%E6%A3%80%E6%9F%A5%E5%99%A8)

在整个过程中，你需要完成的包括但不限于以下任务：

- 使用catkin初始化工作空间和编译代码
- 全程使用github管理自己的代码，有明确commit(使用clion的git操作，不得使用命令行，这里不会可以寻求学长帮助)（为了训练大家的规范能力，按照队里的规范操作）
  - `commit`要具体描述你这次干了什么，不要草草了事，开头要大写，结尾要有结束符；
  - `pr`要在pr的description里面具体描述你的任务效果，pr提交开头要大写。
  - 在每次commit前，使用pre-commit

- 使用.gitignore来隐藏部分没用的文件，不提交它们
- 在 ROS 中，提供了一些URDF文件相关的工具，比如:
  - `check_urdf`命令可以检查复杂的 urdf 文件是否存在语法问题；
  - `urdf_to_graphviz`命令可以查看 urdf 模型结构，显示不同 link 的层级关系。
- 全程自己编写机器人的urdf，并在rviz中检查机器人是否与仿真一致，并加载控制器让自己的机器人运动（不可使用gazebo内置插件，用ros官方提供的插件）
- 要使用Typora记录自己在本任务中学到什么，学习心得，具体讲清楚怎么搭建自己的机器人模型，如何控制自己的机器人运动，pr时要附上自己的学习笔记。
- 完成任务后要提起pr，请求合并。PR时请联系仓库管理者开一个新的分支。[PR仓库](https://github.com/YoujianWu/Learning_task)

本次任务的具体效果

![](./imgs/task.jpg)
