/* Additional Exercise 2
    Write a program to sort the elements using distribution counting method. 
*/

#include <stdio.h>
#include <stdlib.h>

int* distributionsort(int*, int);
void getminmax(int*, int, int*, int*);

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

	arr = distributionsort(arr, n);

	printf("\nArray after sorting:\n");
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);

	return 0;
}

int* distributionsort(int* arr, int n) {
	int min, max;
	getminmax(arr, n, &min, &max);

	int* counts = (int*) calloc(max-min+1, sizeof(int));

	for(int i=0; i<n; i++) {
		counts[arr[i]-min] += 1;
	}

	for(int i=1; i<max-min+1; i++) {
		counts[i] += counts[i-1];
	}

	int* out = (int*) calloc(n, sizeof(int));

	for(int i=n-1; i>=0; i--) {
		int j = arr[i] - min;
		out[counts[j]-1] = arr[i];
		counts[j]--;
	}

	free(arr);

	return out;
}

void getminmax(int* arr, int n, int* min, int* max) {
	*min = *max = *arr;

	for(int i=1; i<n; i++) {
		if(arr[i] < *min) {
			*min = arr[i];
		}
		if(arr[i] > *max) {
			*max = arr[i];
		}
	}
}