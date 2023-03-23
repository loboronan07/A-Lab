/* Lab Exercise 1
	Modify the solved exercise to find the balance factor for every node in the binary
	search tree.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)

typedef struct node {
	int data;
	int balfact;
	struct node* left;
	struct node* right;
} node;

node* create(node*, int);
node* getnode(int);
void inorder(node*);
void preorder(node*);
void postorder(node*);
int calcbalfact(node*);

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

	calcbalfact(root);

	printf("\nPrerder Traversal with Balance Factors of nodes in BST: ");
	preorder(root);

	printf("\nInorder Traversal with Balance Factors of nodes in BST: ");
	inorder(root);

	printf("\nPostorder Traversal with Balance Factors of nodes in BST: ");
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
		printf("\t%d(%d)", root->data, root->balfact);
		inorder(root->right);
	}
}

void preorder(node* root) {
	if(root != NULL) {
		printf("\t%d(%d)", root->data, root->balfact);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("\t%d(%d)", root->data, root->balfact);
	}
}

int calcbalfact(node* n) {
	if(n == NULL)
		return -1;
	else {
		int l = calcbalfact(n->left);
		int r = calcbalfact(n->right);
		n->balfact = l - r;
		return MAX(l, r)+1;
	}
}