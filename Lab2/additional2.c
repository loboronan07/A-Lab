/* Additional Exercise 2
	Write a program to implement recursive solution to the Tower of Hanoi puzzle
	and analyze its time efficiency.
*/

#include <stdio.h>
#include <stdlib.h>

int tower_of_hanoi(int, char, char, char);

int main() {
	int n, opcount;

	printf("Enter the number of disks initially at source(rod A): ");
	scanf("%d", &n);

	printf("\n");

	opcount = tower_of_hanoi(n, 'A', 'B', 'C');

	printf("\nOperation Count: %d\n", opcount);

	return 0;
}

int tower_of_hanoi(int n, char source, char auxil, char dest) {
	int opcount=0;
	if(n > 1) {
		opcount += tower_of_hanoi(n-1, source, dest, auxil);
	}
	
	printf("Move disk %d from %c to %c.\n", n, source, dest);
	opcount++;

	if(n > 1) {
		opcount += tower_of_hanoi(n-1, auxil, source, dest);
	}

	return opcount;
}