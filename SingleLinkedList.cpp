#include<stdio.h>
#include<stdlib.h>

typedef int ElemType; // 定义线性表元素类型为int
typedef struct LNode {
    ElemType data; // 节点数据
    struct LNode *next; // 指向下一个节点的指针
} LNode, *LinkList;

// 初始化单链表
void InitList(LinkList &L) {
    L = (LinkList)malloc(sizeof(LNode)); // 分配头结点
    if (L == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    L->next = NULL; // 头结点的next指针指向NULL
}

//单链表的按位插入 时间复杂度为0(n) 在第i个位置插入元素e
bool ListInsert(LinkList &L, int i, ElemType e) {
    if (i < 1) { // 检查插入位置是否合法
        printf("插入位置不合法\n");
        return false;
    }
    LNode *p = L; // 从头结点开始
    int j = 0; // 当前位置计数器
    while (p != NULL && j < i - 1) { // 找到第i-1个节点
        p = p->next;
        j++;
    }
    if (p == NULL) { // 如果位置超过链表长度
        printf("插入位置超过链表长度\n");
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
    if (s == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    s->data = e; // 设置新节点数据
    s->next = p->next; // 新节点指向第i个节点
    p->next = s; // 第i-1个节点指向新节点
    return true;
}

//指定节点的后插操作 时间复杂度为0(1) 在节点p后插入元素e
bool ListInsertNextNode(LNode *p, ElemType e) {
    if (p == NULL) { // 检查节点是否合法
        printf("指定节点为空，无法插入\n");
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
    if (s == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    s->data = e; // 设置新节点数据
    s->next = p->next; // 新节点指向p的下一个节点
    p->next = s; // p指向新节点
    return true;
}
//指定节点的前插操作 时间复杂度为0(n) 在节点p前插入元素e
bool ListInsertPriorNode(LinkList &L, LNode *p, ElemType e) {
    if (p == NULL) { // 检查节点是否合法
        printf("指定节点为空，无法插入\n");
        return false;
    }
    LNode *pre = L; // 从头结点开始
    while (pre->next != p && pre != NULL) { // 找到p的前驱节点
        pre = pre->next;
    }
    if (pre == NULL) { // 如果没有找到前驱节点
        printf("指定节点不在链表中，无法插入\n");
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
    if (s == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    s->next=p->next; // 新节点指向p的下一个节点
    p->next=s; // p指向新节点
    s->data=p->data;// s节点存储原p数据
    p->data=e; // p节点存储新数据
    return true;
}

//删除操作 时间复杂度为0(n) 删除第i个位置的元素
bool ListDelete(LinkList &L, int i, ElemType &e) {
    if (i < 1) { // 检查删除位置是否合法
        printf("删除位置不合法\n");
        return false;
    }
    LNode *p = L; // 从头结点开始
    int j = 0; // 当前位置计数器
    while (p->next != NULL && j < i - 1) { // 找到第i-1个节点
        p = p->next;
        j++;
    }
    if (p->next == NULL || j < i - 1) { // 如果位置超过链表长度
        printf("删除位置超过链表长度\n");
        return false;
    }
    LNode *q = p->next; // q指向第i个节点
    e = q->data; // 保存被删除节点的数据
    p->next = q->next; // 第i-1个节点指向第i+1个节点
    free(q); // 释放被删除节点的内存
    return true;
}
//删除指定节点p 时间复杂度为0(1)
bool DeleteNode(LNode *p) {
    if (p == NULL) { // 检查节点是否合法
        printf("指定节点为空，无法删除\n");
        return false;
    }
    if (p->next == NULL) { // 如果p是最后一个节点，无法删除
        printf("无法删除最后一个节点\n");
        return false;
    }
    LNode *q = p->next; // q指向p的下一个节点
    p->data = q->data; // 将q的数据复制到p
    p->next = q->next; // p指向q的下一个节点
    free(q); // 释放q的内存
    return true;
}

//按位查找 时间复杂度为0(n) 查找第i个位置的元素
bool GetElem(LinkList L, int i, ElemType &e) {
    if (i < 1) { // 检查查找位置是否合法
        printf("查找位置不合法\n");
        return false;
    }
    LNode *p = L->next; // 从第一个节点开始
    int j = 1; // 当前位置计数器
    while (p != NULL && j < i) { // 找到第i个节点
        p = p->next;
        j++;
    }
    if (p == NULL) { // 如果位置超过链表长度
        printf("查找位置超过链表长度\n");
        return false;
    }
    e = p->data; // 获取节点数据
    return true;
}
//按值查找 时间复杂度为0(n) 查找值为e的元素
LNode* LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next; // 从第一个节点开始
    while (p != NULL) { // 遍历链表
        if (p->data == e) { // 找到元素
            return p; // 返回节点指针
        }
        p = p->next; // 移动到下一个节点
    }
    return NULL; // 未找到元素，返回NULL
}

//单链表的头插法
bool ListInsertHead(LinkList &L, ElemType e) {
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
    if (s == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    L->next=NULL; // 初始化头结点的指针，养成习惯，只要初始化单链表，都要把头指针指向NULL
    s->data = e; // 设置新节点数据
    s->next = L->next; // 新节点指向原头结点的下一个节点
    L->next = s; // 头结点指向新节点
    return true;
}//链表的逆置
//单链表的尾插法
bool ListInsertTail(LinkList &L, ElemType e) {
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
    if (s == NULL) {
        printf("内存分配失败\n");
        return false;
    }
    s->data = e; // 设置新节点数据
    s->next = NULL; // 新节点的next指针指向NULL

    LNode *p = L; // 从头结点开始
    while (p->next != NULL) { // 找到最后一个节点
        p = p->next;
    }
    p->next = s; // 最后一个节点指向新节点
    return true;
    /*
    // 另一种实现方式
    ElemType x;
    L= (LinkList)malloc(sizeof(LNode)); // 分配头结点
    LNode *s,*r=L; // s为新节点，r为尾节点
    sance("%d",&x); // 输入新节点数据
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
        s->data = x; // 设置新节点数据
        s->next = NULL; // 新节点的next指针指向NULL
        r->next = s; // 尾节点指向新节点
        r = s; // 更新尾节点为新节点
        scanf("%d", &x); // 输入下一个新节点数据
    }
    r->next = NULL; // 最后一个节点的next指针指向NULL
    return true;
    */
}
