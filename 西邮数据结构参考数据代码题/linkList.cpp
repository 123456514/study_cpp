//
// Created by 26702 on 2024/5/12.
//

#include <iostream>
using namespace std;
#define MaxSize 10
typedef struct link_node{
    int data;
    struct link_node * next;
}Node ,*linkedList;


typedef struct list{
    int data[MaxSize];
    int last;
}list,*arrayList;
// 1.在链表中找到和 key值相同的节点 并返回
Node * get_node_index(linkedList &l,int key){
    if(l == NULL){
        return NULL;
    }
    Node * cur = l->next;
    while(cur != NULL){
        if(cur->data == key){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
// 2. 头插法建立链表
linkedList  createFromHead(){
    linkedList  l = (linkedList) malloc(sizeof(Node));
    l->next = NULL;
    Node * node;
    int flag = 1;
    int num;
    while(flag){
        cin >> num;
        if(num != -1){
            node = (Node *)malloc(sizeof (Node));
            node->data = num;
            node->next = l->next;
            l->next = node;
        }else{
            flag = 0;
        }
    }
    return l;
}
// 3. 尾插法
linkedList createFromTail(){
    linkedList l = (linkedList)malloc(sizeof (linkedList));
    l->next = NULL;
    Node * r = l;
    Node *s;
    int flag = 1;
    int num;
    while(flag){
        cin >> num;
        if(num != -1){
           s = (Node *)malloc(sizeof(Node));
           r->next = s;
           r = s;
        }else{
            flag = 0;
            r->next = NULL;
        }
    }
    return l;
}
// 4. 已知有两个顺序表 la 和 lb 非递减 合并成一个大的非递减
arrayList combine(arrayList &la,arrayList & lb){
    if(la == NULL) return lb;
    if(lb == NULL) return la;
    list * l1 = la;
    list * l2 = lb;
    int i = 0;
    int j = 0;
    int k = 0;
    arrayList lc = (arrayList) malloc(sizeof(arrayList));
    list * l3 = lc;
    while(i <= l1->last && j <= l2->last){
        if(l1->data[i] <= l2->data[j]){
            l3->data[k++] = l1->data[i++];
        }else{
            l3->data[k++] = l2->data[j++];
        }
        l3->last++;
    }
    while(i <= l1->last){
        l3->data[k++] = l1->data[i++];
    }
    while(j <= l2->last){
        l3->data[k++] = l2->data[j++];
    }
    return lc;
}
// 5. 对带头结点的单链表实现就地逆置
void reverse(linkedList &l){
    link_node * cur = l->next;
    link_node * pre = NULL;
    while(cur != NULL){
        link_node * curNext = cur->next;
        cur->next = pre;
        pre = cur;
        cur = curNext;
    }
}
// 6. 已知线性表中的元素以值递增有序排列，并以单链表作为粗出结构，设计一个高效的算法，删除表中所有值相同的多余元素 使得操作之后的线性表中所有元素的值均不相同，同时释放被删节点空间

// 7. 已知指针 ha 和 hb 分别指向两个单链表的头结点，并且已知两个链表的长度分别为 m 和 n 试设计一个算法将两个链表连接在一起 即另其中一个表的首元节点连在另一个表的最后一个节点之后
// 假设指针 hc 指向连接后的链表的头结点，并要求算法以尽可能短的时间完成连接运算


// 8. 设单链表中存放着 n 个字符，计算判断字符串是否是中心对称

// 9. 已知带头结点的单链表集合，假设集合A用单链表la表示 集合B 用单链表LB 表示 设法计算出两个集合的差 即 A - B

// 10. 假设某循环单链表非空，且无表头节点也无表头指针，指针 P指向该链表中的某节点，设计一个算法 将 p 所指向的节点的后继节点变为 p 所指向的前驱节点

// 11. 有两个单链表 la lb 元素非递减 有序排列，编写一个算法，将他们合并成一个单链表 lc lc 非递减有序排列

// 12. 设指针 la 和 lb 分别指向两个无头节点单链表中的首元节点，试设计从表la 中删除自第 i 个元素起共len 个元素，并将他们插入到表lb 的第j 个元素之后的算法

// 13. 已知两个按元素递增的链表 A 和 B 设计一算法利用原表的节点空间形成两个新链表 A 和 B 使得 A* = A U B ,B* = A n B

int main(){

    return 0;
}
// 1. 在带头结点的单链表L 中查找其节点值等于 key 的节点，若找到则返回该节点的位置p,否则返回 NULL
