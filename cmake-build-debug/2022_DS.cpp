//
// Created by 26702 on 2024/5/11.
//
#include<iostream>
using namespace std;

// 二叉链表参考类型
typedef struct TreeNode{
    int data;
    struct TreeNode * Lchild;
    struct TreeNode * Rchild;
}TreeNode,*BiTree;

typedef struct l_node{
    int data;
    struct l_node * next;
}l_node,*linked_list;
// 线性表 A,B C 均以带头结点的单链表 合并两个单链表
// A a1 a2 a3
// B b1 b2 b3
// 题意就是 如果 A 链表长 那么就是   B   ---->   A  否则 就是 A ----- B
int get_list_len(linked_list list){
    int len = 1;
    l_node * cur = list;
    while(cur != NULL){
        len++;
        cur = cur->next;
    }
    return len;
}

linked_list init_linked_list_a(){
    l_node * dummy = (l_node *)malloc(sizeof(l_node));
    l_node * a = (l_node *)malloc(sizeof(l_node));
    l_node * b = (l_node *)malloc(sizeof(l_node));
    l_node * c = (l_node *)malloc(sizeof(l_node));
    l_node * d = (l_node *)malloc(sizeof(l_node));
    l_node * e = (l_node *)malloc(sizeof(l_node));
    dummy->data = -1;
    a->data = 1;
    b->data = 3;
    c->data = 5;
    d->data = 7;
    e->data = 9;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = NULL;
    dummy->next = a;
    return dummy;
}
linked_list init_linked_list_b(){
    l_node * dummy = (l_node *)malloc(sizeof(l_node));
    l_node * a = (l_node *)malloc(sizeof(l_node));
    l_node * b = (l_node *)malloc(sizeof(l_node));
    l_node * c = (l_node *)malloc(sizeof(l_node));
    l_node * d = (l_node *)malloc(sizeof(l_node));
    l_node * e = (l_node *)malloc(sizeof(l_node));
    l_node * f = (l_node *)malloc(sizeof(l_node));
    dummy->data = -1;
    a->data = 2;
    b->data = 4;
    c->data = 6;
    d->data = 8;
    e->data = 10;
    f->data = 12;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;
    dummy->next = a;
    return dummy;
}

// 已知带头结点的单链表 la 和 lb 某元素均为非递减有序排列，编写算法利用表节点空间，将链表 la 和 lb 合并为非递减有序连
linked_list combine(linked_list a,linked_list b){
    l_node * cur_a = a->next;
    l_node * cur_b = b->next;
    linked_list c = NULL;
    if(cur_a->data <= cur_b->data) {
        c = a;
    }else{
        c = b;
    }
    l_node * temp = c;
    while(cur_a != NULL && cur_b != NULL){
        if(cur_a->data <= cur_b->data){
            temp->next = cur_a;
            cur_a = cur_a->next;
        }else{
            temp->next = cur_b;
            cur_b = cur_b->next;
        }
        temp = temp->next;
    }
    if(cur_a != NULL){
        temp->next = cur_a;
    }
    if(cur_b != NULL){
        temp->next = cur_b;
    }
    return c->next;
}
void print_linked_node(linked_list l){
    l_node * cur = l;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
}
// 在二叉链表存储的二叉树中，已知某节点数据元素 x 该节点最多存在一个，求该节点的双亲节点
// 算法思想： 逐层打印节点，找到这个节点之后，记录这个节点的下标，然后 下标
// 如果是头结点
// 如果不是头结点，那么根据奇偶数 判断左右节点，然后 除以 2 得到父节点，然后遍历二叉树得到对应的节点
// 如果要使用层序遍历，那么此时就要使用到 queue 那么就要写好多的代码

// 这里还是使用 递归解决
TreeNode * get_node_parent(BiTree tree,int num){
    if(tree == NULL){
        return NULL;
    }
    if((tree->Lchild != NULL && tree->Lchild->data == num) || (tree->Rchild != NULL && tree->Rchild->data == num)){
        return tree;
    }
    get_node_parent(tree->Lchild,num);
    get_node_parent(tree->Rchild,num);
}


// 编写算法，实现以字符串形式输入的简单表达式求和 表达式的运算法仅有 + - * / % 并且已知函数 float GetValue(char ch[],int start)
// 能返回字符串从start 位置开始的第一个数字
// 例如 若 ch = "1.2 + 3.4 * 5.6 + 7.8" 则GetValue(ch,1) 返回的值是1.2 GetValue(ch,5) 返回的是 3.4


// 已知有向图 G的邻接表存储方式，计算图G中每个节点的入度和出度
int main(){
    linked_list a = init_linked_list_a();
    linked_list b = init_linked_list_b();
    linked_list c = combine(a,b);
    print_linked_node(c);
    return 0;
}
