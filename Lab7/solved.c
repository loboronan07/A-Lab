/* Solved Exercise 
	Write a program to create a binary search tree and display its elements using all the traversal methods and analyse its time efficiency.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

node* create(node*, int);
node* getnode(int);
void inorder(node*);
void preorder(node*);
void postorder(node*);

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

	printf("\nPrerder Traversal of BST: ");
	preorder(root);

	printf("\nInorder Traversal of BST: ");
	inorder(root);

	printf("\nPostorder Traversal of BST: ");
	postorder(root);
	printf("\n");

	return 0;
}

node* create(node* bnode, int x) {
	if(bnode == NULL) {
		bnode = getnode(x);
	}
	else if(x > bnode->data) {
		bnode->right = create(bnode->right, x);
	}
	else if(x < bnode->data) {
		bnode->left = create(bnode->left, x);
	}
	else {
		printf("Dupicate found for %d in tree.\n", x);
	}

	return bnode;
}

node* getnode(int x) {
	node* n = (node*) malloc(sizeof(node));
	n->data = x;
	n->left = n->right = NULL;
	return n;
}

void inorder(node* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("\t%d", root->data);
		inorder(root->right);
	}
}

void preorder(node* root) {
	if(root != NULL) {
		printf("\t%d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("\t%d", root->data);
	}
}