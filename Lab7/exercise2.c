/* Lab Exercise 2
	Write a program to create the AVL tree by iterative insertion.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)

typedef struct node {
	int data;
	int leftht;
	int rightht;
	struct node* left;
	struct node* right;
} node;

node* create(node*, int, int*);
node* getnode(int);
void inorder(node*);
void preorder(node*);
void postorder(node*);
int height(node*);

int main() {
	int n, ele, ht;
	node* root = NULL;

	printf("Enter the number of elements in BST: ");
	scanf("%d", &n);

	printf("Enter %d values to insert into BST:\n", n);
	for(int i=0; i<n; i++) {
		scanf("%d", &ele);
		root = create(root, ele, &ht);
		printf("\n");
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

node* create(node* bnode, int x, int* ht) {
	if(bnode == NULL) {
		bnode = getnode(x);
	}
	else if(x > bnode->data) {
		bnode->right = create(bnode->right, x, &(bnode->rightht));
	}
	else if(x < bnode->data) {
		bnode->left = create(bnode->left, x, &(bnode->leftht));
	}
	else {
		printf("Dupicate found for %d in tree.\n", x);
	}

	int balfact = bnode->leftht - bnode->rightht;

	if(balfact > 1 || balfact < -1) {
		if(bnode->rightht > bnode->leftht) {
			node* c = bnode->right;
			if(c->leftht > c->rightht) {
				node* g = c->left;
				c->left = g->right;
				g->right = c;
				bnode->right = g->left;
				g->left = bnode;
				bnode = g;
			}
			else {
				bnode->right = c->left;
				c->left = bnode;
				bnode = c;
			}
		}
		else {
			node* c = bnode->left;
			if(c->rightht > c->leftht) {
				node* g = c->right;
				c->right = g->left;
				g->left = c;
				bnode->left = g->right;
				g->right = bnode;
				bnode = g;
			}
			else {
				bnode->left = c->right;
				c->right = bnode;
				bnode = c;
			}
		}

		height(bnode);
	}


	*ht = MAX(bnode->leftht, bnode->rightht) + 1;

	return bnode;
}

node* getnode(int x) {
	node* n = (node*) malloc(sizeof(node));
	n->data = x;
	n->leftht = n->rightht = -1;
	n->left = n->right = NULL;
	return n;
}

void inorder(node* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("\t%d(%d)", root->data, root->leftht - root->rightht);
		inorder(root->right);
	}
}

void preorder(node* root) {
	if(root != NULL) {
		printf("\t%d(%d)", root->data, root->leftht - root->rightht);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("\t%d(%d)", root->data, root->leftht - root->rightht);
	}
}

int height(node* root) {
	if(root == NULL) {
		return -1;
	}
	else {
		root->leftht = height(root->left);
		root->rightht = height(root->right);

		return MAX(root->leftht, root->rightht) + 1;
	}
}