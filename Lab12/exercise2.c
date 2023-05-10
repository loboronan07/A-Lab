/* Lab Exercise 2
    Write a program to implement Knapsack problem using branch and bound 
    technique. 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int i;
    int w;
    int v;
    float ub;
    int *mark;
} node;

typedef struct {
	node** arr;
	float* p;
	int n;
} pqueue;

int *w, *v;
float *vw;
int n, B;

pqueue* initpq(int);
node* dequeue(pqueue*);
void enqueue(pqueue*, node*, float);
void knapsack();
void initvw();
void sortbyvw();
node* createnode(int, int, int, int*);
float getub(int, int, int);

int main() {
    printf("Enter the number of elements: ");
	scanf("%d", &n);

	w = (int*) calloc(n, sizeof(int));
	v = (int*) calloc(n, sizeof(int));

	printf("Enter the elements as weight, value:\n");
	for(int i=0; i<n; i++) {
		scanf("%d %d", w+i, v+i);
	}

	printf("Enter the knapsack capacity: ");
	scanf("%d", &B);

	knapsack();
    
    return 0;
}

pqueue* initpq(int n) {
	pqueue* q = (pqueue*) malloc(sizeof(pqueue));
	q->arr = (node**) calloc(n, sizeof(node*));
	q->p = (float*) calloc(n, sizeof(float));
	q->n = n;
	return q;
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
			if(q->p[j] < q->p[j+1]) {
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
	printf("Queue Size Exceeded. Exiting From Program...\n");
	exit(1);
}

void sortbyvw() {
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
			if(vw[j] < vw[j+1]) {
				float temp = vw[j]; vw[j] = vw[j+1]; vw[j+1] = temp;
				int t = v[j]; v[j] = v[j+1]; v[j+1] = t;
				t = w[j]; w[j] = w[j+1]; w[j+1] = t;
			}
		}
	}
}

void initvw() {
	vw = (float*) calloc(n, sizeof(float));
	for(int i=0; i<n; i++) {
		vw[i] = (float) v[i] / w[i];
	}
}

node* createnode(int i, int w, int v, int* mark) {
	node* new = (node*) malloc(sizeof(node));
	new->i = i;
	new->w = w;
	new->v = v;
	new->ub = getub(i, w, v);
	new->mark = (int*) calloc(n, sizeof(int));
	for(int i=0; i<n; i++) {
		new->mark[i] = mark[i];
	}

	return new;
}

float getub(int i, int w, int v) {
	if(i < n) {
		return v + (B-w)*vw[i];
	}
	else {
		return v;
	}
}

void knapsack() {
	initvw();
	sortbyvw();

	pqueue* q = initpq(MAX_SIZE);

	node* start = createnode(0, 0, 0, (int*) calloc(n, sizeof(int)));
	
	enqueue(q, start, start->ub);

	node* soln;

	while(1) {
		node* curr = dequeue(q);
		
		if(curr->i == n) {
			soln = curr;
			break;
		}

		if(curr->w + w[curr->i] <= B) {
			node* temp = createnode(curr->i+1, curr->w+w[curr->i], curr->v+v[curr->i], curr->mark);
			temp->mark[curr->i] = 1;
			enqueue(q, temp, temp->ub);
		}
		
		node* temp = createnode(curr->i+1, curr->w, curr->v, curr->mark);
		enqueue(q, temp, temp->ub);
	}

	printf("\nThe given knapsack can contain the following subset of items with maximum total value:\n");
	printf("------------------+------------\n");
	printf("  %15s | %10s\n", "Weight", "Value");
	printf("------------------+------------\n");
	for(int i=0; i<n; i++) {
		if(soln->mark[i]) {
			printf("  %15d | %10d\n", w[i], v[i]);
		}
	}
	printf("------------------+------------\n");
	printf(" Total:%10d | %10d\n", soln->w, soln->v);
	printf("------------------+------------\n");
}