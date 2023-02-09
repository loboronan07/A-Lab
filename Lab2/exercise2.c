/* Lab Exercise 2
	Write a program to find GCD using middle school method and analyze its time
	efficiency.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int midgcd(int, int);

int main() {
	unsigned int m, n, gcd;

	printf("Enter the two numbers whose GCD has to be calculated: ");
	scanf("%d %d", &m, &n);

	gcd = midgcd(m, n);

	printf("GCD of the two numbers is %d\n", gcd);

	return 0;
}

unsigned int midgcd(int m, int n) {
	printf("Calculating the GCD of the numbers using middle school method...\n");

	int opcount = 0;
	unsigned int gcd = 1;

	int i=2;
	while(m != 1 && n != 1) {
		int x = m%i;
		int y = n%i;

		if(x == 0) {
			m /= i;
		}
		if(y == 0) {
			n /= i;
		}

		if(x == 0 && y == 0) {
			gcd *= i;
		}
		else if(x != 0 && y != 0) {
			i++;
		}
		opcount++;
	}

	printf("Operation Count: %d\n", opcount);

	return gcd;
}