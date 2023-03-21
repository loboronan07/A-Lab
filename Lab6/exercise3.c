/* Lab Exercise 3
	Sort given set of integers using Merge sort and analyze its efficiency. Obtain the
	experimental result of order of growth and plot the result.
*/

#include<stdio.h>
#include<stdlib.h>

int opcount;

void mergesort(int*, int);
void merge(int*, int, int*, int, int*, int);

int main() {
	int *arr, n;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	arr = (int*) calloc(n, sizeof(int));

	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	printf("\nArray elements before sorting:\n");
	for(int i=0; i<n; i++) {
		printf("\t%d", arr[i]);
	}

	opcount = 0;
	mergesort(arr, n);

	printf("\nArray elements after sorting:\n");
	for(int i=0; i<n; i++) {
		printf("\t%d", arr[i]);
	}
	printf("\nOperation Count: %d\n", opcount);

	return 0;
}

void mergesort(int* A, int n) {
	if(n < 2) {
		return;
	}
	
	int p = n/2;
	int *B = (int*) calloc(p, sizeof(int));
	for(int i=0; i<p; i++) {
		B[i] = A[i];
	}
	mergesort(B, p);

	int q = n-p;
	int *C = (int*) calloc(q, sizeof(int));
	for(int i=0; i<q; i++) {
		C[i] = A[p+i];
	}
	mergesort(C, q);

	merge(B, p, C, q, A, n);
}

void merge(int* B, int p, int* C, int q, int* A, int n) {
	int i=0, j=0, k=0;

	while(i < p && j < q) {
		opcount++;
		if(B[i] < C[j]) {
			A[k++] = B[i++];
		}
		else {
			A[k++] = C[j++];
		}
	}

	if(i == p) {
		while(j < q) {
			A[k++] = C[j++];
		}
	}
	else {
		while(i<p) {
			A[k++] = B[i++];
		}
	}
}