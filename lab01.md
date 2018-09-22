---
layout: default
title: 用乌龟git更加简单地clone作业仓库
---

# 用乌龟git更加简单地clone作业仓库

>前言：由于按照[学校给的教程](https://sysu-swi.github.io/homework-start)在本地clone代码仓库需要打开git bash的类似cmd的界面（这界面还`不能ctrl+v`），并且步骤**感觉**过于麻烦。而我是在室友dalao的帮助下（其实是并没有看到教程(°ー°〃)）通过`乌龟git`进行了同样的设置，并且感觉更加方便快捷易读，所以描述一下相关操作，希望能够帮到读者。  

## 步骤  
1.  注册github账号

2.  下载并安装vscode

3.  下载并安装git

4.  下载并安装乌龟git

5.  fork homework仓库

6.  clone仓库

### 步骤1~3

>可直接参考学校教程 [使用Git提交作业](https://sysu-swi.github.io/homework-start)

![软工导论支持网站](https://wx2.sinaimg.cn/mw1024/007dfLy5ly1fvi4muu1npj30r30aydh8.jpg)

### 4.下载并安装乌龟git

#### 下载乌龟git
* 好的习惯：[百度](www.baidu.com)/[谷歌](www.google.com)搜索乌龟git

*  不好的习惯：直接点开[Tortoise Git](https://tortoisegit.org/)，点击download，然后选择与自己电脑匹配的版本下载即可![TortoiseGit官网](https://wx2.sinaimg.cn/mw1024/007dfLy5ly1fvi6wzhahzj31gx0oj469.jpg)

#### 安装乌龟git

点开安装包，一路**next**，可以在安装路径那里调整一下

>安装完启动了乌龟git之后，会有语言选择项，但是我们会发现只有`english`是可选的，如果想要`中文`：

1.  先不要关闭乌龟git，然后在刚刚的download页面往下滑，找到、下载并且安装简体中文包。

2.  回到乌龟git，点击**refresh**，就能找到中文啦。

### 5.fork 代码仓库

1.  登陆你的github

2.  点开[https://github.com/sysu-swi/homework](https://github.com/sysu-swi/homework)

3.  看到那个红圈里面的**fork**了么，点击它！然后就会跳转并发现了属于自己的`homework`仓库了！![fork](https://wx4.sinaimg.cn/mw1024/007dfLy5ly1fvi80r4x9yj31go0p3ack.jpg)

### 6.clone仓库

1. 复制你的`homework`仓库的网址。![复制网址](https://wx4.sinaimg.cn/mw1024/007dfLy5ly1fvi86wzti0j30zf0p1770.jpg)

2. 在你的桌面**鼠标右键**,找到`Git 克隆`。![鼠标右键](https://wx3.sinaimg.cn/mw1024/007dfLy5ly1fvi4mvetrij30dc0httea.jpg)

>* 如果没有找到，可以**shift+鼠标右键**再试试。

>* 如果上述操作还是找不到，那么 **右键**>>**Tortoise**>>**设置**>>左侧选择**右键菜单**,勾选`克隆`，并重复上一个步骤。

{:start="3"}
3. 把你复制的网址黏贴在`URL`栏，选择好你想克隆到的文件夹，**确定**就好。![](https://wx4.sinaimg.cn/mw1024/007dfLy5ly1fvi4mut5zyj30k00eq3yt.jpg)

4. 等待进度条满上。

5. 大功告成！╰(￣ω￣ｏ)

>后面的步骤继续参考学校教程 [使用Git提交作业](https://sysu-swi.github.io/homework-start)就好。

<!--## 1、你会使用 vscode 编辑 markdown 了吗？

你会使用 git bash 创建本地空间了吗？

你能拉取本文档到本地了？它在 gh-pages 分支内，设置 Slate 主题！

用 vscode 编辑它，然后提交！

这个文档将发布在 https://your-account.github.io/homework 中！-->