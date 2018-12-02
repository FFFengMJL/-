#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SANKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD "$"
#define WALL_CELL '*'

/*dy=-1(down), 1(up), 0(no move); dx=-1(left), 1(right), 0(no move)*/

void Snake_Move(int kb,int len){
    char direct;
    direct=getchar();
    int eat=0;
    switch(direct){
        case a:
        case A:if(snake_xy[1][1] != snake_xy[0][1] || snake_xy[1][1]+1 != snake_xy[0][1]){
            snake_xy[0][0]--;
            int i;
            if(map[snake_xy[0][0]-1][snake_xy[0][1]-1] == SNAKE_FOOD){
                eat=1;
            }
            if(eat){
                snakelen++;
                snake_xy[snakelen-1][0]=snake_xy[snakelen-2][0];
                snake_xy[snakelen-1][1]=snake_xy[snakelen-2][1];
            }
            for(i=0;i<snakelen-1;i++){
                snake_xy[i+1][0]=snake_xy[i][0];
                snake_xy[i+1][1]=snake_xy[i][1];
            }
            map[snake_xy[0][0]-1][snake_xy[0][1]-1]=SNAKE_HEAD;
            map[snake_xy[1][1]-1][snake_xy[1][1]-1]=SNAKE_BODY;
        }
    }
}

/*put a food randomized on a blank cell*/
/*
void Put_Money(void)
*/
/*out cells of the gird*/

void Output(void){
    int i;
    for(i=0;i<12;i++){
        printf("%s",map[i]);
    }
}

/*outs when gameover*/

void Gameover(void){
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
    int i;
    for(i=0;i<12;i++){
        printf("%s\n",map_GG[i]);
    }
}

char map[12][12]={
    "************",
    "*XXXXh     *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "*          *",
    "************"
};

int snakeX[SANKE_MAX_LENGTH]={1,2,3,4,5};
int snakeY[SANKE_MAX_LENGTH]={1,1,1,1,1};
int snakelen=5;
int snake_xy[SANKE_MAX_LENGTH][2];


int main(void){
    Gameover();
    int i;
    for(i=0;i<snakelen;i++){//初始化坐标数组
        snake_xy[i][0]=i+1;
        snake_xy[i][1]=1;
    }
    
}