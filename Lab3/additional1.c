/* Additional Exercise 1 
	Write a program to implement matrix multiplication using brute-force technique
	and analyze its time efficiency. Obtain the experimental result of order of growth.
	Plot the result for the best and worst case.
*/

#include <stdio.h>
#include <stdlib.h> 

int** getmat(char, int, int);
int** matmul(int**, int, int, int**, int, int);
void printmat(int**, int, int);
void freemat(int**, int, int);

int main() {
	int **A, **B, **C;
	int m1, m2, n1, n2;

	printf("Enter the dimension of matrix A: ");
	scanf("%d %d", &m1, &n1);

	A = getmat('A', m1, n1);

	printf("Enter the dimension of matrix B: ");
	scanf("%d %d", &m2, &n2);

	B = getmat('B', m2, n2);

	C = matmul(A, m1, n1, B, m2, n2);

	if(C != NULL) {
		printf("Resultant matrix C = A*B is\n");
		printmat(C, m1, n2);
		freemat(C, m1, n2);
	}

	freemat(A, m1, n1);
	freemat(B, m2, n2);

	return 0;
}

int** getmat(char name, int m, int n) {
	int **mat = (int**) calloc(m, sizeof(int*));

	printf("Enter the elements for matrix %c:\n", name);
	for(int i=0; i<m; i++) {
		mat[i] = (int*) calloc(n, sizeof(int));

		for(int j=0; j<n; j++) {
			scanf("%d", mat[i]+j);
		}
	}

	return mat;
}

int** matmul(int** A, int m1, int n1, int** B, int m2, int n2) {
	int** C = NULL;

	if(n1 != m2) {
		printf("Matrices Incompatible...\n");
		return NULL;
	}

	int opcount=0;

	C = (int**) calloc(m1, sizeof(int*));

	for(int i=0; i<m1; i++) {
		C[i] = (int*) calloc(n2, sizeof(int));

		for(int j=0; j<n2; j++) {
			C[i][j] = 0;

			for(int k=0; k<n1; k++) {
				opcount++;
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	printf("Operation Count: %d\n", opcount);

	return C;
}

void printmat(int** mat, int m, int n) {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			printf("\t%d", mat[i][j]);
		}
		printf("\n");
	}
}

void freemat(int** mat, int m, int n) {
	for(int i=0; i<m; i++) {
		free(mat[i]);
	}

	free(mat);
}