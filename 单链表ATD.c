#include<stdio.h>
#include<stdlib.h>
#include<windows.h>


typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode* next;
} LNode, * LinkedList;

typedef enum Status {
    error,
    success
} Status;

//����������
Status InitList(LinkedList* L);
void DestroyList(LinkedList* L);//��������
Status InsertList(LNode* p, ElemType data);//����ڵ�
Status DeleteList(LNode* p, ElemType e);//ɾ�����
void TraverseList(LinkedList L);//�������
Status SearchList(LinkedList L, ElemType e);//��������
Status ReverseList(LinkedList* L);//��ת����
Status IsLoopList(LinkedList L);
LNode* FindMidNode(LinkedList L);
void show();

void show()
{
    system("cls");
    printf("\n\n\n\n������ADT\n\n");
    printf("1.����������\n");
    printf("2.��������\n");
    printf("3.������\n");
    printf("4.ɾ�����\n");
    printf("5.��������\n");
    printf("6.��������\n");
    printf("7.��ת����\n");
    printf("8.�ж������Ƿ�ɻ�\n");
    printf("9.��ת�����е�ż�����/�޴˹���\n");
    printf("10.�����м���\n");
    printf("11.�˳�\n");
    printf("\n�������Ӧ������(1-11)��");
}

int main(void)
{
    int choice, num = 0;
    LinkedList head = NULL;

    do
    {
        show();
        scanf_s("%d", &choice);
        //ѡ����
        switch (choice)
        {
        case 1://����������
        {
            if (InitList(&head))
            {
                printf("���������ɹ�\n");
            }
            else
            {
                printf("��������ʧ��\n");
            }
            break;
        }
        case 2://��������
        {
            DestroyList(&head);
            printf("�����������\n");
            break;
        }
        case 3://��������
        {
            if (head == NULL)
            {
                printf("����Ϊ�գ� ���ȴ�������\n");
            }
            else
            {
                printf("���������ݣ�");
                scanf_s("%d", &num);
                if (InsertList(head, num))
                {
                    printf("���ݲ���ɹ�\n");
                }
                else
                {
                    printf("���ݲ���ʧ��\n");
                }
            }
            break;
        }
        case 4://ɾ������
        {
            printf("����ɾ���ĸ����ݣ�");
            scanf_s("%d", &num);
            if (DeleteList(head, num))
            {
                printf("����ɾ���ɹ�\n");
            }
            else
            {
                printf("����ɾ��ʧ��\n");
            }
            break;
        }
        case 5://��������
        {
            if (head == NULL || head->next == NULL)
            {
                printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
            }
            else
            {
                TraverseList(head);
            }
            break;
        }
        case 6://��������
        {
            printf("��������Ҫ���ҵ����ݣ�");
            scanf_s("%d", &num);
            if (SearchList(head, num))
            {
                printf("��������\n");
            }
            else
            {
                printf("����������\n");
            }
            break;
        }
        case 7://��ת����
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ�ջ�������ֻ�����������\n");
                printf("����תʧ��\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("����ת�ɹ�\n");
                }
                else
                {
                    printf("����תʧ��\n");
                }

            }
            break;
        }
        case 8://�ж������Ƿ�ɻ�
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ��\n");
            }
            else
            {
                if (IsLoopList(head))
                {
                    printf("����ɻ�\n");
                }
                else
                {
                    printf("����û�гɻ�\n");
                }
            }
            break;
        }
        case 9://��ת�����е�ż�����
        {
            break;
        }
        case 10://�����м���
        {
            if (head == NULL || head->next == NULL)
            {
                printf("���ǿ�����\n");
            }
            else
            {
                printf("�����м䴢���ֵΪ%d\n", (FindMidNode(head))->data);
            }
            break;
        }
        case 11://��������
        {
            DestroyList(&head);
            goto end;
        }
        default:
        {
            printf("�������������֣�(1-11)\n");
            break;
        }
        }
        getchar();
        system("pause");
    } while (1);

end:

    return 0;
}

Status InitList(LinkedList* L) {
    LinkedList list;

    list = (LinkedList)malloc(sizeof(LNode));
    if (list == NULL)//�ڴ����ʧ��
    {
        return error;
    }
    list->next = NULL;
    *L = list;

    return success;
}

void DestroyList(LinkedList* L) {
    LinkedList temp;

    while (*L != NULL)
    {
        temp = *L;
        *L = (*L)->next;
        free(temp);
    }
}

Status InsertList(LNode* p, ElemType data) {
    LinkedList current = p;
    LinkedList newNode = (LinkedList)malloc(sizeof(LNode));
    //�����½ڵ�
    if (newNode == NULL)//�ڴ����ʧ��
    {
        return error;
    }
    newNode->data = data;
    newNode->next = NULL;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return success;
}

Status DeleteList(LNode* p, ElemType e) {
    LinkedList posNode = p->next;//˵Ҫɾ����ָ�����
    LinkedList posNodeFront = p;//ָ��������һ���ڵ�
    if (posNode == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ��\n");
    }
    else
    {
        while (posNode->data != e)
        {
            posNodeFront = posNode;
            posNode = posNode->next;
            //�����ǰ�ڵ�����ݲ���ָ��Ҫɾ�������ݣ�����Ѱ��ָ�����
            if (posNode == NULL)
            {
                printf("û�и�����\n");
                return error;
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);//�ҵ���㲢ɾ������
        return success;
    }
}

void TraverseList(LinkedList L) {
    LinkedList temp;

    temp = L->next;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Status SearchList(LinkedList L, ElemType e) {
    while (L != NULL)
    {
        if (L->data == e)
        {
            return success;
        }
        L = L->next;
    }
    return error;
}

/*
void ReverseList(LinkedList L) {
    LinkedList current, next, pre;
    current = L->next;
    pre = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    L->next = pre;
}
*/
Status ReverseList(LinkedList* L) {
    LNode* newHead;		//����ÿ�η�ת��ĵ�һ���ڵ� 
    LNode* p1;			//ÿ�ζ�ָ��ǰһ���ڵ�	
    LNode* p2;			// ����δ��תǰ����һ���ڵ� 
    p1 = (*L)->next;
    p2 = p1->next;
    p1->next = NULL;
    newHead = p1;
    while (p2 != NULL) {
        p1 = p2;
        p2 = p1->next;
        p1->next = newHead;
        newHead = p1;
    }
    (*L)->next = newHead;
}

LNode* FindMidNode(LinkedList L) {
    LinkedList slow = L, fast = L;
    while (fast != NULL && slow != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Status IsLoopList(LinkedList L) {
    LinkedList fast = L, slow = L;
    while (fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        if ((fast = fast->next->next) == NULL)
            return error;
        if (fast == slow)
            return success;
    }
    return error;
}
