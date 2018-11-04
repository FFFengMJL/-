---
layout: default
title: 实验报告
---

# 任务1: 简单程序

#### 1. 打开网页 The PIPPIN User’s Guide ，然后输入 Program 1：Add 2 number

#### 2. 点step after step。观察并回答下面问题：

1. PC，IR 寄存器的作用。

> PC：读取下一个指令的地址；  
> IR：读取地址中的指令并且保存它。

{:stary="2"}
2. ACC 寄存器的全称与作用。

> *ACC* (**Acc**umulator register): In a computer's central processing unit (CPU), an accumulator is a register in which intermediate arithmetic and logic results are stored.


3. 用“LOD #3”指令的执行过程，解释Fetch-Execute周期。

![](images/lab07/program1%20LOD123.png)

>   - 1) PC拿取指令的地址
>   - 2) IR通过PC的地址获取指令
>   - 3) IR将指令传入Decoder

![](images/lab07/program1%20LOD4.png)

>   - 4) Decoder将*Instruction Specifier*传入ALU，并将*Operand specificer*传入MUX

![](images/lab07/program1%20LOD56.png)

>   - 5) ALU将加法运算载入
>   - 6) ALU左侧载入0，右侧读入MUX中的数字`3`，并进行运算

![](images/lab07/program1%20LOD78.png)

>   - 7) 将结果储存在ACC
>   - 8) PC中的地址+2

{:start="4"}
4. 用“ADD W” 指令的执行过程，解释Fetch-Execute周期。

![](images/lab07/program1%20ADDW123.png)

>   - 1) PC拿取指令的地址
>   - 2) IR通过PC的地址获取指令
>   - 3) IR将指令传入Decoder

![](images/lab07/program1%20ADDW4.png)

>   - 4) Decoder将*Instruction Specifier*传入ALU，并将*Operand specificer*传入MUX

![](images/lab07/program1%20ADDW56.png)

>   - 5) ALU载入加法，MUX读取地址W中的数据
>   - 6) ALU左侧载入ACC中寄存的数据，右侧载入MUX中的数据，进行运算

![](images/lab07/program1%20ADDW78.png)

>   - 7) 将结果储存在ACC
>   - 8) PC中的地址+2

{:start="5"}
5. “LOD #3” 与 “ADD W” 指令的执行在Fetch-Execute周期级别，有什么不同。

> “ADD W”需要向内存拿取数据，所需步骤更多。

#### 3. 点击“Binary”,观察回答下面问题

1. 写出指令 “LOD #7” 的二进制形式，按指令结构，解释每部分的含义。

> **000010100 00000111**
> 
> The former 8 bits are *Instruction Specifier* —— LOD, which means "Load the data to the register"; the later 8 bits are *Operand Specifier*, which is the data "7".

2. 解释 RAM 的地址。

> The *Data* address and *Instruction* address are both **8 bits**, but the first bit of Instruction address is "**1**", instead of it is "**0**" in Data address. 

3. 该机器CPU是几位的？（按累加器的位数）

> 8位

4. 写出该程序对应的 C语言表达。

```
int W=3;
int Y=7+W;
```

# 任务 2：简单循环

#### 1. 输入程序Program 2，运行并回答问题：

1. 用一句话总结程序的功能

> X不断-1。

2. 写出对应的 c 语言程序
```
#include<stdio.h>

int main(){
    int X=0;
    x-=1
    while(x != 0){
        x-=1;
    }
}
```
#### 2. 修改该程序，用机器语言实现 10+9+8+..1 ，输出结果存放于内存 Y

1. 写出 c 语言的计算过程

```
#include<stdio.h>

int main(){
    int X=0;
    int Y=10;
    X+=Y
    Y-=1;
    while(Y != 0){
        X+=Y;
        Y-=1;
    }
}
```

2. 写出机器语言的计算过程

```
0   LOD #10
2   STO Y
4   LOD Y
6   ADD X
8   STO X
10  LOD Y
12  SUB #1
14  STO Y
16  CPZ Y
18  JMZ 4
20  HLT
```

3. 用自己的语言，简单总结高级语言与机器语言的区别与联系。

> 高级语言：
> * 更加灵活易懂，容易掌握，使用与阅读更加容易，但是缺少了对计算的细节，使得无法优化算法。
> * 高级语言能够在编译器的帮助下，编译成机械语言，从而执行程序。
>
> 机器语言：由晦涩难懂的二进制代码组成，在缺乏长期训练的情况下，难以较好地利用该语言；而且语句少，难以实现“少代码，大效果”的如迭代；但是由于其是直接对CPU操作，可以更好的对算法进行优化。
