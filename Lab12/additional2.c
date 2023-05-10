/* Additional Exercise 2
    Write a program to implement assignment problem using Branch and Bound. 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int i;
    int lb;
    int *assignment;
    int* marked;
} node;

typedef struct {
	node** arr;
	int* p;
	int n;
} pqueue;

int n, **mat;

pqueue* initpq(int);
node* dequeue(pqueue*);
void enqueue(pqueue*, node*, int);

void initmat();
void assignmentprob();
void calclb(node*);
node* creatnode(int, int*);

int main() {
	printf("Enter the number of jobs: ");
	scanf("%d", &n);

	initmat();

	printf("Enter the cost matrix:\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", mat[i]+j);
		}
	}

	assignmentprob();

	return 0;
}


pqueue* initpq(int n) {
	pqueue* q = (pqueue*) malloc(sizeof(pqueue));
	q->arr = (node**) calloc(n, sizeof(node*));
	q->p = (int*) calloc(n, sizeof(int));
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
			if(q->p[j] > q->p[j+1]) {
				node* temp = q->arr[j];
				q->arr[j] = q->arr[j+1];
				q->arr[j+1] = temp;
				int t = q->p[j];
				q->p[j] = q->p[j+1];
				q->p[j+1] = t;
			}
		}
	}

	node* temp = q->arr[0];
	q->arr[0] = NULL;
	return temp;
}

void enqueue(pqueue* q, node* new, int pri) {
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


void initmat() {
	mat = (int**) calloc(n, sizeof(int*));

	for(int i=0; i<n; i++) {
		mat[i] = (int*) calloc(n, sizeof(int));
	}
}

node* createnode(int i, int* assignment) {
    node* new = (node*) malloc(sizeof(node));
    new->i = i;
    new->assignment = (int*) calloc(n, sizeof(int));
    new->marked = (int*) calloc(n, sizeof(int));
    for(int j=0; j<i; j++) {
        new->assignment[j] = assignment[j];
        new->marked[assignment[j]] = 1;
    }
    return new;
}

void calclb(node* temp) {
    temp->lb = 0;

    for(int j=0; j<temp->i; j++) {
        temp->lb += mat[j][temp->assignment[j]];
    }

    for(int j=temp->i; j<n; j++) {
        int min = -1;
        for(int k=0; k<n; k++) {
            if(!temp->marked[k] && (min==-1 || mat[j][k] < min)) {
                min = mat[j][k];
            }
        }
        temp->lb += min;
    }
}

void assignmentprob() {
    pqueue* q = initpq(MAX_SIZE);

    node* start = createnode(0, (int*) calloc(n, sizeof(int)));
    calclb(start);
    enqueue(q, start, start->lb);

    node* soln;
    while(1) {
        node* curr = dequeue(q);

        if(curr->i == n) {
            soln = curr;
            break;
        }

        for(int i=0; i<n; i++) {
            if(curr->marked[i] == 0) {
                node* child = createnode(curr->i, curr->assignment);
				child->i += 1;
                child->assignment[curr->i] = i;
                child->marked[i] = 1;
                calclb(child);
                enqueue(q, child, child->lb);
            }
        }
    }

    printf("\nSolution to the given assignment problem is as folows:\n");
	printf("------------+-----------+-----------\n");
    printf(" %10s |%10s |%10s\n", "Person", "Job", "Cost");
	printf("------------+-----------+-----------\n");
    for(int i=0; i<n; i++) {
        printf(" %10d |%10d |%10d\n", i+1, soln->assignment[i]+1, mat[i][soln->assignment[i]]);
    }
	printf("------------+-----------+-----------\n");
    printf("  %21s |%10d\n", "Total Cost", soln->lb);
	printf("------------------------+-----------\n");
}