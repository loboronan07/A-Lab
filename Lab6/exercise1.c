/* Lab Exercise 1
	Find total number of nodes in a binary tree and analyze its efficiency. Obtain the
	experimental result of order of growth and plot the result.
*/

#include <stdio.h>
#include <stdlib.h>

int opcount;

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

node* create(int);
void freetree(node*);
int count(node*);

int main() {
	int data;
	printf("Enter the data for the Tree in the order specified...\n");
	printf("Enter data for root(Hit 0 to exit): ");
	scanf("%d", &data);
	node* root = create(data);

	opcount = 0;
	int num = count(root);
	printf("\nThe total number of nodes in the given tree is %d\n", num);
	printf("Operation Count: %d\n", opcount);
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

int count(node* root) {
	opcount++;
	if(root == NULL) {
		return 0;
	}

	int left = count(root->left);
	int right = count(root->right);
	return left+right+1;
}