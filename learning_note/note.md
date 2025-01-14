

# Learning note

对于此次学习任务的笔记

## urdf

- 由link组成，每个link之间joint连接起来
- 在使用joint连接父link和子link时，子link以joint为参照点（包括collision和inertial）
- 注意模型，碰撞体位置应该一致，还有重心位置
- transimission,joint,actuator.   ros_controller通过识别transimission标签来对urdf模型进行控制
- 需要配置gazebo插件，让gazebo 和 ros 联系起来

## launch

- 加载urdf文件，（获取文件内容，启用节点）

## controller

- 使用正确的控制器类型（对应joint的hardwareinterface）来对关节进行控制
- 一个控制器可以对应多个关节，但一个关节不可以重复出现在多个控制器中

## pre-commit

```
repos:
  - repo: https://github.com/pre-commit/pre-commit-hooks
    rev: v3.4.0
    hooks:
      - id: check-added-large-files
      - id: check-yaml

  - repo: local
    hooks:
      - id: my-example
        name: My  hook
        entry: .git/hooks/pre-commit
        language: script
        types: [file]
        files: \.(cpp|cxx|h|hpp)$
```

创建    .pre-commit-config.yaml    文件，在里面输入类似上方的代码（配置钩子）

第一部分中使用的是远程仓库，笔记中的是一个有已经有钩子的仓库

> [!NOTE]
>
> 使用远程仓库时要rev标明你想要使用的仓库版本

在hooks的id中写上需要使用的钩子



第二部分是本地自行编辑一个钩子

在目录中执行

```
pre-commit install
```

可以生成一个pre-commit文件在.git/hooks/pre-commit中

id处描述钩子作用，entry后面跟着的是执行文件的路径

language是指钩子的语言类型，script是通用类型

type是检查的文件类型。在这里，因为cpp无法被直接识别，所以要用上述方式，但像python，yaml文件可以

```
type: [python,yaml]
```

形如这样（同时多种类型）



## gitignore

```
*.log
```

像这样可以忽略全部的.log文件

```
*.[oa]
```

忽略.o 和.a文件

```
example/
```

这样是直接忽略整个example文件夹

```
exampel.txt
```

这样可以忽略example.txt这个文件