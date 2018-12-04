---
layout: default
title: 贪吃蛇实验报告
---
# 贪吃蛇实验报告

## 目录

### 1. snake_move（会动的蛇）

* <a href="#SM_1">伪代码</a>

* <a href="#SM_2">细节问题</a>

* <a href="#SM_3">C 语言代码（119行）</a>

### 2. snake_eat

* <a href="#SE_1">伪代码</a>

* <a href="#SE_2">细节问题</a>

* <a href="#SE_3">C 语言代码（181行）</a>

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
答：在读取按键之后，判断头即将位移到的位置**是否有身体部分存在**，若不在则移动，否则不移动

3. 问题三：坐标储存
答：经过长时间的 debug 发现，XY轴是**顺时针旋转90度**的，在编程中需要注意；由于边框的存在，导致坐标**不需要-1**即可对应相应位置

#### 3. C 语言代码<a name="SM_3"></a>：

代码比较长，而且没有高亮，所以可以看这个我的 github 里面的，<a href="https://github.com/FFFengMJL/homework/blob/gh-pages/lab/snake_move.c" target="_blank">点我打开</a>
或者这个<a href="https://paste.ubuntu.com/p/DNGMfZtxp9/" target="_blank">PasteBin Ubuntu链接</a>（放心，代码是一样的）

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
    for(i=0;i < snakelen;i++){/*初始化坐标数组*/
        snake_xy[i][0]=1;
        snake_xy[i][1]=snakelen-i;
    }
    while(GG != 1){
        Output();
        Snake_Move(snakelen);
    }
}
</pre>

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

1. 问题一：如何判断该不该产生 MONEY
答：设定一个**全局变量**，当场上存在 MONEY/蛇没吃 MONEY 时开关关闭；当蛇吃了 MONEY 时，开关打开，同时通过**随机函数**在**空白区域**产生一个 MONEY，产生后将开关关闭

2. 问题二：如何判定撞墙/我 吃 我 自 己的死亡
答：声明并定义一个新的函数，提前**预览下一步蛇头的位置**，如果处在 WALL_CELL 或者 BODY_CELL 的位置，则判定游戏结束

3. 问题三：如何判定胜利？
答：我个人是设定胜利条件是蛇长度达到最大值（SNAKE_MAX_LENGTH），并且再吃一个 MONEY 即为胜利，所以只需要在**吃到 MONEY 的时候判断蛇长度**是否达到了最大长度即可

#### 3. C语言代码<a name="SE_3"></a>：

代码**没有高亮**，可以到**我的 github 仓库**中查看，<a href="https://github.com/FFFengMJL/homework/blob/gh-pages/lab/snake_eat.c" target="_blank">点我打开</a>  
也可以查看这个 <a href="https://paste.ubuntu.com/p/s4pFg2tZGr/" target="_blank">Pastebin Ubuntun 链接</a>

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
/*void Put_Money(void)*/
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
int Money=1;/*游戏区域是否有钱，默认没钱*/
int eat=0;/*表示刚刚是否吃屎*/
void Put_Money(void){/**/
    while(Money){/*区域里面没钱*/
        int x=rand()%10+1;
        int y=rand()%10+1;
        if(map[x][y] == ' '){
            map[x][y]='$';
            Money--;
        }
    }
}

void Gameover(int a){/*将GG修改集成于此，添加了胜利的结算画面*/
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
    char map_WIN[12][12]={
        "***********",
        "*         *",
        "*         *",
        "*         *",
        "*  Y O U  *",
        "*         *",
        "*  W I N  *",
        "*         *",
        "*         *",
        "*         *",
        "*         *",
        "***********"
    };
    system("clear");
    GG=1;
    int i;
    if(a == 1){
        for(i=0;i<12;i++){
            printf("%s\n",map_WIN[i]);
        }
    }
    else if(a == 0){
        for(i=0;i<12;i++){
            printf("%s\n",map_GG[i]);
        }
    }
}


void Crush_Foresee(int x_fore,int y_fore){/*康康下一步会不会翻车*/
    if(map[x_fore][y_fore] == '*' || map[x_fore][y_fore] == 'X'){
        Gameover(0);/*撞墙/我 吃 我 自 己的话就GG啦*/
    }
    else if(map[x_fore][y_fore] == '$'){/*判断会吃屎*/
        snakelen++;
        if(snakelen>20){
            Gameover(1);
        }
        eat=1;/*表示即将吃屎*/
        Money=1;/*表示区域即将没钱*/
    }
}

void Output(void){/*no problem*/
    int i;
    Put_Money();
    system("clear");/*清屏*/
    for(i=0;i<12;i++){
        printf("%s\n",map[i]);
    }
}


/*x是竖，y是横*/
/*复制除了头之外的蛇的坐标*/
void MoveButHead(void){
    int i;
    if(eat){/*新加的尾巴坐标是（0,0)*/
        eat=0;
    }
    else{
        map[snake_xy[snakelen-1][0]][snake_xy[snakelen-1][1]]=' ';/*将蛇尾消失*/
    }
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
    char direct=getchar();
    switch(direct){
        case 'a':
        case 'A':if(snake_xy[1][1]+1 != snake_xy[0][1]){/*判断条件：脖子不在头的要转向的方向*/
            Crush_Foresee(snake_xy[0][0],snake_xy[0][1]-1);
            MoveButHead();
            snake_xy[0][1]--;/*头纵坐标-1*/
            MoveHead();
        }break;
        case 'w':
        case 'W':if(snake_xy[1][0]+1 != snake_xy[0][0]){
            Crush_Foresee(snake_xy[0][0]-1,snake_xy[0][1]);
            MoveButHead();
            snake_xy[0][0]-=1;/*头横坐标-1*/
            MoveHead();
        }break;
        case 's':
        case 'S':if((snake_xy[1][0]-1) != (snake_xy[0][0])){
            Crush_Foresee(snake_xy[0][0]+1,snake_xy[0][1]);
            MoveButHead();
            snake_xy[0][0]+=1;/*头横坐标+1*/
            MoveHead();
        }break;
        case 'd':
        case 'D':if(snake_xy[1][1]-1 != snake_xy[0][1]){
            Crush_Foresee(snake_xy[0][0],snake_xy[0][1]+1);
            MoveButHead();
            snake_xy[0][1]++;/*头纵坐标+1*/
            MoveHead();
        }break;
        case 'q':case 'Q':Gameover(0);break;
        default:break;
    }
}

int main(void){
    int i;
    for(i=0;i < snakelen;i++){/*初始化坐标数组*/
        snake_xy[i][0]=1;
        snake_xy[i][1]=snakelen-i;
    }
    while(GG != 1){
        Output();
        Snake_Move(snakelen);
    }
}
</pre>