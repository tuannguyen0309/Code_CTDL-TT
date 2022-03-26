#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
    int num;
    struct listnode *next;
} ListNode;

typedef struct linkedList
{
    ListNode *head;
    ListNode *tail;
    int size;
} LinkedList;

void printList(ListNode *head)
{
    ListNode *cur = head;
    if (cur == NULL)
    {
        printf("Danh sach lien ket khong co phan tu nao");
    }
    while (cur != NULL)
    {
        printf("%d\t", cur->num);
        cur = cur->next;
    }
}

ListNode *findNode(ListNode *head, int i)
{
    ListNode *cur = head;
    if (head == NULL || i < 0)
    {
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai\n");
        return NULL;
    }
    while (i > 0)
    {
        cur = cur->next;
        if (cur == NULL)
        {
            printf("Phan tu tim kiem khong ton tai\n");
            return NULL;
        }
        i--;
    }
    if (cur != NULL)
        printf("Phan tu can tim kiem l�: %d\n", cur->num);
    return cur;
}

void insertNode(ListNode **ptrhead, int index, int value)
{
    ListNode *cur, *newNode;
    if (ptrhead == NULL || index == 0)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *ptrhead;
        *ptrhead = newNode;
    }
    else if ((cur = findNode(*ptrhead, index - 1)) != NULL)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else
        printf("Kh�ng the them phan tu moi v�o vi tr� index = %d\n", index);
}

void removeNode(ListNode **ptrhead, int index)
{
    ListNode *cur, *pre;
    if (index == 0)
    {
        cur = *ptrhead;
        *ptrhead = cur->next;
        free(cur);
    }
    else
    {
        pre = findNode(*ptrhead, index - 1);
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
}

typedef struct stack
{
    LinkedList ll;
} Stack;

void push(Stack *s, int item)
{
    insertNode(&(s->ll.head), 0, item);
    s->ll.size++;
}

int isEmptyStack(Stack *s)
{
    if ((s->ll).size == 0)
        return 1;
    else
        return 0;
}

int pop(Stack *s)
{
    int item;
    if (isEmptyStack(s) == 0)
    {
        item = s->ll.head->num;
        removeNode(&(s->ll.head), 0);
        s->ll.size--;
        return item;
    }
    else
    {
        printf("Ngan xep rong");
        return 0;
    }
}

int peekS(Stack *s)
{
    int item;
    if (isEmptyStack(s) == 0)
    {
        item = s->ll.head->num;
        return item;
    }
    else
        return 0;
}

int main()
{

    Stack *s = malloc(sizeof(Stack));
    s->ll.head = NULL;
    s->ll.size = 0;
    //Ham push
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("stack ban dau la: ");
    printList(s->ll.head);
//    printf("\nstack sau khi them du lieu la: ");
//    push(s, 4);
//    printList(s->ll.head);
//    isEmptyStack(s);
//    pop(s);
//    printf("\nStack sau khi pop la:");
//    printList(s->ll.head);
//    printf("\nStack sau khi peek la:");
//    printf("%d\n", peekS(s));
//    


}
