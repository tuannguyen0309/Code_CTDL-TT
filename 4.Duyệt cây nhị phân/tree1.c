#include<stdio.h>
#include<stdlib.h>

typedef struct _btnode {
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;

//Duyet cay theo thu tu truoc
void TreeTraversal_PreOrder(BTNode *cur)
{
	if (cur == NULL) {
		return;
	}
	printf("%c",cur->item);
	TreeTraversal_PreOrder(cur->left); //Tham nut con trai
	TreeTraversal_PreOrder(cur->right);//Tham nut con phai
}

//Duyet cay theo thu tu giua
void TreeTraversal_InOrder(BTNode *cur)
{
	if (cur == NULL) {
		return;
	}
	TreeTraversal_InOrder(cur->left); //Tham nut con trai
	printf("%c",cur->item);
	TreeTraversal_InOrder(cur->right);//Tham nut con phai
}

//Duyet cay theo thu tu sau
void TreeTraversal_PostOrder(BTNode *cur)
{
	if (cur == NULL) {
		return;
	}
	TreeTraversal_PostOrder(cur->left); //Tham nut con trai
	TreeTraversal_PostOrder(cur->right);//Tham nut con phai
	printf("%c",cur->item);
}

void main()
{
    BTNode *btnodeA, *btnodeB, *btnodeC, *btnodeD, *btnodeE, *btnodeF,
        *btnodeG, *btnodeH, *btnodeI;
    
    btnodeA = malloc(sizeof(BTNode));
    btnodeB = malloc(sizeof(BTNode));
    btnodeC = malloc(sizeof(BTNode));
    btnodeD = malloc(sizeof(BTNode));
    btnodeE = malloc(sizeof(BTNode));
    btnodeF = malloc(sizeof(BTNode));
    btnodeG = malloc(sizeof(BTNode));
    btnodeH = malloc(sizeof(BTNode));
    btnodeI = malloc(sizeof(BTNode));
    btnodeA->item = 'A';
    btnodeB->item = 'B';
    btnodeC->item = 'C';
    btnodeD->item = 'D';
    btnodeE->item = 'E';
    btnodeF->item = 'F';
    btnodeG->item = 'G';
    btnodeH->item = 'H';
    btnodeI->item = 'I';
    btnodeA->left = btnodeB;
    btnodeA->right = btnodeC;
    btnodeB->left = btnodeD;
    btnodeB->right = btnodeE;
    btnodeC->left = btnodeF;
    btnodeC->right = btnodeG;
    btnodeD->left = btnodeH;
    btnodeD->right = btnodeI;
    btnodeE->left = NULL;
    btnodeE->right = NULL;
    btnodeF->left = NULL;
    btnodeF->right = NULL;
    btnodeG->left = NULL;
    btnodeG->right = NULL;
    btnodeH->left = NULL;
    btnodeH->right = NULL;
    btnodeI->left = NULL;
    btnodeI->right = NULL;
    printf("\nDuyet cay theo thu tu truoc: ");
    TreeTraversal_PreOrder(btnodeA);
    printf("\nDuyet cay theo thu tu giua: ");
    TreeTraversal_InOrder(btnodeA);
    printf("\nDuyet cay theo thu tu sau: ");
    TreeTraversal_PostOrder(btnodeA);
}
