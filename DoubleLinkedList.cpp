//双链表的初始化，插入，删除，遍历等操作
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType; // 定义线性表元素类型为int
typedef struct DNode {
    ElemType data; // 节点数据
    struct DNode *next; // 指向下一个节点的指针,后继
    struct DNode *prior; // 指向上一个节点的指针，前驱
} DNode, *DoubleLinkList;

// 初始化双链表
bool InitList(DoubleLinkList &L) {
    L = (DoubleLinkList)malloc(sizeof(DNode)); // 分配头结点
    if (L == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    L->next = NULL; // 头结点的next指针指向NULL
    L->prior = NULL; // 头结点的prior指针指向NULL
}//DoubleLinkList等价于DNode*

//双链表的按位插入 时间复杂度为0(n) 在p节点后插入s节点
bool ListInsert(DoubleLinkList &L, DNode *p, ElemType e) {
    if (p == NULL) { // 检查节点是否合法
        printf("指定节点为空，无法插入\n");
        return false;
    }
    DNode *s = (DNode *)malloc(sizeof(DNode)); // 创建新节点
    if (s == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    s->data = e; // 设置新节点数据
    s->next = p->next; // 新节点指向p的下一个节点
    s->prior = p; // 新节点的前驱指向p
    if (p->next != NULL) { // 如果p不是最后一个节点
        p->next->prior = s; // 下一个节点的前驱指向新节点
    }
    p->next = s; // p指向新节点
    return true;
}

//删除操作 时间复杂度为0(n) 删除p节点的后继节点
bool ListDelete(DoubleLinkList &L, DNode *p, ElemType &e) {
    if (p == NULL || p->next == NULL) { // 检查节点是否合法
        printf("指定节点为空或没有后继节点，无法删除\n");
        return false;
    }
    DNode *q = p->next; // q指向p的后继节点
    e = q->data; // 保存被删除节点的数据
    p->next = q->next; // p指向q的下一个节点
    if (q->next != NULL) { // 如果q不是最后一个节点
        q->next->prior = p; // 下一个节点的前驱指向p
    }
    free(q); // 释放被删除节点的内存
    return true;
}

//双链表不可随机存取，只能按位查找 时间复杂度为0(n) 查找第i个位置的元素。