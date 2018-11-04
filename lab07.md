---
layout: default
title: 实验报告
---

# 任务1: 简单程序

1. 打开网页 The PIPPIN User’s Guide ，然后输入 Program 1：Add 2 number

2. 点step after step。观察并回答下面问题：

* 1. PC，IR 寄存器的作用。

> PC：读取下一个指令的地址；  
> IR：读取地址中的指令并且保存它。

{:stary="2"}
* 2. ACC 寄存器的全称与作用。

> *ACC* (**Acc**umulator register): In a computer's central processing unit (CPU), an accumulator is a register in which intermediate arithmetic and logic results are stored.

{:start="3"}
* 3. 用“LOD #3”指令的执行过程，解释Fetch-Execute周期。

![](/images/lab07/program1%20LOD123.png)

>   1. PC拿取指令的地址
>   2. IR通过PC的地址获取指令
>   3. IR将指令传入Decoder

![](/images/lab07/program1%20LOD4.png)

>   4. Decoder将*Instruction Specifier*传入ALU，并将*Operand specificer*传入MUX

![](/images/lab07/program1%20LOD56.png)

>   5. ALU将加法运算载入
>   6. ALU左侧载入0，右侧读入MUX中的数字3，并进行运算

![](images/lab07/program1%20LOD78.png)

>   7. 将结果储存在ACC
>   8. PC中的地址+2

{:start="4"}
* 4. 用“ADD W” 指令的执行过程，解释Fetch-Execute周期。

![](/images/lab07/program1%20ADDW123.png)

>   1. PC拿取指令的地址
>   2. IR通过PC的地址获取指令
>   3. IR将指令传入Decoder

![](/images/lab07/program1%20ADDW4.png)

>   4. Decoder将*Instruction Specifier*传入ALU，并将*Operand specificer*传入MUX

![](/images/lab07/program1%20ADDW56.png)

>   5. ALU载入加法，MUX读取地址W中的数据
>   6. ALU左侧载入ACC中寄存的数据，右侧载入MUX中的数据，进行运算

![](/images/lab07/program1%20ADDW78.png)

>   7. 将结果储存在ACC
>   8. PC中的地址+2

{:start="5"}
* 5. “LOD #3” 与 “ADD W” 指令的执行在Fetch-Execute周期级别，有什么不同。

> “ADD W”需要向内存拿取数据，所需步骤更多。
