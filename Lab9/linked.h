#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

node* insertll(node*, int);
node* getnode(int);
int searchll(node*, int);
void freell(node*);

node* getnode(int ele) {
	node* n = (node*) malloc(sizeof(node));
	n->data = ele;
	n->next = NULL;

	return n;
}

node* insertll(node* head, int ele) {
	node* temp = getnode(ele);

	if(head == NULL) 
		head = temp;
	else {
		node* curr = head;
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = temp;
	}

	return head;
}

int searchll(node* head, int ele) {
	node* curr = head;

	while(curr) {
		if(curr->data == ele) {
			return 1;
		}

		curr = curr->next;
	}

	return 0;
}

void freell(node* head) {
	node* temp;
	while(head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}