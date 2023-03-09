/* Solved Exercise 
	Write a program to sort a set of numbers using insertion sort and analyze its time
	efficiency. Obtain the experimental result of order of growth and plot the result.
*/

#include <stdio.h>
#include <stdlib.h>

void sort(int*, int);
void printarr(int*, int);

int main() {
	int n;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int* arr = (int*) malloc(n * sizeof(int));

	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	printf("Array before sorting:\n");
	printarr(arr, n);

	sort(arr, n);

	printf("Array after sorting:\n");
	printarr(arr, n);

	return 0;
}

void printarr(int* arr, int n) {
	for(int i=0; i<n; i++) {
		printf("\t%d", arr[i]);
	}
	printf("\n");
}


void sort(int* arr, int n) {
	int opcount = 0;

	for(int i=0; i<n; i++) {
		int piv = arr[i];
		int j = i-1;

		while(++opcount && j >= 0 && arr[j] > piv) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = piv;
	}
	printf("Operation Count: %d\n", opcount);
}