/* Lab Exercise 1
	Write a program to compute the transitive closure of a given directed graph using
	Warshall’s algorithm and analyse its time efficiency. Obtain the experimental results
	for order of growth and plot the result.
*/

#include <stdio.h>
#include <stdlib.h>

int** initmat(int);
void insertedge(int**, int, int);
int** createcopy(int**, int);
void printmat(int**, int);
int** warshall(int**, int);


int main() {
	int vert, edges, u, v;

	printf("Enter the number of vertices: ");
	scanf("%d", &vert);

	int** mat = initmat(vert);

	printf("Enter the number of edges in the graph: ");
	scanf("%d", &edges);

	printf("Enter the edges as the ordered pairs (u, v):\n");
	for(int i=0; i<edges; i++) {
		scanf("%d %d", &u, &v);
		insertedge(mat, u, v);
	}

	printf("\nAdjacency Matrix for the Given Graph:\n");
	printmat(mat, vert);

	int** tclose = warshall(mat, vert);

	printf("\nTransitive Closure for the Given Graph:\n");
	printmat(tclose, vert);


	return 0;
}

int** initmat(int v) {
	int** mat = (int**) calloc(v, sizeof(int*));

	for(int i=0; i<v; i++) {
		mat[i] = (int*) calloc(v, sizeof(int));
	}

	return mat;
}

void insertedge(int** mat, int u, int v) {
	mat[u][v] = 1;
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
			printf("\t%d", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int** warshall(int** mat, int n) {
	int** prev = NULL;
	int** curr = createcopy(mat, n);

	for(int k=0; k<n; k++) {
		prev = curr;
		curr = initmat(n);

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				curr[i][j] = prev[i][j] || (prev[i][k] && prev[k][j]);
			}
		}
	}

	return curr;
}