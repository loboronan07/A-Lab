/* Lab Exercise 1
	Write a program for assignment problem by brute-force technique and analyze its
	time efficiency. Obtain the experimental result of order of growth and plot the
	result.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int leastCost, *leastAssignment;
unsigned int n, **mat;
unsigned int opcount;

void initmat();
void solveassignment();
void recursiveassign(unsigned int*, int, unsigned int*);

int main() {
	printf("Enter the number of jobs: ");
	scanf("%d", &n);

	initmat();

	printf("Enter the cost matrix:\n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", mat[i]+j);
		}
	}

	solveassignment();

	return 0;
}

void initmat() {
	mat = (unsigned int**) calloc(n, sizeof(unsigned int*));

	for(int i=0; i<n; i++) {
		mat[i] = (unsigned int*) calloc(n, sizeof(unsigned int));
	}
}

void solveassignment() {
	opcount = 0;
	leastCost = 0;
	leastAssignment = (unsigned int*) calloc(n, sizeof(unsigned int));

	unsigned int* assigned = (unsigned int*) calloc(n, sizeof(unsigned int));
	unsigned int* marked = (unsigned int*) calloc(n, sizeof(unsigned int));

	recursiveassign(assigned, 0, marked);

	printf("\nThe least cost of assignment would be %d with the assignments as follows:\n", leastCost);
	printf("Person\tJob\n");
	for(int i=0; i<n; i++) {
		printf("%6d\t%3d\n", i, leastAssignment[i]);
	}
	printf("\n");

	printf("Operation Count: %d\n", opcount);
}

void recursiveassign(unsigned int* assigned, int pos, unsigned int* marked) {
	if(pos == n) {
		opcount++;
		int cost = 0;
		for(int i=0; i<n; i++) {
			cost += mat[i][assigned[i]];
		}
		if (leastCost == 0 || cost < leastCost) {
			leastCost = cost;
			for(int i=0; i<n; i++) {
				leastAssignment[i] = assigned[i];
			}
		}
	}
	else {
		for(int i=0; i<n; i++) {
			if(marked[i] == 0) {
				marked[i] = 1;
				assigned[pos] = i;
				recursiveassign(assigned, pos+1, marked);
				marked[i] = 0;
			}
		}
	}
	
}