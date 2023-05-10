/* Lab Exercise 3
	Write a program to implement 0/1 Knapsack problem using bottom-up dynamic
	programming
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)

int knapsack(int*, int*, int, int);
int** initmat(int, int);

int main() {
	int *weight, *value, n, B;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	weight = (int*) calloc(n+1, sizeof(int));
	value = (int*) calloc(n+1, sizeof(int));

	printf("Enter the elements as weight, value:\n");
	for(int i=1; i<=n; i++) {
		scanf("%d %d", weight+i, value+i);
	}

	printf("Enter the knapsack capacity: ");
	scanf("%d", &B);

	printf("Knapsack can contain elements with max value of %d.\n", knapsack(weight, value, n, B));

	return 0;
}

int knapsack(int* w, int* v, int n, int B) {
	int** f = initmat(n+1, B+1);
	int opcount = 0;

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=B; j++) {
			opcount++;
			if(j - w[i] >= 0) {
				f[i][j] = MAX(f[i-1][j], v[i] + f[i-1][j - w[i]]);
			}
			else {
				f[i][j] = f[i-1][j];
			}
		}
	}

	printf("Operation Count: %d\n", opcount);

	return f[n][B];
}

int** initmat(int m, int n) {
	int** mat = (int**) calloc(m, sizeof(int*));

	for(int i=0; i<m; i++) {
		mat[i] = (int*) calloc(n, sizeof(int));
	}

	return mat;
}
