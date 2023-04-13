/* Additional Exercise 2
	Write a function to find the composition of an optimal subset from the table generated 
    by the bottom-up dynamic programming algorithm for the knapsack problem. 
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) ((a) > (b) ? a : b)

int *w, *v, n, B;

void knapsack();
int** initmat(int, int);
int* getcomposition(int**);

int main() {
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	w = (int*) calloc(n, sizeof(int));
	v = (int*) calloc(n, sizeof(int));

	printf("Enter the elements as weight, value:\n");
	for(int i=0; i<n; i++) {
		scanf("%d %d", w+i, v+i);
	}

	printf("Enter the knapsack capacity: ");
	scanf("%d", &B);

	knapsack();

	return 0;
}

void knapsack() {
	int** f = initmat(n+1, B+1);

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=B; j++) {
			if(j - w[i-1] >= 0) {
				f[i][j] = MAX(f[i-1][j], v[i-1] + f[i-1][j - w[i-1]]);
			}
			else {
				f[i][j] = f[i-1][j];
			}
		}
	}

    int* assignment = getcomposition(f);

    printf("Knapsack Should contain the following items for the optimal subset:\n");
    printf("%10s%10s%10s\n", "Item No.", "Weight", "Value");
    for(int i=0; i<n; i++) {
        if(assignment[i] == 1) {
            printf("%10d%10d%10d\n", i+1, w[i], v[i]);
        }
    }

    printf("%20s%10d", "Total:", f[n][B]);
}

int* getcomposition(int** f) {
    int* arr = (int*) calloc(n, sizeof(int));

    int i=n, j=B;
    while(i>0 && j>0) {
        if(j - w[i-1] >= 0) {
            if(f[i-1][j] > v[i-1] + f[i-1][j-w[i-1]]) {
                i = i - 1;
            }
            else {
                arr[i-1] = 1;
                j = j - w[i-1];
                i = i - 1;
            }
        }
        else {
            i = i - 1;
        }
    }

    return arr;
}

int** initmat(int m, int n) {
	int** mat = (int**) calloc(m, sizeof(int*));

	for(int i=0; i<m; i++) {
		mat[i] = (int*) calloc(n, sizeof(int));
	}

	return mat;
}
