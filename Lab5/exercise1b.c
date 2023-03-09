/* Lab Exercise 1b
	Write a program to determine the Topological sort of a given graph using
		ii. Source removal technique
*/

#include <stdio.h> 
#include <stdlib.h>
#include "queue.h"

typedef struct {
	int n;
	int **mat;
} graph;

graph* initgraph(int);
void insertedge(graph*, int, int);
void topologicalsort(graph* g);

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
	int* indegree = (int*) calloc(g->n, sizeof(int));
	cqueue* q = initialize_cqueue(g->n);

	for(int i=0; i<g->n; i++) {
		for(int j=0; j<g->n; j++) {
			if(g->mat[i][j] == 1) {
				indegree[j] += 1;
			}
		}
	}

	for(int i=0; i<g->n; i++) {
		if(indegree[i] == 0) {
			insertcq(q, i);
		}
	}

	printf("The topological sorting of the given graph is ");
	while(!isEmpty(q)) {
		int vert = deletecq(q);

		printf("%d ", vert);

		for(int i=0; i<g->n; i++) {
			if(g->mat[vert][i] == 1) {
				indegree[i] -= 1;
				if(indegree[i] == 0) {
					insertcq(q, i);
				}
			}
		}
	}

	printf("\n");
}