/* Solved Exercise 
	Write a program to implement Knapsack problem using brute-force design technique
	and analyze its time efficiency. Obtain the experimental result of order of growth and plot
	the result. Knapsack Problem: Given n items of known weights w1, w2, ..wn values v1, v2,
	...vn and a knapsack of capacity B, find the most valuable subset of items that fit into the
	knapsack.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int knapsack(unsigned int* w, unsigned int* v, unsigned int n, unsigned int B) {
	unsigned int i, temp;
	unsigned int maxVal=0, maxSequence=0;
	unsigned int totalWeight, totalValue;
	int opcount=0;
	unsigned int index=0;

	for(i=1; i < pow(2, n); i++) {
		++opcount;
		temp = i;
		totalWeight = totalValue = 0;
		index = 0;
		while(temp) {
			if(temp & 0x1) {
				totalWeight = totalWeight + w[index];
				totalValue = totalValue + v[index];
			}
			index++;
			temp = temp >> 1;
		}

		if(totalWeight <= B && totalValue > maxVal) {
			maxVal = totalValue;
			maxSequence = i;
		}
	}

	printf("\nOperation Count: %d\n", opcount);
	return maxSequence;
}

int main() {
	unsigned int *w, *v, n, i, knaps, B;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	w = (int*) calloc(n, sizeof(unsigned int));
	v = (int*) calloc(n, sizeof(unsigned int));

	printf("Enter the elements as weight, value:\n");
	for(i=0; i<n; i++) {
		scanf("%d %d", w+i, v+i);
	}

	printf("Enter the knapsack capacity: ");
	scanf("%d", &B);

	knaps = knapsack(w, v, n, B);

	printf("Knapsack contains the following items:\n");
	printf("Item\tValue\tWeight\n");
	i=0;
	while(knaps) {
		if(knaps & 0x1) {
			printf("%4d\t%5d\t%6d\n", i+1, v[i], w[i]);
		}
		i++;
		knaps = knaps >> 1;
	}

	return 0;
}