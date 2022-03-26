#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _btnode2
{
	char item;
	struct _btnode2 *left;
	struct _btnode2 *right;
} BTNode2;

void TreeTraversal_InOrder2(BTNode2 *cur)
{
	if (cur == NULL)
	{
		return;
	}
	TreeTraversal_InOrder2(cur->left);
	printf("%c ", cur->item);
	TreeTraversal_InOrder2(cur->right);
}


BTNode2* BSTT(BTNode2 *cur, char c)
{
	if (cur == NULL)
	{
		return NULL;
	}
	if (c==cur->item)
	{
		return cur;
	}
	if (c < cur->item)
	{
		return BSTT(cur->left,c);
	}
	else
	{
		return BSTT(cur->right,c);
	}
}


BTNode2* BSTT2(BTNode2 *cur, char c)
{
	if (c==cur->item)
	{
		return NULL;
	}
	if (c < cur->item)
	{
		if (cur->left == NULL)
		{
			return cur;
		}
		return BSTT2(cur->left,c);
	}
	else
	{
		if (cur->right == NULL)
		{
			return cur;
		}
		return BSTT2(cur->right,c);
	}
}

int main(void)
{
	BTNode2 *btnodeA, *btnodeB, *btnodeC, *btnodeD, *btnodeE, *btnodeF;
	btnodeA = malloc(sizeof(BTNode2));
	btnodeB = malloc(sizeof(BTNode2));
	btnodeC = malloc(sizeof(BTNode2));
	btnodeD = malloc(sizeof(BTNode2));
	btnodeE = malloc(sizeof(BTNode2));
	btnodeF = malloc(sizeof(BTNode2));

	btnodeA->item='A';
	btnodeB->item='B';
	btnodeC->item='C';
	btnodeD->item='D';
	btnodeE->item='E';
	btnodeF->item='F';

	btnodeA->left=btnodeB;
	btnodeA->right=btnodeC;

	btnodeB->left=btnodeD;
	btnodeB->right=btnodeE;

	btnodeC->left=NULL;
	btnodeC->right=btnodeF;

	btnodeD->left=NULL;
	btnodeD->right=NULL;

	btnodeE->left=NULL;
	btnodeE->right=NULL;

	btnodeF->left=NULL;
	btnodeF->right=NULL;
	
	printf("\n\nCay nhi phan tim kiem truoc khi chen:\n ");
	TreeTraversal_InOrder2(btnodeA);

	// Insert
	char q = 'Q';
	BTNode2* posNode = BSTT2(btnodeA,q);

	BTNode2 *btNewNode = malloc(sizeof(BTNode2));
	btNewNode->item = q;
	btNewNode->left = NULL;
	btNewNode->right = NULL;
	if (posNode == NULL)
	{
		printf("Phan tu da ton tai");
		return 0;
	}
	if (q < posNode->item)
	{
		posNode->left = btNewNode;
	}
	else
	{
		posNode->right = btNewNode;
	}
	printf("\n\nCay nhi phan tim kiem sau khi chen:\n ");
	TreeTraversal_InOrder2(btnodeA);
}
