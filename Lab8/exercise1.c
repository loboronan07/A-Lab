/* Lab Exercise 1
	Write a program to create a heap for the list of integers using top-down heap
	construction algorithm and analyze its time efficiency. Obtain the experimental
	results for order of growth and plot the result.
*/

#include <stdio.h>
#include <stdlib.h>

int opcount;

void heapify(int*, int);
void topdown(int*, int);
void swap(int*, int, int);

int main() {
	int *arr, n;

	printf("Enter the number of elements in array: ");
	scanf("%d", &n);

	arr = (int*) calloc(n+1, sizeof(int));

	printf("Enter %d elements into array: ", n);
	for(int i=1; i<=n; i++) {
		scanf("%d", arr+i);
	}

	printf("\nArray before heapify:\n");
	for(int i=1; i<=n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	heapify(arr, n);

	printf("\nArray after heapify:\n");
	for(int i=1; i<=n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

void heapify(int* arr, int n) {
	opcount = 0;

	for(int i=1; i<=n; i++) {
		topdown(arr, i);
	}

	printf("\nOpcount: %d\n", opcount);
}

void topdown(int* arr, int n) {
	int i = n;
	int k = n/2;

	while(k > 0) {
		opcount++;
		if(arr[k] < arr[i]) {
			swap(arr, k, i);
		}
		else {
			break;
		}
		i = k;
		k = k/2;
	}
}

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}