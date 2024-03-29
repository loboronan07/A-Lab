/* Lab Exercise 1
	Modify the solved exercise to find the balance factor for every node in the binary
	search tree.
*/

#include<stdio.h>
#include<stdlib.h>
#include "trees.h"

int main() {
	int n, ele;
	node* root = NULL;

	printf("Enter the number of elements in BST: ");
	scanf("%d", &n);

	printf("Enter %d values to insert into BST:\n", n);
	for(int i=0; i<n; i++) {
		scanf("%d", &ele);
		root = create(root, ele);
	}

	printf("\nPrerder Traversal with Balance Factors of nodes in BST: ");
	preorder(root);

	printf("\nInorder Traversal with Balance Factors of nodes in BST: ");
	inorder(root);

	printf("\nPostorder Traversal with Balance Factors of nodes in BST: ");
	postorder(root);
	printf("\n");

	return 0;
}