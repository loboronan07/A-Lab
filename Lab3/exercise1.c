/* Lab Exerscise 1
	Write a program to sort set of integers using bubble sort. Analyze its time
	efficiency. Obtain the experimental result of order of growth. Plot the result for
	the best and worst case.
*/

#include <stdio.h>
#include <stdlib.h>

void bubblesort(int*, unsigned int);

int main() {
	int* arr;
	unsigned int n;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	arr = (int*) calloc(n, sizeof(int));

	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	printf("\nElements before sorting: ");
	for(int i=0; i<n; i++) {
		printf("\t%d", *(arr+i));
	}
	printf("\n");

	bubblesort(arr, n);

	printf("\nElements after sorting: ");
	for(int i=0; i<n; i++) {
		printf("\t%d", *(arr+i));
	}
	printf("\n");

	return 0;
}

void bubblesort(int *arr, unsigned int n) {
	int opcount = 0;
	int swap = 0;
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
			opcount++;
			if(arr[j] > arr[j+1]) {
				swap = 1;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}

		if(!swap) {
			break;
		}
		swap = 0;
	}

	printf("Operation Count: %d\n", opcount);
}