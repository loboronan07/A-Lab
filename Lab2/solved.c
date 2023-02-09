/* Lab Exercise 1
	Write an algorithm for finding the Greatest Common Divisor (GCD) of two numbers
	using Euclid’s algorithm and implement the same. Determine the time complexity of the
	algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int eucgcd(unsigned int, unsigned int);

int main() {
	unsigned int m, n, gcd;

	printf("Enter the two numbers whose GCD has to be calculated: ");
	scanf("%d %d", &m, &n);

	gcd = eucgcd(m, n);

	printf("GCD of the two numbers is %d\n", gcd);

	return 0;
}

unsigned int eucgcd(unsigned int m, unsigned int n) {
	printf("Calculating the GCD of the numbers using Euclid's algorithm...\n");

	unsigned int r;
	int opcount = 0;

	while(n != 0) {
		r = m % n;
		m = n;
		n = r;
		opcount++;
	}

	printf("Operation Count: %d\n", opcount);

	return m;
}