/* Lab Exercise 1
	Write a program to compute the transitive closure of a given directed graph using
	Warshall’s algorithm and analyse its time efficiency. Obtain the experimental results
	for order of growth and plot the result.
*/

#include <stdio.h>
#include <stdlib.h>

int** initmat(int);
void insertedge(int**, int, int);
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
	int** curr = mat;
	int opcount = 0;

	for(int k=0; k<n; k++) {
		prev = curr;
		curr = initmat(n);

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				opcount++;
				curr[i][j] = prev[i][j] || (prev[i][k] && prev[k][j]);
			}
		}
	}

	printf("\nOperation Count: %d\n", opcount);

	return curr;
}
