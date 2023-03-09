/* Lab Exercise 1a
	Write a program to determine the Topological sort of a given graph using
		i. Depth-First technique
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct {
	int n;
	int **mat;
} graph;

graph* initgraph(int);
void insertedge(graph*, int, int);
void topologicalsort(graph*);
void topsort(graph*, int, int*, STACK*);

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

	topologicalsort(g);

	return 0;
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
}

void topologicalsort(graph* g) {
	int *visited = (int*) calloc(g->n, sizeof(int));

	STACK* s = initialize_stack(g->n);

	for(int i=0; i<g->n; i++) {
		if(visited[i] == 0){
			topsort(g, i, visited, s);
		}
	}

	printf("The topological sorting of the given graph is ");
	while(!isEmpty(s)) {
		printf("%d ", pop(s));
	}
	printf("\n");
}

void topsort(graph* g, int vert, int* visited, STACK* sort) {
	visited[vert] = 1;

	STACK* stack = initialize_stack(g->n);

	push(stack, vert);

	int flag;

	while (!isEmpty(stack)) {
		vert = atTop(stack);

		flag = 0;

		for(int i=0; i<g->n; i++) {
			if(g->mat[vert][i] == 1 && visited[i] == 0) {
				push(stack, i);
				visited[i] = 1;
				flag = 1;
				break;
			}
		}

		if(!flag) {
			push(sort, pop(stack));
		}
	}
}