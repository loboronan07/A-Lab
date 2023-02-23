/* Additional Exercise 3
	Write a program to compute the nth Fibonacci number recursively and analyze its
	time efficiency.
*/

#include <stdio.h>
#include <stdlib.h>

int opcount;

int fibonacci(int);

int main() {
	int n, fib;
	opcount = 0;

	printf("Enter the number n: ");
	scanf("%d", &n);

	fib = fibonacci(n);

	printf("Fib(%d) = %d\n", n, fib);
	printf("Operation Count: %d\n", opcount);

	return 0;
}

int fibonacci(int n) {
	if(n<3) {
		return n-1;
	}

	opcount++;
	return fibonacci(n-1) + fibonacci(n-2);
}