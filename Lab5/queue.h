#include <stdlib.h>

typedef struct {
	int *arr;
    int size;
	int front;
	int rear;
} cqueue;

void insertcq(cqueue *, int);
int deletecq(cqueue *);
int isEmpty(cqueue *);
cqueue* initialize_cqueue(int);
void free_cqueue(cqueue *);

cqueue* initialize_cqueue(int size) {
    cqueue *cq = (cqueue*) malloc(sizeof(cqueue));
    cq->arr = (int *) calloc(size, sizeof(int));
    cq->size = size;
    cq->front = cq->rear = 0;
    return cq;
}

void insertcq(cqueue *cq, int ele) {
	cq->rear = (cq->rear+1) % cq->size;
	cq->arr[cq->rear] = ele;
}

int deletecq(cqueue *cq) {
	int x;
	if(isEmpty(cq)) {
		x = -5555;
	}
	else if((cq->front+1)%cq->size == cq->rear) {
		x = cq->arr[cq->rear];
		cq->front = cq->rear = 0;
	}
	else {
		cq->front = (cq->front+1) % cq->size;
		x = cq->arr[cq->front];
	}
	return x;
}

int isEmpty(cqueue* cq) {
	return cq->front == cq->rear;
}

void free_cqueue(cqueue *cq) {
	free(cq->arr);
	free(cq);
}