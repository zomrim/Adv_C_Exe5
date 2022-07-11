#include "BST.h"
#include <stdio.h>
#define ALLOCATE_CHECK(node) do {\
								if (!node){\
								printf("\nallocation failed\n");\
								exit(1);}\
							}while(0)


void initBST(BST* bst) {
	bst->root = NULL;
}

void insertBST(BST* bst, int value) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	ALLOCATE_CHECK(newNode);
	newNode->element = value;
	newNode->left = newNode->right = NULL;

	if (bst->root == NULL)
	{
		bst->root = newNode;
		return;
	}

	BST temp;

	if (newNode->element <= bst->root->element) //left subtree (<=)
		if (bst->root->left == NULL)
			bst->root->left = newNode;
		else {
			temp.root = bst->root->left;
			insertBST(&temp, value);
		}

	if (newNode->element > bst->root->element) //right subtree (>)
		if (bst->root->right == NULL)
			bst->root->right = newNode;
		else {
			temp.root = bst->root->right;
			insertBST(&temp, value);
		}
}

void printTreeInorder(BST* bst) {
	if (bst->root == NULL)
		printf("\nTree is empty!\n");
	else printTreeInorderRec(bst);
}

void destroyBST(BST* bst) {
	if (bst->root == NULL)//case tree is empty
		return;
	
	if (bst->root->left == NULL && bst->root->right == NULL) {//case leaf has no kids
		free(bst->root);
		bst->root = NULL;
		return;
	}

	BST tempL, tempR;
	tempL.root = bst->root->left;
	destroyBST(&tempL);
	tempR.root = bst->root->right;
	destroyBST(&tempR);
	free(bst->root);
}

int findIndexNFromLast(BST* bst, int N) {

}

int sameHeightLeaves(BST* bst) {
	if (bst->root == NULL) {
		return -1;
	}

	BST tempL, tempR;
	tempL.root = bst->root->left;
	tempR.root = bst->root->right;

	int lefth = sameHeightLeaves(&tempL);
	int righth = sameHeightLeaves(&tempR);

	if (lefth > righth) {
		return lefth + 1;
	}
	else {
		return righth + 1;
	}
}

void printTreeInorderRec(BST* bst) {
	if (bst->root != NULL)
	{
		BST tempL, tempR;
		tempL.root = bst->root->left;
		printTreeInorderRec(&tempL);
		printf("%d", bst->root->element);
		tempR.root = bst->root->right;
		printTreeInorderRec(&tempR);
	}
}