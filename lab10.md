---
layout: default
title: 使用 pyhon 求解
---

# 使用 Python 求解

## 目录

1. <a href="#math">使用 Python 求解高等数学</a>

2. <a href="#linalg">使用 Python 求解线性代数</a>

## <a name="math">高等数学</a>

## <a name="linalg">使用 python 求解线性代数</a>

### 1. What is the RANK of the space spanned by the given vector.

$$ \vec{a} $$ = $ \begin{bmatrix} 1 -3 2 -4 \end{bmatrix} $  
$$ \vec{b} $$ = $ \begin{bmatrix} -3 \\ 9 \\ -6 \\ 12 \\ \end{bmatrix} $  
$$ \vec{c} $$ = $ \begin{bmatrix} 2 \\ -1 \\ 4 \\ 2 \\ \end{bmatrix} $  
$$ \vec{d} $$ = $ \begin{bmatrix} -4 \\ 5 \\ -3 \\ 7 \\ \end{bmatrix} $  

1. 加载库  
![](images/lab10/loadmodule.png)

2. 创建题目给的矩阵  
![](images/lab10/creatmatrix.png)

3. 使用.shape查看矩阵维度
![](images/lab10/dimensions.png)

### 2. 求下列矩阵的转置、逆（如果可逆）

B = $ \begin{bmatrix} 0 & 1 & 2 \\ 1 & 0 & 3 \\ 4 & -3 & 8 \\ \end{bmatrix} $

1. 输入上述矩阵  
![inputB](images/lab10/inputB.png)

2. 求解上述矩阵的转置  
![B.tranpose](images/lab10/tranpose.png)

3. 求上述举证的逆  
![A**-1](images/lab10/wayone.png)  
![A.I](images/lab10/waytwo.png)