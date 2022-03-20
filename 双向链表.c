#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;


// ����˫����������

typedef struct Node
{
    ElemType data;
    struct Node* prior;         //ָ��ǰ�����
    struct Node* next;          //ָ���̽��
}Node, * DLinkList;



//˫����Ľ���������β�巨����˫����
DLinkList DLinkListCreatT()
{
    Node* L, * p, * r;
    L = (Node*)malloc(sizeof(Node));//����ͷ���
    L->next = NULL;
    r = L;
    r->next = NULL;                          //r Ϊָ���ն˽���ָ��
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



//˫����Ĳ��ң�����Ԫ��Ϊx��λ��

int DLinkListFind(DLinkList L, ElemType x)
{
    DLinkList p;                //pΪ������
    p = L->next;
    int i = 1;
    while (p != NULL && p->data != x)//Ѱ��ֵΪx��Ԫ��**ע������ѭ������������д��
    {                               //ԭ�򣬵�p == NULL ʱ�� p->data �����
        ++i;                        //  for (i = 1, p = L->next; p; p = p->next, i++) {
                                    //  if (p->data == x) break;}
        p = p->next;
    }

    if (p == NULL)               //���û�ҵ�����0
        return 0;
    else return i;              //����ҵ�����i
}


//˫����Ĳ��룬��˫�����еĵ�i��λ�ò���ֵΪx��Ԫ��

DLinkList DLinkListInsert(DLinkList L, int i, ElemType x)
{
    DLinkList p, s;                          //sΪҪ����Ľ��
    p = L->next;                         //�ӵ�һ�����λ�ÿ�ʼ����
    int j;
    for (j = 1; j < i - 1; j++)
        p = p->next;
    s = (Node*)malloc(sizeof(Node));
    s->data = x;                         //��x��ֵ��s��������
    s->next = p->next;                        //��������
    p->next->prior = s;
    s->prior = p;
    p->next = s;

    return L;

}

//

//˫�����ɾ����ɾ��˫�����е�i�����

DLinkList DLinkListDelete(DLinkList L, int i)
{
    int tempi = 1;
    DLinkList p;                        //pΪ���ҽ�㡣
    p = L->next;
    while ((tempi++) != i && p != NULL)
    {
        p = p->next;
    }
    if (p == NULL)                       //����ǲ�����˫�����е�λ��
        printf("λ�ò��Ϸ���\n");
    else if (p->next == NULL)         //���һ��������⴦��ԭ�����һ�����p->nextû��prior
    {
        p->prior->next = NULL;
        free(p);
    }
    else                                //����ɾ������
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

//�ж������Ƿ�Ϊ��
int IsEmptyDbLinkList(DLinkList pHead)
{
    DLinkList pt = pHead->next;

    if (pt == NULL)
        return 1;
    else
        return 0;
}
//��ӡ����
void TraverseDbLinkList(DLinkList pHead)
{
    if (IsEmptyDbLinkList(pHead))
    {
        printf("����Ϊ�գ�\n");
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
//���������
int GetLengthDbLinkList(DLinkList pHead)
{
    int i = 0;//����
    DLinkList p = (DLinkList)malloc(sizeof(Node));
    p = pHead->next;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}