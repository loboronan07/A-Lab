/* Lab Exercise 1
    Write a program to find the solution to the subset-sum problem using backtracking. 
    Consider the test case S={1, 2, 5, 6, 8} and d=9, to verify your answer. 
*/

#include <stdio.h>
#include <stdlib.h>

int *arr, *mark;
int n, d;

void getsubsets(int, int, int);
int sum();
void printmarked();

int main() {
    printf("Enter the number of values in set: ");
    scanf("%d", &n);

    arr = (int*) calloc(n, sizeof(int));

    printf("Enter the values: ");
    for(int i=0; i<n; i++) {
        scanf("%d", arr+i);
    }

    printf("Enter the value for target sum, d: ");
    scanf("%d", &d);

    mark = (int*) calloc(n, sizeof(int));

    printf("\nSubsets with target sum:\n");
    getsubsets(0, 0, sum());

    return 0;
}

int sum() {
    int s = 0;
    for(int i=0; i<n; i++) {
        s += arr[i];
    }
    return s;
}

void printmarked() {
    for(int i=0; i<n; i++) {
        if(mark[i] == 1) {
            printf("\t%d", arr[i]);
        }
    }
    printf("\n");
}

void getsubsets(int i, int s, int r) {
    if(s > d || s+r < d) {
        return;
    }

    if(s == d) {
        printmarked();
    }
    else {
        mark[i] = 1;
        getsubsets(i+1, s+arr[i], r-arr[i]);

        mark[i] = 0;
        getsubsets(i+1, s, r-arr[i]);
    }
}
