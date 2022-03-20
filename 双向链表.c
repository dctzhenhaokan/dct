#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;


// 定义双链表结点类型

typedef struct Node
{
    ElemType data;
    struct Node* prior;         //指向前驱结点
    struct Node* next;          //指向后继结点
}Node, * DLinkList;



//双链表的建立，采用尾插法建立双链表
DLinkList DLinkListCreatT()
{
    Node* L, * p, * r;
    L = (Node*)malloc(sizeof(Node));//申请头结点
    L->next = NULL;
    r = L;
    r->next = NULL;                          //r 为指向终端结点的指针
    ElemType x;
    while (scanf_s("%d", &x) != EOF)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->next = r->next;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return L;
}



//双链表的查找，查找元素为x的位置

int DLinkListFind(DLinkList L, ElemType x)
{
    DLinkList p;                //p为检索，
    p = L->next;
    int i = 1;
    while (p != NULL && p->data != x)//寻找值为x的元素**注意这里循环的条件不能写反
    {                               //原因，当p == NULL 时候 p->data 会出错
        ++i;                        //  for (i = 1, p = L->next; p; p = p->next, i++) {
                                    //  if (p->data == x) break;}
        p = p->next;
    }

    if (p == NULL)               //如果没找到返回0
        return 0;
    else return i;              //如果找到返回i
}


//双链表的插入，在双链表中的第i个位置插入值为x的元素

DLinkList DLinkListInsert(DLinkList L, int i, ElemType x)
{
    DLinkList p, s;                          //s为要插入的结点
    p = L->next;                         //从第一个结点位置开始查找
    int j;
    for (j = 1; j < i - 1; j++)
        p = p->next;
    s = (Node*)malloc(sizeof(Node));
    s->data = x;                         //将x赋值到s的数据域
    s->next = p->next;                        //将结点插入
    p->next->prior = s;
    s->prior = p;
    p->next = s;

    return L;

}

//

//双链表的删除，删除双链表中第i个结点

DLinkList DLinkListDelete(DLinkList L, int i)
{
    int tempi = 1;
    DLinkList p;                        //p为查找结点。
    p = L->next;
    while ((tempi++) != i && p != NULL)
    {
        p = p->next;
    }
    if (p == NULL)                       //检查是不是在双链表中的位置
        printf("位置不合法。\n");
    else if (p->next == NULL)         //最后一个结点特殊处理，原因最后一个结点p->next没有prior
    {
        p->prior->next = NULL;
        free(p);
    }
    else                                //进行删除操作
    {
        p->prior->next = p->next;
        p->next->prior = p->prior;
        free(p);
    }
}
void TraverseDbLinkList(DLinkList pHead)
{
    DLinkList pt = pHead->next;
    while (pt != NULL)
    {
        printf("%d ", pt->data);
        pt = pt->next;
    }
    putchar('\n');
}

//判断链表是否为空
int IsEmptyDbLinkList(DLinkList pHead)
{
    DLinkList pt = pHead->next;

    if (pt == NULL)
        return 1;
    else
        return 0;
}
//打印链表
void TraverseDbLinkList(DLinkList pHead)
{
    if (IsEmptyDbLinkList(pHead))
    {
        printf("链表为空！\n");
    }
    else
    {
        DLinkList p = (DLinkList)malloc(sizeof(Node));
        p = pHead->next;
        while (p)
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }
}
//获得链表长度
int GetLengthDbLinkList(DLinkList pHead)
{
    int i = 0;//计数
    DLinkList p = (DLinkList)malloc(sizeof(Node));
    p = pHead->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}