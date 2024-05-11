//
// Created by 26702 on 2024/5/11.
//
#include <iostream>
using namespace std;
// 二叉链表参考类型
typedef struct Node{
    int data;
    struct Node * Lchild;
    struct Node * Rchild;
}root,*BiTree;

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
    b->data = 1;
    c->data = 1;
    d->data = 1;
    e->data = 1;
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
    b->data = 2;
    c->data = 2;
    d->data = 2;
    e->data = 2;
    f->data = 2;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;
    dummy->next = a;
    return dummy;
}
linked_list combine(linked_list a,linked_list b){
    int len_a = get_list_len(a->next);
    int len_b = get_list_len(b->next);
    l_node * newHead = (l_node *)malloc(sizeof(l_node));
    l_node * temp = newHead;
    l_node * cur_a = a->next;
    l_node * cur_b = b->next;
    if(len_a <= len_b){
       while(cur_a != NULL && cur_b != NULL){
           temp->next = cur_a;
           cur_a = cur_a->next;
           temp = temp->next;
           temp->next = cur_b;
           cur_b = cur_b->next;
           temp = temp->next;
       }
    }else{
        while(cur_a != NULL && cur_b != NULL){
            temp->next = cur_b;
            cur_b = cur_b->next;
            temp = temp->next;
            temp->next = cur_a;
            cur_a = cur_a->next;
            temp = temp->next;
        }
    }
    if(cur_a != NULL){
        temp->next = cur_a;
    }
    if(cur_b != NULL){
        temp->next - cur_b;
    }
    return newHead->next;
}
void print_linked_node(linked_list l){
    l_node * cur = l;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
}
// 假设某非空二叉树以二叉链表作为存储结构，请设计算法打印二叉树中第 k 层 上的所有节点
bool print_level_k(Node *root,int k){
    if(root == NULL || k < 0){
        return false;
    }
    if(k == 0){
        cout << root->data << " ";
        return true;
    }
    bool b1 = print_level_k(root->Lchild,k - 1);
    bool b2 = print_level_k(root->Rchild,k - 1);
    return b1 || b2;
}
// 设计算法判断一个无向图是否是连通图，并打印其连通分量个数，可调用的 dfs,bfs 函数原型如下：
// void dfs(Graph g,int v) 在无向图 g 中深度优先搜索遍历 v 所有的连通子图
// void bfs(Graph g,int v) 在无向图 g 中广度有限搜索遍历 v 所在的连通子图

int main(){
    linked_list a = init_linked_list_a(); // 5
    linked_list b = init_linked_list_b(); // 6
    linked_list c = combine(a,b);
    print_linked_node(c);
}