/* Additional Exercise 4
    Write a program to sort a set of strings using Bubble Sort. Analyze its time
    efficiency. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

void bubblesort(char**, unsigned int);

int main() {
	char** arr;
	unsigned int n;

    char str[100];

	printf("Enter the number of strings in the array: ");
	scanf("%d", &n);

	arr = (char**) calloc(n, sizeof(char*));

	printf("Enter the strings:\n");
	for(int i=0; i<n; i++) {
		scanf(" %[^\n]s", str);
        arr[i] = (char*) calloc(strlen(str)+1, sizeof(char));
        strcpy(arr[i], str);
	}

	printf("\nElements before sorting:\n");
	for(int i=0; i<n; i++) {
		printf("\t%s\n", arr[i]);
	}
	printf("\n");

	bubblesort(arr, n);

	printf("\nElements after sorting:\n");
	for(int i=0; i<n; i++) {
		printf("\t%s\n", arr[i]);
	}
	printf("\n");

    for(int i=0; i<n; i++) {
        free(arr[i]);
    }
    free(arr);

	return 0;
}

void bubblesort(char** arr, unsigned int n) {
	int opcount = 0;
	int swap = 0;
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
			opcount++;
			if(strcmp(arr[j], arr[j+1]) > 1) {
				swap = 1;
				char* temp = arr[j];
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