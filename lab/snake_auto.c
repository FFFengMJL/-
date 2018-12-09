// Hx,Hy: 头的位置
// Fx,Fy：食物的位置
//function whereGoNext(Hx,Hy,Fx,Fy) {
// 用数组movable[3]={“a”,”d”,”w”,”s”} 记录可走的方向
// 用数组distance[3]={0,0,0,0} 记录离食物的距离
// 分别计算蛇头周边四个位置到食物的距离。H头的位置，F食物位置
//     例如：假设输入”a” 则distance[0] = |Fx – (Hx-1)| + |Fy – Hy|
//           如果 Hx-1，Hy 位置不是Blank，则 distance[0] = 9999
// 选择distance中存最小距离的下标p，注意最小距离不能是9999
// 返回 movable[p]

#include <stdio.h>
#include <stdlib.h>
