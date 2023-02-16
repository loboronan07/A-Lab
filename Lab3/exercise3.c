/* Lab Exercise 3
	Write a program to implement solution to partition problem using brute-force
	technique and analyze its time efficiency theoretically. A partition problem takes
	a set of numbers and finds two disjoint sets such that the sum of the elements in
	the first set is equal to the second set. [Hint: You may generate power set]
*/

#include <stdio.h>
#include <stdlib.h>

void finddisjoint(int*, unsigned int);
int findpartition(int*, int*, unsigned int, int, int, int, int*);

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

	finddisjoint(arr, n);

	free(arr);

	return 0;
}

void finddisjoint(int* arr, unsigned int n) {
	int sum = 0;
	int opcount = 0;
	int flag = 0;
	int* mark = NULL;

	for(int i=0; i<n; i++) {
		sum += arr[i];
	}

	if(sum%2 == 0) {
		sum = sum/2;

		mark = (int*) calloc(n, sizeof(int));

		flag = findpartition(arr, mark, n, 0, 0, sum, &opcount);
	}

	printf("Operation Count: %d\n", opcount);

	if(flag) {
		printf("The Set Can Be Partitioned...\n");
		printf("Set 1: ");
		for(int i=0; i<n; i++) {
			if(mark[i] == 1) {
				printf("\t%d", arr[i]);
			}
		}
		printf("\n");

		printf("Set 2: ");
		for(int i=0; i<n; i++) {
			if(mark[i] == 0) {
				printf("\t%d", arr[i]);
			}
		}
		printf("\n");
	}
	else {
		printf("The Set Cannot Be Partitioned...\n");
	}

	if(mark) {
		free(mark);
	}
}

int findpartition(int *arr, int* mark, unsigned int n, int i, int sum, int target, int* opcount) {
	*opcount += 1;
	sum += arr[i];
	mark[i] = 1;

	if(sum == target) {
		return 1;
	}
	else if(sum > target) {
		mark[i] = 0;
		return 0;
	}

	for(int j=i+1; j<n; j++) {
		if(findpartition(arr, mark, n, j, sum, target, opcount)) {
			return 1;
		}
	}

	mark[i] = 0;
	return 0;
}