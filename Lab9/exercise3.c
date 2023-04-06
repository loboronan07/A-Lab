/* Lab Exercise 3
	Write a program to construct the closed hash table. Find the number of key
	comparisons in successful search and unsuccessful search.
*/

#include <stdio.h>
#include <stdlib.h>

#define EMPTY -5555

int opcount;

int* createhash(int*, int, int);
int search(int*, int, int);

int main() {
	int *arr, n;
	int *hash, key;
	int ele;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	arr = (int*) calloc(n, sizeof(int));

	printf("Enter %d elements into the array:\n", n);
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}

	printf("Enter the value of key for the hash table: ");
	scanf("%d", &key);

	hash = createhash(arr, n, key);

	printf("Enter the search element: ");
	scanf("%d", &ele);

	opcount = 0;

	if(search(hash, key, ele)) {
		printf("Search successfull with operation count %d...\n", opcount);
	}
	else {
		printf("Search unsuccessfull with operation count %d...\n", opcount);
	}

	free(hash);
	free(arr);

	return 0;
}

int* createhash(int* arr, int n, int key) {
	if(key < n) {
		printf("Number of elements is more than the key value.\n");
		printf("Closed Hashing Not Possible.");
		printf("Exiting from Program...\n");
		exit(1);
	}

	int* hash = (int*) calloc(key, sizeof(int));

	for(int i=0; i<key; i++) {
		hash[i] = EMPTY;
	}


	for(int i=0; i<n; i++) {
		int pos = arr[i] % key;

		int j=pos;

		do {
			if(hash[j] == EMPTY) {
				hash[j] = arr[i];
				break;
			}

			j = (j+1) % key;
		} while(j != pos);
	}

	return hash;
}

int search(int* hash, int key, int ele) {
	int pos = ele % key;

	int i = pos;

	do {
		opcount++;
		if(hash[i] == ele) {
			return 1;
		}
		else if(hash[i] == EMPTY) {
			return 0;
		}

		i = (i+1) % key;
	} while(i != pos);

	return 0;
}