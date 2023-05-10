/* Additional Exercise 1
    Write a program for finding Hamiltonian circuit for the graph, using backtracking. 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n;
	int **mat;
} graph;

graph* initgraph(int);
void insertedge(graph*, int, int);
void hamiltonian(graph*, int);
void getpaths(graph*, int, int*, int, int*);
void printcircuit(int*, int);

int main() {
	int vert, edges, u, v, start;

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

    printf("Enter the start node for the hamiltionian circuits: ");
    scanf("%d", &start);

	hamiltonian(g, start);

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
	g->mat[v][u] = 1;
}

void printcircuit(int* traversal, int n) {
    for(int i=0; i<n; i++) {
        printf("%d -> ", traversal[i]);
    }
    printf("%d\n", traversal[0]);
}

void hamiltonian(graph* g, int start) {
    int* visited = (int*) calloc(g->n, sizeof(int));
    int* traversal = (int*) calloc(g->n, sizeof(int));
    traversal[0] = start;

    printf("Required Hamiltonian Circuits are:\n");
    getpaths(g, start, traversal, 1, visited);
}

void getpaths(graph* g, int curr, int* traversal, int i, int* visited) {
    visited[curr] = 1;

    if(i == g->n && g->mat[curr][traversal[0]]) {
        printcircuit(traversal, g->n);
    }
    else {
        for(int j=0; j<g->n; j++) {
            if(g->mat[curr][j] && !visited[j]) {
                traversal[i] = j;
                getpaths(g, j, traversal, i+1, visited);
            }
        }
    }

    visited[curr] = 0;
}