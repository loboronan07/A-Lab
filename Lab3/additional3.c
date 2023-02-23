/* Additional Exercise 3
	Write a program to implement solution to partition problem using recursion.
*/

#include <stdio.h>
#include <stdlib.h>

int *arr, *mark;
unsigned int n, opcount;
int target;

void finddisjoint();
int findpartition(int, int);

int main() {
	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	arr = (int*) calloc(n, sizeof(int));

	printf("Enter the elements of the array: ");
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	finddisjoint();

	free(arr);
    arr = NULL;

	return 0;
}

void finddisjoint() {
	int sum = 0;
    int flag = 0;

	opcount = 0;
	mark = NULL;

	for(int i=0; i<n; i++) {
		sum += arr[i];
	}

	if(sum%2 == 0) {
		target = sum/2;

		mark = (int*) calloc(n, sizeof(int));

		flag = findpartition(0, 0);
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
        mark = NULL;
	}
}

int findpartition(int i, int sum) {
	opcount += 1;
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
		if(findpartition(j, sum)) {
			return 1;
		}
	}

	mark[i] = 0;
	return 0;
}