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
		printf("Phan tu can tim kiem la: %d\n", cur->num);
	return cur;
}

void insertNode(ListNode **phead, int index, int value)
{
	ListNode *cur, *newNode;
	if (phead == NULL || index == 0)
	{
		newNode = malloc(sizeof(ListNode));
		newNode->num = value;
		newNode->next = *phead;
		*phead = newNode;
	}
	else if ((cur = findNode(*phead, index - 1)) != NULL)
	{
		newNode = malloc(sizeof(ListNode));
		newNode->num = value;
		newNode->next = cur->next;
		cur->next = newNode;
	}
	else
		printf("Khong the them phan tu moi vao vi tri index= %d\n", index);
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

typedef struct queue
{
	LinkedList ll;
} Queue;

void enqueue(Queue *q, int item)
{
	if (q->ll.tail == NULL)
	{
		insertNode(&(q->ll.head), 0, item);
		q->ll.tail = q->ll.head;
		q->ll.size++;
	}
	else
	{
		q->ll.tail->next = malloc(sizeof(Queue));
		q->ll.tail = q->ll.tail->next;
		q->ll.tail->num = item;
		q->ll.tail->next = NULL;
		q->ll.size++;
	}
}

int dequeue(Queue *q)
{
	int item;
	if (q->ll.head != NULL)
	{
		item = q->ll.head->num;
		removeNode(&q->ll.head, 0);
		q->ll.size--;
		return item;
	}
	else
	{
		printf("Hang doi rong");
		return 0;
	}
}

int peekQ(Queue *q)
{
	int item;
	if (q->ll.head != NULL)
	{
		item = q->ll.head->num;
		return item;
	}
	else
	{
		printf("Hang doi rong");
		return 0;
	}
}

int isEmptyQueue(Queue *q)
{
	if ((q->ll).size == 0)
		return 1;
	return 0;
}

void main()
{
	Queue *q = malloc(sizeof(Queue));
	q->ll.head = NULL;
	q->ll.size = 0;
	q->ll.tail = NULL;
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
//	printList(q->ll.head);
	 enqueue(q, 40);
	 printList(q->ll.head);
//	 printf("%d\n", dequeue(q));
//	 printf("%d\n", peekQ(q));
//	 isEmptyQueue(q);
}
