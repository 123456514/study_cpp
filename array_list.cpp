//
// Created by 26702 on 2024/5/10.
//
#include <iostream>
using namespace std;

#define MaxSize 10
#define InitSize 10
// 顺序表静态分配
typedef struct{
    int data[MaxSize]; // 使用静态数组
    int length;
}SqList;

// 顺序表 动态分配
typedef struct {
    int *data; // 指示动态分配数组的指针
    int max_size;
    int length;
}sq_list;
// 顺序表 顺序存储  物理内存相邻
// 初始化
void init_list(SqList &l){
    for(int i = 0;i < MaxSize;i++){
        l.data[i] = 0;
    }
    l.length = 0;
}

void init_list_dynamic(sq_list &l){
    l.data = (int *) malloc(InitSize * sizeof(int)); // 初始化 InitSize 个 int 类型的内存空间
    l.length = 0;
    l.max_size = InitSize;
}
void increase_size(sq_list &l,int len) {
    int *p = l.data;
    l.data = (int *) malloc((l.max_size + len) * sizeof(int));
    for (int i = 0; i < l.length; i++) {
        l.data[i] = p[i];  // 数据复制到新的区域
    }
    l.max_size = l.max_size + len;
    free(p); // 释放原来的内存空间
}

// 在静态顺序表中 的 第 i 个位置 添加 e
bool insert(SqList &l,int i,int target){
    // i 不合法
    if(i <1 || i > l.length + 1){
        return false;
    }
    // 顺序表已经填满了
    if(l.length >= MaxSize){
        return false;
    }
    // 后移
    for(int j = l.length; j >= i;j--){
        l.data[j] = l.data[j - 1];
    }
    l.data[i-1] = target;
    l.length++; // 这里的length 表示的是在顺序表中真正使用的元素
    return true;
}
bool delete_data(SqList &l,int i,int &e){
    if(i < 1 || i > l.length){
        return false;
    }
    e = l.data[i - 1];
    for(int j = i;j < l.length;j++){
        l.data[j-1] = l.data[j];
    }
    l.length--;
    return true;
}
void print(SqList &l){
    for(int i = 0;i < l.length;i++){
        cout << l.data[i] << " ";
    }
}
int main(){
    SqList l;
    init_list(l);
    for(int i = 0;i < 9;i++){
        l.data[i] = 1;
        l.length++;
    }
    insert(l,2,10);
    int target = 10;
    delete_data(l,2,target);
    print(l);


//    sq_list l;
//    init_list_dynamic(l);
//    for(int i = 0;i < l.max_size;i++){
//        l.data[i] = 10;
//     }
//    for(int i =0;i < l.max_size;i++){
//        cout << l.data[i] << " ";
//    }
//    cout << endl;
//    increase_size(l,5);// 扩容，但是此时 l 中是没有数据的
//    for(int i = 0;i < l.max_size;i++){
//        l.data[i] = i;
//    }
//    for(int i = 0;i < l.max_size;i++){
//        cout << l.data[i] << " ";
//    }
    return 0;
}