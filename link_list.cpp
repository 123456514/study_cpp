//
// Created by 26702 on 2024/5/10.
//
#include <iostream>
using namespace std;

typedef struct l_node{
    int data;
    struct l_node *next;
}l_node,*linked_list;

bool init_list(linked_list &l){
    l = NULL;
    return true;
}

bool init_list_have_head(linked_list &l){
    l = (l_node *) malloc(sizeof(l_node));
    if(l == NULL){
        return false;
    }
    l->next = NULL;
    return true;
}

bool insert_node(linked_list &l,int i,int num){
    if(i < 1)
        return false;
    l_node *p = l;
    int j = 0;
    while(p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    if(p == NULL)
        return false;
    // 申请空间，添加节点
    l_node * node = (l_node*) malloc(sizeof(l_node));
    node->data = num;
    node->next = p->next;
    p->next = node;
    return true;
}
bool delete_node(linked_list &l,int i,int &e){
    if(i < 1)
        return false;
    l_node *p = l;
    int j = 0;
    while(p != NULL && j < i - 1){
        p = p->next;
        j++;
    }
    // p 表示的是 删除节点的前一个节点
    if(p == NULL)
        return false;
    if(p->next == NULL)
        return false;
    l_node *q= p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
// 删除链表中的指定节点
// 使用两个指针，一个为 cur 一个为 pre
void delete_node_index(l_node *p){
    // 删除节点 p

}
// 2023 年
// 已知带头结点的链表la 和 lb 其元素均为非递减有序排列，编写算法利用原链表节点空间，将链表la 和 lb 合并为非递减有序序列的单链表 lc
linked_list combine(linked_list la,linked_list lb){
    if(la == NULL)
        return lb;
    if(lb == NULL)
        return la;
    if(la == NULL && lb == NULL)
        return NULL;
    l_node * node1 = la->next;
    l_node * node2 = lb->next;
    linked_list lc = la;
    l_node * p = lc;
    while(node1->next != NULL && node2->next != NULL){
        if(node1->data < node2->data){
            p->next = node1;
            p = node1;
            node1 = node1->next;
        }else{
            p->next = node2;
            p = node2;
            node2 = node2->next;
        }
    }
    if(node2->next !=NULL){
        p->next = node2;
    }
    if(node1->next != NULL){
        p->next = node1;
    }
    return lc->next;
}





// 找到链表的 第 i 个位置的节点
// 如果 i == 0 直接返回 l 如果 i < 0 返回NULL 否则 遍历链表中的节点，j用来记位
// l->next表示的是链表的真正的节点，因为第一个要遍历的节点不需要遍历，那么此时就把第一位直接记位1 => j = 1
// i 表示的是界限，
// -1 ----> 1  --->   2  -----> 3   ---->  4
//          j                   i
//          p
l_node * get_elem(linked_list l,int i){
    int j = 1;
    l_node * p = l->next;
    if(i == 0){
        return l;
    }
    if(i < 1){
        return NULL;
    }
    while(p != NULL && j <i){
        p = p->next;
        j++;
    }
    return p;
}
// l 表示的是一个带有头结点的链表，头结点就相当于虚拟节点
l_node * get_node(linked_list l,int i){
    if(i == 0){
        return l->next;
    }
    l_node * cur = l;
    while(cur != NULL && i != 0){
        cur = cur->next;
        i--;
    }
    return cur;
}

int main(){
    linked_list l;
    init_list_have_head(l);
    return 0;
}