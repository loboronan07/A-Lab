/* Additional Exercise 1
	Write a program to implement 0/1 Knapsack problem using memory function.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)

int *weight, *value, n, B;

int knapsack();
int mfknapsack(int**, int, int);
int** initmat(int, int);

int main() {
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

	printf("Knapsack can contain elements with max value of %d.\n", knapsack());

	return 0;
}

int knapsack() {
	int** f = initmat(n+1, B+1);

	return mfknapsack(f, n, B);
}

int mfknapsack(int** f, int i, int j) {
    if(f[i][j] < 0) {
        if(j < weight[i]) {
            f[i][j] = mfknapsack(f, i-1, j);
        }
        else {
            f[i][j] = MAX(mfknapsack(f, i-1, j), value[i] + mfknapsack(f, i-1, j-weight[i]));
        }
    }
    
    return f[i][j];
}

int** initmat(int m, int n) {
	int** mat = (int**) calloc(m, sizeof(int*));

	for(int i=0; i<m; i++) {
		mat[i] = (int*) calloc(n, sizeof(int));
		if(i == 0) {
			continue;
		}
		for(int j=1; j<n; j++) {
        		mat[i][j] = -1;
        	}
	}

	return mat;
}
