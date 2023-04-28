/* Lab Exercise 2
	Write a program to find shortest path from a given vertex to other vertices in a given
	weighted connected graph. Using Dijkstra's algorithm and analyse its time efficiency.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITY INT_MAX

typedef struct {
	int n;
	int **mat;
} graph;

graph* g;
int *parent, *mincost, *visited;

void initgraph(int);
void insertedge(int, int, int);
void dijkstra(int);
void getpath(int);

int main() {
	int vert, edges, u, v, w, start;
	
	printf("Enter the number of vertices: ");
	scanf("%d", &vert);

	initgraph(vert);

	printf("Enter the number of edges in the graph: ");
	scanf("%d", &edges);

	printf("Enter the edges as the ordered pairs (u, v, weight):\n");
	for(int i=0; i<edges; i++) {
		scanf("%d %d %d", &u, &v, &w);
		insertedge(u, v, w);
	}

	printf("Enter the start node: ");
	scanf("%d", &start);

	dijkstra(start);

	printf("Minimum Costs and Paths to Nodes from %d:\n", start);
	printf("%4s\t%6s\t%13s\n", "Node", "Cost", "Paths");
	for(int i=0; i<g->n; i++) {
		printf("%4d\t", i);
		printf("%6d\t\t", mincost[i]);
		getpath(i);
		printf("\n");
	}

	return 0;
}

void initgraph(int n) {
	g = (graph*) malloc(sizeof(graph));

	g->n = n;
	g->mat = (int**) calloc(n, sizeof(int*));

	for(int i=0; i<n; i++) {
		g->mat[i] = (int*) calloc(n, sizeof(int));
	}
}

void insertedge(int u, int v, int w) {
	g->mat[u][v] = w;
	g->mat[v][u] = w;
}

void dijkstra(int start) {
	parent = (int*) calloc(g->n, sizeof(int));

	mincost = (int*) calloc(g->n, sizeof(int));
	for(int i=0; i<g->n; i++) {
		mincost[i] = INFINITY;
	}

	visited = (int*) calloc(g->n, sizeof(int));

	int n = 0;
	mincost[start] = 0;
	parent[start] = -1;

	while(n<g->n) {	
		int curr;
		int pathcost = INFINITY;
		for(int i=0; i<g->n; i++) {
			if(mincost[i]<pathcost && !visited[i]) {
				curr = i;
				pathcost = mincost[i];
			}
		}

		visited[curr] = 1;
		for(int i=0; i<g->n; i++) {
			if(!visited[i] && g->mat[curr][i] != 0) {
				if(pathcost+g->mat[curr][i]<mincost[i]) {
					parent[i] = curr;
					mincost[i] = pathcost+g->mat[curr][i];
				}
			}
		}
		n++;
	}
}

void getpath(int curr) {
	if(parent[curr] >= 0) {
		getpath(parent[curr]);
	}
	printf("->%d", curr);
}
