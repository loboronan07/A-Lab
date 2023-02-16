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

	for(n=10; n<101; n+=10) {
		printf("Number of elements: %d\n", n);

		arr = (int*) calloc(n, sizeof(int));

		for(int i=0; i<n; i++) {
			arr[i] = n-i;
		}

		bubblesort(arr, n);

		free(arr);

		printf("\n");
	}

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
