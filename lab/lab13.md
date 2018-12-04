---
layout: default
title: 贪吃蛇实验报告
---
# 贪吃蛇实验报告

## 目录

### 1. snake_move（会动的蛇）

* <a href="#SM_1">伪代码</a>

* <a href="#SM_2">细节问题</a>

* <a href="#SM_3">C 语言代码（比较长）</a>

### 2. snake_eat

## 1. snake_move

#### 1. 伪代码<a name="SM_1"></a>
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

#### 2. 细节问题<a name="SM_2"></a>

1. 问题一：蛇如何移动 
> 在通过测试之后，发现竖对应字符串的第一个指针，横对应第二个，故将常规的XY坐标轴顺时针旋转90度
答：通过 getchar() 函数读取按键， **w、a、s、d 键**分别对应**上下左右**；在读取到按键的时候，对蛇头的坐标进行相应的调整，身体组成的位置则被赋为**坐标数组**中前一个的值  
>（**w** --> X-1; **s** --> X+1; **a** --> Y-1; **d** --> Y+1）

2. 问题二：蛇移动的时候不会直接“回马枪”？
答：在读取按键之后，判断头即将位移到的位置**是否有身体部分存在**，若不在则移动，否则不移动

3. 问题三：坐标储存
答：经过长时间的 debug 发现，XY轴是**顺时针旋转90度**的，在编程中需要注意；由于边框的存在，导致坐标**不需要-1**即可对应相应位置

#### 3. C 语言代码<a name="SM_3"></a>

>代码比较长，而且没有高亮，所以可以看这个<a href="https://paste.ubuntu.com/p/DNGMfZtxp9/" target="_blank">PasteBin Ubuntu网页</a>的（放心，代码是一样的）

<pre>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SANKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

int GG=0;
char map[12][12]={
    {"***********"},
    {"*XXXXH    *"},
    {"*         *"},
    {"*         *"},
    {"*         *"},
    {"*         *"},
    {"*         *"},
    {"*         *"},
    {"*         *"},
    {"*         *"},
    {"*         *"},
    {"***********"}
};
int snakelen=5;
int snake_xy[SANKE_MAX_LENGTH][2];/*x是竖坐标，y是横坐标*/


void Output(void){/*输出*/
    int i;
    system("clear");/*清屏（Ubuntu版本命令），win版本未尝试*/
    for(i=0;i<12;i++){
        printf("%s\n",map[i]);
    }
}

void Gameover(void){/*游戏结束*/
    char map_GG[12][12]={
        "***********",
        "*         *",
        "*         *",
        "*         *",
        "* G a m e *",
        "*         *",
        "* O v e r *",
        "*         *",
        "*         *",
        "*         *",
        "*         *",
        "***********"
    };
    system("clear");
    int i;
    for(i=0;i<12;i++){
        printf("%s\n",map_GG[i]);
    }
}

/*x是竖，y是横*/
/*复制除了头之外的蛇的坐标*/
void MoveButHead(int snakelen){
    int i;
    map[snake_xy[snakelen-1][0]][snake_xy[snakelen-1][1]]=' ';/*将蛇尾消失*/
    for(i=snakelen-1;i>=1;i--){/*倒序赋值，避免逻辑错误*/
        snake_xy[i][0]=snake_xy[i-1][0];
        snake_xy[i][1]=snake_xy[i-1][1];
    }
}

void MoveHead(void){
    map[snake_xy[1][0]][snake_xy[1][1]]='X';/*原本的头变为身子*/
    map[snake_xy[0][0]][snake_xy[0][1]]='H';/*新的头出现*/
}

void Snake_Move(int snakelen){
    char direct=getchar();
    switch(direct){
        case 'a':
        case 'A':if(snake_xy[1][1]+1 != snake_xy[0][1]){/*判断条件：脖子不在头的要转向的方向*/
            MoveButHead(snakelen);
            snake_xy[0][1]--;/*头Y坐标-1*/
            MoveHead();
        }break;
        case 'w':
        case 'W':if(snake_xy[1][0]+1 != snake_xy[0][0]){
            MoveButHead(snakelen);
            snake_xy[0][0]-=1;/*头X坐标-1*/
            MoveHead();
        }break;
        case 's':
        case 'S':if((snake_xy[1][0]-1) != (snake_xy[0][0])){
            MoveButHead(snakelen);
            snake_xy[0][0]+=1;/*头X坐标+1*/
            MoveHead();
        }break;
        case 'd':
        case 'D':if(snake_xy[1][1]-1 != snake_xy[0][1]){
            MoveButHead(snakelen);
            snake_xy[0][1]++;/*头Y坐标+1*/
            MoveHead();
        }break;
        case 'q':GG=1;Gameover();break;
        default:break;
    }
}

int main(void){
    int i;
    for(i=0;i<snakelen;i++){/*初始化坐标数组*/
        snake_xy[i][0]=1;
        snake_xy[i][1]=snakelen-i;
    }
    while(GG != 1){
        Output();
        Snake_Move(snakelen);
    }
}
</pre>