/* Lab Exercise 2
	Write a program to construct the Open hash table. Find the number of key
	comparisons in successful search and unsuccessful search. This should be done by
	varying the load factor of the hash table. You may consider varying the number of
	keys for a fixed value of hash table size say m=10 and n=50, 100, and 200. This
	should be repeated for at least four different hash table sizes say m= 20, m=50.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} node;

int opcount;

node** createhash(int*, int, int);
int search(node**, int, int);
void freehash(node**, int);

node* insertll(node*, int);
node* getnode(int);
int searchll(node*, int);
void freell(node*);

int main() {
	int *arr, n;
	node **hash;
	int key;
	int ele;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	arr = (int*) calloc(n, sizeof(int));

	printf("Enter %d elements into the array:\n", n);
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	printf("Enter the value of key for the hash table: ");
	scanf("%d", &key);

	hash = createhash(arr, n, key);

	printf("Enter the search element: ");
	scanf("%d", &ele);

	opcount = 0;

	if(search(hash, key, ele)) {
		printf("Search successfull with operation count %d...\n", opcount);
	}
	else {
		printf("Search unsuccessfull with operation count %d...\n", opcount);
	}

	freehash(hash, key);
	free(arr);

	return 0;
}

node** createhash(int* arr, int n, int key) {
	node** hash = (node**) calloc(key, sizeof(node*));

	for(int i=0; i<n; i++) {
		int pos = arr[i] % key;

		hash[pos] = insertll(hash[pos], arr[i]);
	}

	return hash;
}

int search(node** hash, int key, int ele) {
	int pos = ele % key;

	opcount++;

	return searchll(hash[pos], ele);
}

void freehash(node** hash, int key) {
	for(int i=0; i<key; i++) {
		freell(hash[i]);
	}
}

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
		opcount++;
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