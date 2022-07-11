#include "BST.h"
#include "TreePrintLibrary.h"

void main() {
	BST bst1;
	initBST(&bst1);
	insertBST(&bst1, 9);
	insertBST(&bst1, 8);
	insertBST(&bst1, 4);
	insertBST(&bst1, 3);
	insertBST(&bst1, 7);
	insertBST(&bst1, 6);
	print_ascii_tree(bst1.root);
	printTreeInorder(&bst1);
	destroyBST(&bst1);
}