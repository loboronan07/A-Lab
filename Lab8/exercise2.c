/* Lab Exercise2
	Write a program to sort the list of integers using heap sort with bottom up max heap
	construction and analyze its time efficiency. Prove experimentally that the worst
	case time complexity is O(n log n).
*/

#include <stdio.h>
#include <stdlib.h>

int opcount;

void heapify(int*, int);
void heapsort(int*, int);
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

	printf("\nArray before sorting:\n");
	for(int i=1; i<=n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	heapsort(arr, n);

	printf("\nArray after sorting:\n");
	for(int i=1; i<=n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}

void heapsort(int* arr, int n) {
	opcount = 0;

	for(int i=n; i>1; i--) {
		swap(arr, 1, i);
		heapify(arr, i-1);
	}

	printf("\nOperation Count: %d\n", opcount);
}

void heapify(int* h, int n) {
	int i, k, v, heapify, j;
	for(i = (n/2); i >= 1; i--) {
		k = i;
		v = h[k];
		heapify = 0;
		while(heapify==0 && 2*k<=n) {
			j = 2*k;
			
			opcount++;
			if(j < n) 
				if(h[j] < h[j+1])
					j=j+1;

			opcount++;
			if(v >= h[j])
				heapify=1;
			else {
				h[k] = h[j];
				k = j;
			}
		}
		h[k]=v;
	}
}

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}