---
layout: default
title: 智障蛇学习
---

# 字符游戏——智能蛇（学习）

## 目录

1. <a href="#term">终端调整</a>  
2. <a href="#tty">非阻塞输入</a>
3. <a href="#auto">智能行走</a>

## 1. 终端调整<a name="term"></a>

1. 通过官方示范：  
<pre>
    printf("\033[41;36m something here \033[0m");
</pre>
并试着将结尾处的 "\033[0m" （取消全部之前所有属性）去除，发现区别如下：  
![](../images/lab15/del[0m.png)

2. 尝试将贪吃蛇的背景色换成**白色**(\033[47m)，将蛇的身体与墙壁换成**黑色**(\033[30m)，于是将 Output() 函数进行了更改，改变如下：  
<pre>
printf("\033[30;47m%s\n\033[0m);
</pre>
然而，发现其与预期效果不符（使整个终端界面变成白色底色）  
![](../images/lab15/fullwhite.png)

3. 修改代码，使结尾处恢复属性的代码 "\033[0m" 放到 "\n" 前，发现符合需求，于是将在胜利和失败的输出页面也加入代码，最终效果如图：  
![](../images/lab15/nofullwhite.png)

> "\033[2J" 似乎与 "system("clear")" 命令相当，但是似乎由于 windows 系统下不支持这个命令，因此不做更改，使用兼容性更好的 "system("clear")"

## 2. 非阻塞输入<a name="tty"></a>

1. 阅读 kbhit() 的代码（我是直接复制的<a href="http://bbs.chinaunix.net/thread-935410-1-1.html" target="_blank">Linux下非阻塞地检测键盘输入的方法 (整理)</a>的），<del>我选择自爆</del>，将部分不需要的代码注释掉，最终的代码和网页上给的差不多（其实也就是注释掉第83行（或者左右）的else{}中的那一行）

2. 测试kbhit().c的实际性能，发现基本符合要求，效果如下：  
![](../images/lab15/kbhit_test.png)

3. 按照网页的提示，应该将贪吃蛇代码放入 kbhit.c 文件中，但是为了避免出错/污染/冲突，选择在原本的贪吃蛇代码上进行**加载**（#include "./kbhit.c"）操作，并将 kbhit.c 中的main函数**注释**掉

4. 按照原本kbhit.c中main()函数的类似形式，将tty的代码**加入**，最终代码形式如下：  
<pre id="ks"></pre>  
*发现刷新率似乎似乎过快？*  
> 通过修改第53~54行的代码，修改刷新/输入所需要的时间（second或usecond），从而**改变自动刷新的速率**

5. 尝试使贪吃蛇变得和平常玩的贪吃蛇一样，每一步都**不再需要方向键**输入，而是向着**头的方向**进行移动，于是修改代码，让蛇只在有**方向键输入的时候改变方向**，其它时刻只需要按照**蛇头/上一次输入的方向**移动即可  ，效果基本符合需求，<a href="https://github.com/FFFengMJL/homework/blob/gh-pages/lab/snake_eat_v2.c" target="_blank">代码链接：snake_eat_v2.c</a>

## 3. 智能（障）蛇<a name="auto"></a>

1. 根据网页给出的思路：
<pre>
    // Hx,Hy: 头的位置
    // Fx,Fy：食物的位置
	function whereGoNext(Hx,Hy,Fx,Fy) {
	// 用数组movable[3]={“a”,”d”,”w”,”s”} 记录可走的方向
	// 用数组distance[3]={0,0,0,0} 记录离食物的距离
	// 分别计算蛇头周边四个位置到食物的距离。H头的位置，F食物位置
	//     例如：假设输入”a” 则distance[0] = |Fx – (Hx-1)| + |Fy – Hy|
	//           如果 Hx-1，Hy 位置不是Blank，则 distance[0] = 9999
	// 选择distance中存最小距离的下标p，注意最小距离不能是9999
	// 返回 movable[p]
	}
</pre>

2. 做出部分修改后，写出AutoMove()函数  

3. 在贪吃蛇中去除接受输入的函数，并将自动移动的算法写入，<a href="https://github.com/FFFengMJL/homework/blob/gh-pages/lab/snake_automove.c" target="_blank">代码链接：snake_automove.c</a>，最终效果：蛇能够判断并吃屎，但是**无法判断会不会自己吃自己**

4. 优化算法，伪代码如下：  
<pre>
分别计算蛇头周边四个位置的距离，取最小值 min_1
FOR i FROM 0 TO 4
  IF 蛇头按照最小值 min_1 对应的方向的前进一个的位置是'X'或者'*' THEN
    找出除了比最小值大的数组中的最小值 min_2
    min_1 = min_2
  ELSE
    BREAK
  ENDIF
ENDFOR
返回最小值 min_1 对应的方向
</pre>

5. 写出代码，代码链接效果：能够自己胜利（长度达到20,并再吃一个）一次  

6. 修改map字符串，使地图中加入阻碍物，效果：由于**无法预测更远**的下一步，因此会出现自己把自己**弄进死胡同**,导致GG，<a herf="https://github.com/FFFengMJL/homework/blob/gh-pages/lab/snake_automove_ver2.c" target="_blank">代码链接：snake_automove_ver2.c</a>

<script>
document.getElementById('ks').innerText=`
int main(void){
  int tty_set_flag;
  tty_set_flag = tty_set();
  int i;
  int key;
  for(i=0;i < snakelen;i++){/*初始化坐标数组*/
      snake_xy[i][0]=1;
      snake_xy[i][1]=snakelen-i;
  }
  while(GG != 1){
    if( kbhit() ) {
      key=getchar();      
      Output();
      Snake_Move(snakelen,key);
    }
    else{
      Output();
    }
  }
  if(tty_set_flag == 0) 
          tty_reset();
  return 0;
}`
document.getElementById('au').innerText=`
char movable[]={'w','a','s','d'};/*走的方式，与最小值的位置对应*/
int distance[4]={0};
char Auto_Move(int Money_x,int Money_y){
  int former_x=snake_xy[0][0];
  int former_y=snake_xy[0][1];
  distance[0]=abs(snake_xy[0][0]-1-Money_x)+abs(snake_xy[0][1]-Money_y);/**/
  distance[1]=abs(snake_xy[0][0]-Money_x)+abs(snake_xy[0][1]-1-Money_y);
  distance[2]=abs(snake_xy[0][0]+1-Money_x)+abs(snake_xy[0][1]-Money_y);
  distance[3]=abs(snake_xy[0][0]-Money_x)+abs(snake_xy[0][1]+1-Money_y);
  int i,t,min=0;
  for(i=0;i<4;i++){
    min=(distance[i]<distance[min]?i:min);
  }
  Snake_Move(snakelen,movable[min]);
  if(snake_xy[0][0] == former_x && snake_xy[0][1] == former_y){
    for(i=0,t=min,min=0;i<4;i++){
      if(i!=t){
        min=(distance[i]<distance[min]?i:min);
      }
    }
    Snake_Move(snakelen,movable[min]);
  }
//  return movable[min];
}
`
document.getElementById('au_2').innerText=`/*预防自己吃自己和往回走和撞墙*/
int HowToMove(int lowest){
  int i,min,flag=0;
  for(i=0;i<4;i++){
    if(flag){
      if(distance[i]<distance[min] && distance[i]>=distance[lowest]){
        if(i != lowest){
          min=i;
        }
      }
    }
    else{
      if(distance[i]>=distance[lowest] && i != lowest){
        min=i;
        flag=1;
      }
    }
  }
  return min;
}

char Auto_Move(int Money_x,int Money_y){
  int i,t,min=0;
  for(i=0;i<4;i++){
    distance[i]=abs(snake_xy[0][0]+move[i][0]-Money_x)+abs(snake_xy[0][1]+move[i][1]-Money_y);
  }
  for(i=0;i<4;i++){
    min=(distance[i]<distance[min]?i:min);
  }
  for(i=0;i<4;i++){
    char tar=map[snake_xy[0][0]+move[min][0]][snake_xy[0][1]+move[min][1]];
    if(tar == 'X' || tar == '*'){
      min=HowToMove(min);
    }
    else{
      break;
    }
  }
  Snake_Move(snakelen,movable[min]);
  Output(GG);
  printf("%c\n",movable[min]);
}
`
</script>