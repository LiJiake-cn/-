#include<stdio.h>
#include<stdlib.h>

/*
InitList(&L) 初始化表，创建一个空的线性表
Length(L) 求表长。返回线性表L的长度
LocateElem(L,e) 按值查找
GetElem(L,e) 按位查找
ListInsert(&L,i,e) 插入操作。在表L中的第i个位置插入元素e
ListDelete(&L,i,&e) 删除操作。删除表L中的第i个元素并用e返回
PrintList(L) 输出操作
Empty(L) 判空操作。若L为空表，返回true 否则返回false
DestroyList(&L) 销毁操作。
*/

typedef int ElemType;//线性表元素类型

#define MaxSize 100//线性表的最大长度

typedef struct {
    ElemType data[MaxSize];// 存储空间基址
    int length;// 当前长度
} SqList;// 顺序线性表

// 初始化线性表
void InitList(SqList &L) {
    for (int i = 0; i < MaxSize; i++) {
        L.data[i] = 0; // 初始化元素为0
        L.length = 0; // 初始化长度为0
    }
}

/*
//动态分配
void CreateList(SqList &L) {
    L.data = (ElemType *)malloc(InitSize * sizeof(ElemType)); // 动态分配内存
    L.MaxSize = InitSize; // 设置初始大小
    L.length = 0; // 初始化长度为0
}

//增加线性表的长度
void IncreaseList(SqList &L,int len) {
    int *p=L.data; // 保存旧的指针
    L.data= (ElemType *)malloc((L.MaxSize + len) * sizeof(ElemType)); // 分配新的内存空间
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i]; // 复制旧数据到新空间
    }
    free(p); // 释放旧的内存空间
    L.MaxSize=L.MaxSize+len; // 增加最大长度
}
*/

//插入操作 时间复杂度为0(n)
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) { // 检查插入位置是否合法
        printf("插入位置不合法\n");
        return;
    }
    if (L.length >= MaxSize) { // 检查线性表是否已满
        printf("线性表已满，无法插入\n");
        return;
    }
    for (int j = L.length; j >= i; j--) { // 将插入位置及之后的元素后移
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 插入新元素
    L.length++; // 更新长度
    return true;
}

//删除操作 时间复杂度为0(n)
bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) { // 检查删除位置是否合法
        printf("删除位置不合法\n");
        return false;
    }
    e = L.data[i - 1]; // 保存被删除的元素
    for (int j = i; j < L.length; j++) { // 将删除位置之后的元素前移
        L.data[j - 1] = L.data[j];
    }
    L.length--; // 更新长度
    return true;
}

//按位查找 时间复杂度为0(1)
bool GetElem(SqList L, int i, ElemType &e) {
    if (i < 1 || i > L.length) { // 检查查找位置是否合法
        printf("查找位置不合法\n");
        return false;
    }
    e = L.data[i - 1]; // 获取元素
    return true;
}

//按值查找 时间复杂度为0(n)
int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) { // 找到元素
            return i + 1; // 返回位置（1-based）
        }
    }
    return 0; // 未找到元素
}//注意：C语言中，结构体的比较不能直接用==，需要逐个成员比较
/*if (a.num == b.num && a.name == b.name) { 
    printf ("相等");
} else {
    printf( "不相等");
}*/

//求表长 时间复杂度为0(1)
int Length(SqList L) {
    return L.length; // 返回当前长度
}

//判空操作 时间复杂度为0(1)
bool Empty(SqList L) {
    return L.length == 0; // 判断是否为空
}
//销毁操作 时间复杂度为0(1)
void DestroyList(SqList &L) {   
    L.length = 0; // 重置长度
    // 对于静态分配的顺序表，不需要释放内存
    // 如果是动态分配的顺序表，需要释放内存
    // free(L.data);
}
