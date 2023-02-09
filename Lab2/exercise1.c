/* Lab Exercise 1
	Write a program to find GCD using consecutive integer checking method and
	analyze its time efficiency.
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int consgcd(unsigned int, unsigned int);

int main() {
	unsigned int m, n, gcd;

	printf("Enter the two numbers whose GCD has to be calculated: ");
	scanf("%d %d", &m, &n);

	gcd = consgcd(m, n);

	printf("GCD of the two numbers is %d\n", gcd);

	return 0;
}

unsigned int consgcd(unsigned int m, unsigned int n) {
	printf("Calculating the GCD of the numbers using consecutive integer checking method...\n");

	unsigned int t = m < n ? m : n;
	int opcount = 0;

	while(t > 1) {
		if(m%t == 0 && n%t == 0) {
			break;
		}

		t--;
		opcount++;
	}

	printf("Operation Count: %d\n", opcount);

	return t;
}