# Github&Clion

![photo](../imgs/github.jpeg)



## pr

step 1:在github上fork别人的仓库

step 2:在clion里clone那个fork下来的（project from VCS,贴URL可以打开），然后可以选择分支进行开发

step 3: commit并push

step 4:在github上开启pr



## tools

#### .gitignore

在一些项目中，我们不想让本地仓库的所有文件都上传到远程仓库中，而是有选择的上传,用.gitignore

##### 用法：

```yaml
/mtk/ #过滤整个文件夹
*.zip #过滤所有.zip文件
/mtk/do.c #过滤某个具体文件
```

- 以斜杠`/`开头表示目录；
- 以星号`*`通配多个字符；
- 以问号`?`通配单个字符
- 以方括号`[]`包含单个字符的匹配列表；
- 以叹号`!`表示不忽略(跟踪)匹配到的文件或目录；
- 若匹配语句中无“/ ” ,便将其视为一个 glob匹配，如'abc'可以匹配 ' abc' , 'cd/abc' , 'ef/abcde.txt'
- 若匹配语句中有'/ ' ,便视为一个路径匹配，如'abc/'可以匹配 ' abc' , 'cd/abc' ，但是无法匹配 'ef/abcde.txt'
- 若匹配语句以'/ ' 开始，便视为匹配当前目录，如'/abc'可以匹配 ' abc' 但无法匹配 'cd/abc' 

**此外，.gitignore是按行从上到下进行规则匹配的，意味着如果前面的规则匹配的范围更大，则后面的规则将不会生效**

#### pre-commit

在我们的许多存储库中，有一个在 CI 中运行的[pre-commit](https://pre-commit.com/) 检查。 你可以在本地使用它并将其设置为在提交之前自动运行，从而避免因为格式错误而无法通过 CI。 要安装，请使用 pip：

```text
pip3 install pre-commit
```

要手动运行 repo 中的所有文件：

```text
pre-commit run -a
```

要在本地存储库中提交之前自动运行 pre-commit，请在本地仓库目录中运行以下指令安装 git hooks：

```text
pre-commit install
```



## problems

#### 1. fatal: refusing to merge unrelated histories

####     fatal: refusing to merge unrelated histories

####     Push rejected: Push to origin/master was rejected

使用 `--allow-unrelated-histories`

比如 git （） origin master --allow-unrelated-histories    （）可能是pull/push/merge,

