/* Lab Exercise 3
	Write a program for breadth-first search of a graph.
*/

#include <stdio.h> 
#include <stdlib.h>

typedef struct {
	int *arr;
    int size;
	int front;
	int rear;
} cqueue;

typedef struct {
	int n;
	int **mat;
} graph;

void insertcq(cqueue *, int);
int deletecq(cqueue *);
int isEmpty(cqueue *);
cqueue* initialize_cqueue(int);
void free_cqueue(cqueue *);

graph* initgraph(int);
void insertedge(graph*, int, int);
void BFS(graph*);
void bfs(graph*, int, int*);

int main() {
	int vert, edges, u, v;

	printf("Enter the number of vertices: ");
	scanf("%d", &vert);

	graph* g = initgraph(vert);

	printf("Enter the number of edges in the graph: ");
	scanf("%d", &edges);

	printf("Enter the edges as the ordered pairs (u, v):\n");
	for(int i=0; i<edges; i++) {
		scanf("%d %d", &u, &v);
		insertedge(g, u, v);
	}
	printf("\n");

	BFS(g);

	return 0;
}


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

graph* initgraph(int v) {
	graph* g = (graph*) malloc(sizeof(graph));

	g->n = v;

	g->mat = (int**) calloc(v, sizeof(int*));

	for(int i=0; i<v; i++) {
		g->mat[i] = (int*) calloc(v, sizeof(int));
	}

	return g;
}

void insertedge(graph* g, int u, int v) {
	g->mat[u][v] = 1;
	g->mat[v][u] = 1;
}

void BFS(graph* g) {
	int *visited = (int*) calloc(g->n, sizeof(int));

	printf("The BFS traversal of the given graph is ");
	for(int i=0; i<g->n; i++) {
		if(visited[i] == 0) {
			bfs(g, i, visited);
		}
	}
	printf("\n");
}

void bfs(graph* g, int vert, int* visited) {
	visited[vert] = 1;

	cqueue* q = initialize_cqueue(g->n);
	insertcq(q, vert);
	
	while (!isEmpty(q)) {
		vert = deletecq(q);
		printf("%d ", vert);

		for(int i=0; i<g->n; i++) {
			if(g->mat[vert][i] == 1 && visited[i] == 0) {
				insertcq(q, i);
				visited[i] = 1;
			}
		}
	}
}