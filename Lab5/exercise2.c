/* Lab Exercise 2
	Write a program to find diameter of a binary tree. Diameter of a binary tree is
	the longest path between any two nodes.
*/

#include <stdio.h>
#include <stdlib.h>

int max;

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

node* create(int);
void freetree(node*);
int maxdiameter(node*);

int main() {
	int data;
	printf("Enter the data for the Tree in the order specified...\n");
	printf("Enter data for root(Hit 0 to exit): ");
	scanf("%d", &data);
	node* root = create(data);

	max = 0;
	maxdiameter(root);

	printf("The diameter of the given tree is %d\n", max);
	
	freetree(root);

	return 0;
}

node* create(int ele){
	if(ele == 0) 
		return NULL;

	int x;

	node* temp = (node*) malloc(sizeof(node));
	temp->data = ele;

	printf("Enter data for left child of %d(Hit 0 to exit): ", ele);
	scanf("%d", &x);
	temp->left = create(x);

	printf("Enter data for right child of %d(Hit 0 to exit): ", ele);
	scanf("%d", &x);
	temp->right = create(x);

	return temp;
}

void freetree(node* root) {
	if(!root) 
		return;

	freetree(root->left);
	freetree(root->right);
	free(root);
}

int maxdiameter(node* root) {
	if(root != NULL) {
		int left = maxdiameter(root->left);
		int right = maxdiameter(root->right);

		int total = left + right + 1;

		if(total > max) {
			max = total;
		}

		return left > right ? left + 1 : right + 1;
	}
	else {
		return 0;
	}
}