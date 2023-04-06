/* Additional Exercise 1
    Write a program to check whether an array H[1..n] is a heap or not.
*/

#include <stdio.h>
#include <stdlib.h>

int isheap(int*, int, int);

int main() {
    int *arr, n;

	printf("Enter the number of elements in array: ");
	scanf("%d", &n);

	arr = (int*) calloc(n+1, sizeof(int));

	printf("Enter %d elements into array: ", n);
	for(int i=1; i<=n; i++) {
		scanf("%d", arr+i);
	}

	if(isheap(arr, 1, n)) {
        printf("The given array is a heap.\n");
    }
    else {
        printf("The given array is not a heap.\n");
    }

    return 0;
}

int isheap(int* arr, int curr, int n) {
    int child = curr*2;

    if(child > n) {
        return 1;
    }
    else if(arr[child] > arr[curr]) {
        return 0;
    }
    else if(!isheap(arr, child, n)) {
        return 0;
    }

    child += 1;

    if(child > n) {
        return 1;
    }
    else if(arr[child] > arr[curr]) {
        return 0;
    }
    else if(!isheap(arr, child, n)) {
        return 0;
    }

    return 1;
}