/* Lab Exercise 2
	Sort given set of integers using Quick sort and analyze its efficiency. Obtain the
	experimental result of order of growth and plot the result.
*/

#include<stdio.h>
#include<stdlib.h>

int opcount;

void quicksort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int, int);

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
	quicksort(arr, 0, n-1);

	printf("\nArray elements after sorting:\n");
	for(int i=0; i<n; i++) {
		printf("\t%d", arr[i]);
	}
	printf("\nOperation Count: %d\n", opcount);

	return 0;
}

void quicksort(int* arr, int l, int r) {
	if(l < r) {
		int s = partition(arr, l, r);
		quicksort(arr, l, s-1);
		quicksort(arr, s+1, r);
	}
}

int partition(int* arr, int l, int r) {
	int p = arr[l];
	int i=l;
	int j=r+1;

	do {
		do {
			i++;
			opcount++;
		} while(i <= r && arr[i] < p);

		do {
			j--;
			opcount++;
		} while(arr[j] > p);

		if(i > r) {
			i--;
		}

		swap(arr, i, j);

	} while(i < j);

	swap(arr, i, j);

	swap(arr, l, j);

	return j;
}

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}