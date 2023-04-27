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
	
	int* visited = (int*) calloc(n, sizeof(int));
	edge* min = (edge*) calloc(n-1, sizeof(edge));
	int i=0;
	int k=0;

	while(i<e && k<n-1) {
		if(!visited[edges[i].u] || !visited[edges[i].v]) {
			min[k++] = edges[i];
			visited[edges[i].u] = 1;
			visited[edges[i].v] = 1;
		}	
		i++;
	}

	return min;
}