#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)

typedef struct node {
	int data;
	int height;
	struct node* left;
	struct node* right;
} node;

node* create(node*, int);
node* createavl(node*, int);
node* getnode(int);
void inorder(node*);
void preorder(node*);
void postorder(node*);
int getheight(node*);
void setheight(node*);
int getbalfact(node*);
node* avl(node*);

node* getnode(int x) {
	node* n = (node*) malloc(sizeof(node));
	n->data = x;
	n->height = 0;
	n->left = n->right = NULL;
	return n;
}

int getheight(node* root) {
	return root ? root->height : -1;
}

void setheight(node* root) {
	root->height = MAX(getheight(root->left), getheight(root->right)) + 1;
}

int getbalfact(node* root) {
	return getheight(root->left) - getheight(root->right);
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

	setheight(bnode);

	return bnode;
}

node* createavl(node* bnode, int x) {
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
		printf("Duplicate found for %d in tree.\n", x);
	}

	bnode = avl(bnode);
	setheight(bnode);

	return bnode;
}

node* avl(node* bnode) {
	int balfact = getbalfact(bnode);

	if(balfact > 1) {
		node* c = bnode->left;
		if(getheight(c->left) > getheight(c->right)) {
			bnode->left = c->right;
			setheight(bnode);
			c->right = bnode;
			setheight(c);
			bnode = c;
		}
		else {
			node* g = c->right;
			c->right = g->left;
			setheight(c);
			g->left = c;
			setheight(g);
			bnode->left = g->right;
			setheight(bnode);
			g->right = bnode;
			setheight(g);
			bnode = g;
		}
	}
	else if(balfact < -1) {
		node* c = bnode->right;
		if(getheight(c->right) > getheight(c->left)) {
			bnode->right = c->left;
			setheight(bnode);
			c->left = bnode;
			setheight(c);
			bnode = c;
		}
		else {
			node* g = c->left;
			c->left = g->right;
			setheight(c);
			g->right = c;
			setheight(g);
			bnode->right = g->left;
			setheight(bnode);
			g->left = bnode;
			setheight(g);
			bnode = g;
		}
	}

	return bnode;
}

void inorder(node* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("\t%d(%d)", root->data, getbalfact(root));
		inorder(root->right);
	}
}

void preorder(node* root) {
	if(root != NULL) {
		printf("\t%d(%d)", root->data, getbalfact(root));
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(node* root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("\t%d(%d)", root->data, getbalfact(root));
	}
}