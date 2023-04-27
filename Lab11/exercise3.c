/* Lab Exercise 3
	Write a program to implement Huffman tree construction algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int isdata;
	char data;
	float freq;
	struct node* left;
	struct node* right;
} node;


int main() {

	printf("Enter the number of characters: ");
	scanf("%d", &n);

	char* characters = (char*) calloc(n, sizeof(char));
	float* freq = (float*) calloc(n, sizeof(float));

	printf("Enter the data as characters, freq:\n");
	for(int i=0; i<n; i++) {
		scanf(" %c %f", characters+i, freq+i);
	}

	return 0;
}



void sort(node** nodes, int n) {
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-i-1; j++) {
			if(nodes[j]->freq < nodes[j+1]->freq) {
				node temp = nodes[j];
				nodes[j] = nodes[j+1];
				nodes[j+1] = temp;
			}
		}
	}
}
