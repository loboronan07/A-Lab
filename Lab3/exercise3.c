/* Lab Exercise 3
	Write a program to implement solution to partition problem using brute-force
	technique and analyze its time efficiency theoretically. A partition problem takes
	a set of numbers and finds two disjoint sets such that the sum of the elements in
	the first set is equal to the second set. [Hint: You may generate power set]
*/

#include <stdio.h>
#include <stdlib.h>

int *arr, *mark;
unsigned int n, opcount;
int target;

int incrementmark();
int getmarkedsum();
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
		mark = (int*) calloc(n, sizeof(int));
		while(1) {
			opcount++;
			if(incrementmark()) {
				if(getmarkedsum() == sum/2) {
					flag = 1;
					break;
				}
			}
			else {
				break;
			}
		}
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

int getmarkedsum() {
	int sum = 0;

	for(int i=0; i<n; i++) {
		if(mark[i] == 1) {
			sum += arr[i];
		}
	}

	return sum;
}

int incrementmark() {
	int carry = 1;
	int sum = 0;

	for(int i=0; i<n && carry==1; i++) {
		sum = mark[i] + carry;
		mark[i] = sum%2;
		carry = sum/2;
	}

	return carry==0;
}