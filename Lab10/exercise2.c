/* Lab Exercise 2
	Write a program to implement Floyd’s algorithm for the All-Pairs- Shortest-Paths
	problem for any given graph and analyse its time efficiency. Obtain the experimental
	results for order of growth and plot the result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INFINITY INT_MAX
#define MIN(a,b) ((a) < (b) ? a : b)

int** initmat(int);
void insertedge(int**, int, int, int);
int** createcopy(int**, int);
void printmat(int**, int);
int** floyd(int**, int);

int main() {
	int vert, edges, u, v, w;

	printf("Enter the number of vertices: ");
	scanf("%d", &vert);

	int** mat = initmat(vert);

	printf("Enter the number of edges in the graph: ");
	scanf("%d", &edges);

	printf("Enter the edges as the ordered pairs (u, v, weight):\n");
	for(int i=0; i<edges; i++) {
		scanf("%d %d %d", &u, &v, &w);
		insertedge(mat, u, v, w);
	}

	printf("\nAdjacency Matrix for the Given Graph:\n");
	printmat(mat, vert);

	int** pairshort = floyd(mat, vert);

	printf("\nAll Pairs Shortest Paths Matrix for the Given Graph:\n");
	printmat(pairshort, vert);

	return 0;
}

int** initmat(int v) {
	int** mat = (int**) calloc(v, sizeof(int*));

	for(int i=0; i<v; i++) {
		mat[i] = (int*) calloc(v, sizeof(int));

		for(int j=0; j<v; j++) {
			if(i == j) {
				continue;
			}
			mat[i][j] = INFINITY;
		}
	}

	return mat;
}

void insertedge(int** mat, int u, int v, int w) {
	mat[u][v] = w;
}

int** createcopy(int** mat, int n) {
	int** copy = (int**) calloc(n, sizeof(int*));

	for(int i=0; i<n; i++) {
		copy[i] = (int*) calloc(n, sizeof(int));

		for(int j=0; j<n; j++) {
			copy[i][j] = mat[i][j];
		}
	}

	return copy;
}

void printmat(int** mat, int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(mat[i][j] == INFINITY) {
				printf("\tINF");
			}
			else {
				printf("\t%3d", mat[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

int** floyd(int** mat, int n) {
	int** out = createcopy(mat, n);

	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				out[i][j] = MIN(out[i][j], (long) out[i][k] + out[k][j]);
			}
		}
	}

	return out;
}