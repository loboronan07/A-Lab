/* Lab Exercise 1
	Write a program to find Minimum Cost Spanning Tree of a given undirected graph
	using Kruskal's algorithm and analyse its time efficiency.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int u;
	int v;
	int w;
} edge;

void sortedges(edge*, int);
edge* minimumspanning(int, edge*, int);
int checkcycle(int, edge*, int);
int cycle(int, edge*, int, int*, int*);

int main() {
	int vert, e;

	printf("Enter the number of vertices: ");
	scanf("%d", &vert);

	printf("Enter the number of edges in the graph: ");
	scanf("%d", &e);

	edge* edges = (edge*) calloc(e, sizeof(edge));

	printf("Enter the edges as the ordered pairs (u, v, weight):\n");
	for(int i=0; i<e; i++) {
		scanf("%d %d %d", &(edges[i].u), &(edges[i].v), &(edges[i].w));
	}

	edge* minspan = minimumspanning(vert, edges, e);

	printf("Edges in the Minimum Spanning Tree:\n");
	printf("%4s %4s %4s\n", "u", "v", "w");
	for(int i=0; i<vert-1; i++) {
		printf("%4d %4d %4d\n", minspan[i].u, minspan[i].v, minspan[i].w);
	}

	return 0;
}

void sortedges(edge* edges, int n) {
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
			if(edges[j].w > edges[j+1].w) {
				edge temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp;
			}
		}
	}
}

edge* minimumspanning(int n, edge* edges, int e) {
	sortedges(edges, e);

	edge* min = (edge*) calloc(n-1, sizeof(edge));
	int i=0;
	int k=0;

	while(i<e && k<n-1) {
		min[k] = edges[i];
		if(!checkcycle(n, min, k+1)) {
			k++;
		}
		i++;
	}

	return min;
}

int checkcycle(int n, edge* edges, int e) {
	for(int i=0; i<n; i++) {
		int* edgevisited = (int*) calloc(e, sizeof(int));
		int* nodevisited = (int*) calloc(n, sizeof(int));
		if(cycle(i, edges, e, edgevisited, nodevisited)) {
			return 1;
		}
	}
	return 0;
}

int cycle(int curr, edge* edges, int e, int* edgevisited, int* nodevisited) {
	if(nodevisited[curr]) {
		return 1;
	}
	nodevisited[curr] = 1;

	for(int i=0; i<e; i++) {
		if(edgevisited[i]) {
			continue;
		}
		if(edges[i].u == curr) {
			edgevisited[i] = 1;
			if(cycle(edges[i].v, edges, e, edgevisited, nodevisited)) {
				return 1;
			}
		}
		else if(edges[i].v == curr) {
			edgevisited[i] = 1;
			if(cycle(edges[i].u, edges, e, edgevisited, nodevisited)) {
				return 1;
			}
		}
	}

	return 0;
}