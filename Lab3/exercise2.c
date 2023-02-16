/* Lab Exercise 2
	Write a program to implement brute-force string matching. Analyze its time
	efficiency.
*/

#include <stdio.h>
#include <string.h>

int stringmatch(char* str, char* pat) {
	int m = strlen(str);
	int n = strlen(pat);

	int flag = 0;
	int opcount = 0;

	if(m >= n) {
		for(int i=0; i <= m-n; i++) {
			flag = 1;
			for(int j=0; j<n; j++) {
				opcount++;
				if(str[i+j] != pat[j]) {
					flag = 0;
					break;
				}
			}

			if(flag) {
				break;
			}
		}
	}

	printf("Operation Count: %d\n", opcount);
	return flag;
}

int main() {
	char str[100], pat[100];

	printf("Enter the input string: ");
	scanf(" %[^\n]s", str);

	printf("Enter the pattern string: ");
	scanf(" %[^\n]s", pat);

	if(stringmatch(str, pat)) {
		printf("Pattern Found in String...\n");
	}
	else {
		printf("Pattern Not Found in String...\n");
	}

	return 0;
}