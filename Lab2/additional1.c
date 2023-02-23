/* Additional Exercise 1
    Write a program for computing ⌊√n⌋ for any positive integer and analyze its time 
    efficiency. Besides assignment and comparison, your program may only use the 
    four basic arithmetic operations.
*/

#include <stdio.h>
#include <stdlib.h>

int sqrt(int);

int main() {
    int n;
    
    printf("Enter the number, n: ");
    scanf("%d", &n);

    printf("The ⌊√n⌋ is = %d\n", sqrt(n));

    return 0;
}

int sqrt(int n) {
    int opcount=0;
    int root=n;
    int prev=1;

    while(prev != root) {
        opcount++;
        prev = root;
        root = 0.5 * (root + (n/root));
    }

    printf("Operation Count: %d\n", opcount);

    return root;
}