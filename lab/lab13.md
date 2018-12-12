---
layout: default
title: 贪吃蛇实验报告
---
# 贪吃蛇实验报告

## 目录

### 1. snake_move（会动的蛇）

* <a href="#SM_1">伪代码</a>

* <a href="#SM_2">细节问题</a>

### 2. snake_eat

* <a href="#SE_1">伪代码</a>

* <a href="#SE_2">细节问题</a>

## 1. snake_move

#### 1. 伪代码<a name="SM_1"></a>：
<pre>
输出字符矩阵
	WHILE not 游戏结束 DO
		ch＝等待输入
		CASE ch DO
		‘A’:左前进一步，break 
		‘D’:右前进一步，break    
		‘W’:上前进一步，break    
		‘S’:下前进一步，break    
		END CASE
		输出字符矩阵
	END WHILE
	输出 Game Over!!! 
</pre>

![](https://sysu-swi.github.io/images/snake-head.png)

#### 2. 细节问题<a name="SM_2"></a>：

1. 问题一：蛇如何移动   
> 在通过测试之后，发现竖对应字符串的第一个指针，横对应第二个，故将常规的XY坐标轴顺时针旋转90度
答：通过 getchar() 函数读取按键， **w、a、s、d 键**分别对应**上下左右**；在读取到按键的时候，对蛇头的坐标进行相应的调整，身体组成的位置则被赋为**坐标数组**中前一个的值  
>（**w** --> X-1; **s** --> X+1; **a** --> Y-1; **d** --> Y+1）

2. 问题二：蛇移动的时候不会直接“回马枪”？  
> 答：在读取按键之后，判断头即将位移到的位置**是否有身体部分存在**，若不在则移动，否则不移动

3. 问题三：坐标储存  
> 答：经过长时间的 debug 发现，XY轴是**顺时针旋转90度**的，在编程中需要注意；由于边框的存在，导致坐标**不需要-1**即可对应相应位置

## 2. snake_eat

#### 1. 伪代码<a name="SE_1"></a>：

<pre>
输出字符矩阵
	WHILE not 游戏结束 DO
        随机在游戏区域产生 MONEY
		ch＝等待输入
		CASE ch DO
		‘A’:左前进一步，break 
		‘D’:右前进一步，break    
		‘W’:上前进一步，break    
		‘S’:下前进一步，break    
		END CASE
        IF SANKE_HEAD 触碰 WALL_CELL OR BODY_CELL THEN
            输出 Game Over!!!
        ELSE IF SNAKE_HEAD 触碰 MONEY THEN
            SNAKE_LENGTH += 1 #蛇长度+1
        ENDIF
		输出字符矩阵
	END WHILE
	输出 Game Over!!! 
</pre>

#### 2. 细节问题<a name="SE_2"></a>：

1. 问题一：如何判断该不该产生 MONEY ？  
> 答：设定一个**全局变量**，当场上存在 MONEY/蛇没吃 MONEY 时开关关闭；当蛇吃了 MONEY 时，开关打开，同时通过**随机函数**在**空白区域**产生一个 MONEY，产生后将开关关闭

2. 问题二：如何判定撞墙/我 吃 我 自 己的死亡？  
> 答：声明并定义一个新的函数，提前**预览下一步蛇头的位置**，如果处在 WALL_CELL 或者 BODY_CELL 的位置，则判定游戏结束

3. 问题三：如何判定胜利？  
> 答：我个人是设定胜利条件是蛇长度达到最大值（SNAKE_MAX_LENGTH），并且再吃一个 MONEY 即为胜利，所以只需要在**吃到 MONEY 的时候判断蛇长度**是否达到了最大长度即可