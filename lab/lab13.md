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
答：通过 getchar() 函数读取按键， **w、a、s、d 键**分别对应**上下左右**；在读取到按键的时候，对蛇头的坐标进行相应的调整，身体组成的位置则被赋为**坐标数组**中前一个的值  
>（**w** --> Y+1; **s** --> Y-1; **a** --> X-1; **d** --> X+1）

2. 问题二：蛇移动的时候不会直接“回马枪”？
答：在读取按键之后，判断头即将位移到的位置**是否有身体部分存在**，若不在则移动，否则不移动

3. 问题三：坐标储存
答：经过长时间的 debug 发现，XY轴是**顺时针旋转90度**的，在编程中需要注意；由于边框的存在，导致坐标**不需要-1**即可对应

4. 问题四：如何解决撞墙/出墙问题
答：暂不添加，在snake_eat中添加；思路：判断蛇头下一步移动的位置是否是墙，如果是则不动/GG，否则进行移动

#### 3. C 语言代码<a name="SM_3"></a>

>代码比较长，而且没有高亮，所以可以看这个<a href="https://paste.ubuntu.com/p/QXytHZNdyd/" target="_blank">PasteBin Ubuntu网页</a>的（放心，代码是一样的）

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
/*put a food randomized on a blank cell*/
/*
void Put_Money(void)
*/
/*out cells of the gird*/
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
int snake_xy[SANKE_MAX_LENGTH][2];/*x是竖，y是横*/


void Output(void){/*no problem*/
    int i;
    system("clear");/*清屏*/
    for(i=0;i<12;i++){
        printf("%s\n",map[i]);
        /*if(i != 11){
            printf("\n");
        }*/
    }
}

void Gameover(void){/*no problem*/
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
    map[snake_xy[0][0]][snake_xy[0][1]]='H';/*头出现*/
}

void Snake_Move(int snakelen){
    scanf("%c",&direct);/*此处爆炸？*/
    switch(direct){
        case 'a':
        case 'A':if(snake_xy[1][1]+1 != snake_xy[0][1]){/*判断条件：脖子不在头的要转向的方向*/
            MoveButHead(snakelen);
            snake_xy[0][1]--;/*头纵坐标-1*/
            MoveHead();
        }break;
        case 'w':
        case 'W':if(snake_xy[1][0]+1 != snake_xy[0][0]){
            MoveButHead(snakelen);
            snake_xy[0][0]-=1;/*头横坐标-1*/
            MoveHead();
        }break;
        case 's':
        case 'S':if((snake_xy[1][0]-1) != (snake_xy[0][0])){
            MoveButHead(snakelen);
            snake_xy[0][0]+=1;/*头横坐标+1*/
            MoveHead();
        }break;
        case 'd':
        case 'D':if(snake_xy[1][1]-1 != snake_xy[0][1]){
            MoveButHead(snakelen);
            snake_xy[0][1]++;/*头纵坐标+1*/
            MoveHead();
        }break;
        case 'q':GG=1;Gameover();break;
        default:break;
    }
}

int main(void){
/*    Gameover();*/
    int i;
    for(i=0;i<snakelen;i++){/*初始化坐标数组*/
        snake_xy[i][0]=1;
        snake_xy[i][1]=snakelen-i;
/*        printf("%d\t%d\n",snake_xy[i][0],snake_xy[i][1]);坐标初始化没有问题*/
    }
    char direct;
    while(GG != 1){
        Output();
        Snake_Move(snakelen);
    }
}
</pre>