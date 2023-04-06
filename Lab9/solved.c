/* Solved Exercise
	Write a program to sort set of integers using comparison counting algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

int* countingsort(int*, int);

int main() {
	int *arr, n;

	printf("Enter the number of elements in array: ");
	scanf("%d", &n);

	arr = (int*) calloc(n, sizeof(int));

	printf("Enter %d elements into array: ", n);
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	printf("\nArray before sorting:\n");
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	arr = countingsort(arr, n);

	printf("\nArray after sorting:\n");
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	return 0;
}

int* countingsort(int* arr, int n) {
	int* counts = (int*) calloc(n, sizeof(int));

	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(arr[i] < arr[j]) {
				counts[j] += 1;
			}
			else {
				counts[i] += 1;
			}
		}
	}

	int* out = (int*) calloc(n, sizeof(int));

	for(int i=0; i<n; i++) {
		out[counts[i]] = arr[i];
	}

	free(arr);

	return out;
}
