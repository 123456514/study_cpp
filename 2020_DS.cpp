//
// Created by 26702 on 2024/5/12.
//
#include<iostream>
using namespace std;
#define MaxSize 10
// 顺序表静态分配
typedef struct{
    int data[MaxSize]; // 使用静态数组
    int length;
}SqList;
void sort(int &nums[MaxSize]){
    int length = sizeof(nums) / sizeof(int);
    for(int i = 0;i < length;i++){
        for(int j = i ;j < length - i - 1;j++){
            if(nums[j] > nums[j+1]){
                int *temp = nums[j];
                nums[j] = nums[j +1];
                nums[j +1] = *temp;
            }
        }
    }
}
void swap(int *a,int *b){
    int *temp = *a;
    *a = *b;
    *b = *temp;
}
// 1. 已知顺序表l中的数据元素是整数类型，编写算法删除顺序表中值最小的数据元素
void deleteMin(SqList &list){
   int min = list.data[0];
   for(int i = 1;i < list.length;i++){
       if(list.data[i] < min){
           min = list.data[i];
       }
   }
   for(int i = 0;i < list.length;i++){
       if(list.data[i] == min){
           for(int j = i;j < list.length;j++){
               list.data[j] = list.data[j + 1];
               list.length--;
               i--;
           }
       }
   }
}
// 2. 2023年 链表第一题原题
// 3. 已知二叉树以二叉链表方式存储，二叉树盖度定义为 如果二叉树为空则其高度为0 若非空则其高度为左右子树的最大值 + 1
//    简要描述采用的算法思想 编写求二叉树高度的算法
// 4. 判断无向图G是否是一颗二叉树
//    简要描述采用的算法思想 写出图的存储结构定义 邻接矩阵，邻接表
//    在此存储结构的基础上，编程实现该算法

int main(){

    return 0;
}