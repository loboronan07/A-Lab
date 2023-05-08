/* Lab Exercise 3
	Write a program to implement Huffman tree construction algorithm.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int isdata;
	char data;
	float freq;
	struct node* left;
	struct node* right;
} node;

typedef struct {
	node** arr;
	float* p;
	int n;
} pqueue;

pqueue* initpq(int);
node* create_huff(char*, float*, int);
node* dequeue(pqueue*);
void enqueue(pqueue*, node*, float);
void print_inorder(node*, char*);

int main() {
	int n;
	
	printf("Enter the number of characters: ");
	scanf("%d", &n);

	char* characters = (char*) calloc(n, sizeof(char));
	float* freq = (float*) calloc(n, sizeof(float));

	printf("Enter the data as characters, freq:\n");
	for(int i=0; i<n; i++) {
		scanf(" %c %f", characters+i, freq+i);
	}

	node* root = create_huff(characters, freq, n);

	char* code = (char*) calloc(n, sizeof(char));

	printf("Huffmann Code Generated is:\n");
	print_inorder(root, code);
	printf("\n");

	return 0;
}

node* getnodedata(char c, float f) {
	node* new = (node*) malloc(sizeof(node));
	new->isdata = 1;
	new->data = c; 
	new->freq = f;
	return new;
}

node* getnode(node* left, node* right) {
	node* new = (node*) malloc(sizeof(node));
	new->isdata = 0;
	new->freq = left->freq + right->freq;
	new->left = left;
	new->right = right;
	return new;
}

pqueue* initpq(int n) {
	pqueue* q = (pqueue*) malloc(sizeof(pqueue));
	q->arr = (node**) calloc(n, sizeof(node*));
	q->p = (float*) calloc(n, sizeof(int));
	q->n = n;
	return q;
}

node* create_huff(char* c, float* f, int n) {
	pqueue* q = initpq(n);

	for(int i=0; i<n; i++) {
		enqueue(q, getnodedata(c[i], f[i]), f[i]);
	}

	while(n > 1) {
		node* l = dequeue(q);
		node* r = dequeue(q);
		enqueue(q, getnode(l, r), l->freq + r->freq);
		n--;
	}

	return dequeue(q);
}

node* dequeue(pqueue* q) {
	int k = 0;
	for(int i=0; i<q->n; i++) {
		if(q->arr[i] != NULL) {
		    node* temp = q->arr[i];
		    q->arr[i] = NULL;
			q->arr[k] = temp;
			q->p[k] = q->p[i];
			k++;
		}
	}

	for(int i=0; i<k-1; i++) {
		for(int j=0; j<k-i-1; j++) {
			if(q->p[j] > q->p[j+1]) {
				node* temp = q->arr[j];
				q->arr[j] = q->arr[j+1];
				q->arr[j+1] = temp;
				float t = q->p[j];
				q->p[j] = q->p[j+1];
				q->p[j+1] = t;
			}
		}
	}

	node* temp = q->arr[0];
	q->arr[0] = NULL;
	return temp;
}

void enqueue(pqueue* q, node* new, float pri) {
	for(int i=0; i<q->n; i++) {
		if(q->arr[i] == NULL) {
			q->arr[i] = new;
			q->p[i] = pri;
			return;
		}
	}
	exit(1);
}

void print_inorder(node* root, char* code) {
	if(root->isdata) {
		printf("%c -> %s\n", root->data, code);
	}
	else {
		int l = strlen(code);
		code[l] = '0';
		print_inorder(root->left, code);

		code[l] = '1';
		print_inorder(root->right, code);

		code[l] = '\0';
	}
}
