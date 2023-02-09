#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;	
} node;

node* getnode(int);
void traverse(node*, int);
void searchinsert(node**, int);
node* create(int);
void freetree(node*);

int main() {
	node* root = NULL;
	int d, choice, order;

	printf("Creating the Initial Binary Search Tree..\n");
	printf("Enter the data for the root node(Hit -1 for NULL): ");
	scanf("%d", &d);

	root = create(d);

	printf("\nAvailable Operations:\n");
	printf("\t1. Search and Insert\n");
	printf("\t2. Traverse\n");
	printf("\t3. Exit\n");

	while(1) {
		printf("\nEnter your operation: ");
		scanf("%d", &choice);

		if(choice == 1) {
			int key;
			printf("Enter search key: ");
			scanf("%d", &key);
			searchinsert(&root, key);
		}
		else if(choice == 2) {
			if(root == NULL) {
				printf("Tree Empty...\n");
			}
			else {
				printf("Inorder: ");
				traverse(root, 0);
				printf("\n");

				printf("Preorder: ");
				traverse(root, 1);
				printf("\n");

				printf("Postorder: ");
				traverse(root, 2);
				printf("\n");
			}
		}
		else if(choice == 3) {
			break;
		}
		else {
			printf("Please enter a valid operation. Try Again..\n");
		}
	}

	freetree(root);

	return 0;
}

void traverse(node* root, int order) {
	if(root) {
		if(order == 0) {
			traverse(root->left, order);
			printf("%d ", root->data);
			traverse(root->right, order);
		}
		else if(order == 1) {
			printf("%d ", root->data);
			traverse(root->left, order);
			traverse(root->right, order);
		}
		else {
			traverse(root->left, order);
			traverse(root->right, order);
			printf("%d ", root->data);
		}
	}
}

void searchinsert(node **root, int key) {
	node* curr = *root;
	node* prev = NULL;

	while(curr && curr->data != key) {
		prev = curr;
		curr = (curr->data > key) ? curr->left : curr->right;
	}

	if(curr) {
		printf("Key Found!\n");
	}
	else {
		printf("Key Not Found! Inserting %d into the BST...\n", key);
		if(prev == NULL) {
			*root = getnode(key);
		}
		else if(prev->data > key) {
			prev->left = getnode(key);
		}
		else {
			prev->right = getnode(key);
		}
	}
}

node* getnode(int data) {
	node* temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

node* create(int data) {
	if(data == -1) {
		return NULL;
	}

	node* root = getnode(data);
	int d;

	printf("Enter the data for the left node of %d(Hit -1 for NULL): ", data);
	scanf("%d", &d);

	root->left = create(d);

	printf("Enter the data for the right node of %d(Hit -1 for NULL): ", data);
	scanf("%d", &d);

	root->right = create(d);

	return root;
}

void freetree(node* root) {
	if(root) {
		freetree(root->left);
		freetree(root->right);
		free(root);
	}
}