/* Additional Exercise 1
	Write a program in C to find a^n where n > 0 using divide and conquer strategy.
*/

#include<stdio.h>
#include<stdio.h>

int pow(int, int);

int main() {
	int a, n;

	printf("Enter the base: ");
	scanf("%d", &a);

	printf("Enter the exponent: " );
	scanf("%d", &n);

	int ans = pow(a, n);

	printf("%d ^ %d = %d\n", a, n, ans);

	return 0;
}

int pow(int a, int n) {
	if(n == 0) {
		return 1;
	}

	if(n % 2 == 0) {
		int temp = pow(a, n/2);
		return temp * temp;
	}
	else {
		int temp = pow(a, (n-1)/2);
		return temp * temp * a;
	}
}