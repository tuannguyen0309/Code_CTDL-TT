#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode
{
	int num;
	struct _listnode *next;
} ListNode;

void printList(ListNode *head)
{
	ListNode *cur = head;
	if (cur == NULL)
	{
		printf("Danh sach lien ket khong co phan tu nao");
	}
	else
	{
		while (cur != NULL)
		{
			printf("%d\n", cur->num);
			cur = cur->next;
		}
	}
	printf(" \n");
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

void insertNode(ListNode **pHead, int index, int value)
{
	ListNode *cur, *newNode;
	if (*pHead == NULL || index == 0)
	{
		newNode = malloc(sizeof(ListNode));
		newNode->num = value;
		newNode->next = *pHead;
		*pHead = newNode;
	}
	else
	{
		cur = findNode(*pHead, index - 1);
		if (cur != NULL)
		{
			newNode = malloc(sizeof(ListNode));
			newNode->num = value;
			newNode->next = cur->next;
			cur->next = newNode;
		}
		else
		{
			printf("Khong the them phan tu moi vao vi tri index= %d!\n", index);
		}
	}
}

void removeNode(ListNode **ptrHead, int index)
{
	ListNode *cur, *pre;
	if (index == 0)
	{
		cur = *ptrHead;
		*ptrHead = cur->next;
		free(cur);
	}
	else
	{
		pre = findNode(*ptrHead, index - 1);
		cur = pre->next;
		pre->next = cur->next;
		free(cur);
	}
}

int main()
{
	ListNode *node0, *node1, *node2, *node3, *head, **ptrhead = &head;
	node0 = malloc(sizeof(ListNode));
	node1 = malloc(sizeof(ListNode));
	node2 = malloc(sizeof(ListNode));
	node3 = malloc(sizeof(ListNode));
	node0->num = 10;
	node1->num = 20;
	node2->num = 30;
	node3->num = 40;
	node0->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	head = node0;
	head = *ptrhead;
//	 printList(head);
//	findNode(head, 3);
//	 insertNode(&head, 3, 50);
	 removeNode(&head, 0);
	 printList(head);
}
