#include <iostream>
using namespace std;
// 第一章数据结构线性表
// 链表 + 数组 创建销毁增删查改

/**
 * &l 表示的是引用类型 对参数的修改结构要带回来
 */
void test(int &x){
    x = 1024;
    printf("test 函数内部的 x = %d\n" ,x);
}
int main() {
    int x = 1;
    test(x);
    printf("main 函数 x = %d\n",x);
    printf("你好");
    return 0;
}
