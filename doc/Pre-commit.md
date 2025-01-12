

# Using pre-commit

## Step1: 安装pre-commit

```bash
pip install pre-commit
```

## Step2: 使用一个简单配置

运行

```bash
pre-commit sample-config > .pre-commit-config.yaml
```

会在根目录下生成一个样例.pre-commit-config.yaml

## Step3: 安装Git钩子

在仓库根目录下

```bash
pre-commit install
```
## Step4: 进行项目检查
运行

```bash
pre-commit run -a
```

会对仓库下所有文件进行检查

```bash
Trim Trailing Whitespace.................................................Passed
Fix End of Files.........................................................Failed
- hook id: end-of-file-fixer
- exit code: 1
- files were modified by this hook

Fixing doc/notes.md
Fixing doc/Pre-commit.md
Fixing doc/URDF_Design.md

Check Yaml...............................................................Passed
Check for added large files..............................................Passed

```
