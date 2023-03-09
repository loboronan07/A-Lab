#include <stdlib.h>

typedef struct {
	int *arr;
	int tos;
	int size;
} STACK;

STACK* initialize_stack(int);
void push(STACK*, int);
int pop(STACK*);
int isEmpty(STACK*);
int isFull(STACK*);
void free_stack(STACK*);

STACK* initialize_stack(int size) {
	STACK* stack = (STACK*) malloc(sizeof(STACK));
	stack->size = size;
	stack->arr = (int*) calloc(size, sizeof(int));
	stack->tos = -1;
	return stack;
}

void push(STACK* stack, int ele) {
	stack->arr[++stack->tos] = ele;
}

int pop(STACK* stack) {
	return stack->arr[stack->tos--];
}

int isEmpty(STACK* stack) {
	return stack->tos == -1;
}

int atTop(STACK* stack) {
	return stack->arr[stack->tos];
}

void free_stack(STACK* stack) {
	free(stack->arr);
	free(stack);
}