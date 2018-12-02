---
layout: default
title: 贪吃蛇实验报告
---
# 贪吃蛇实验报告

## 目录

1. 伪代码

2. 编写 C 语言代码

3. 优化

## 1. 伪代码

1. 在课件博客找到
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

2. 问题  
问题一：蛇如何移动  
回答：