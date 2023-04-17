/* Additional Exercise 1
    Write a program to implement Boyer-Moore algorithm for String Matching and 
    find the number of key comparisons in successful search and unsuccessful search. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? a : b)

int* createBadSymTable(char*);
int* createGoodSuffTable(char*);
int strmatch(char*, char*);

int main() {
	char text[100], pat[100];
	int pos;

	printf("Enter the text string:\n");
	scanf(" %[^\n]s", text);

	printf("Enter the pattern string:\n");
	scanf(" %[^\n]s", pat);

	pos = strmatch(text, pat);

	if(pos < 0) {
		printf("Pattern not found in text...\n");
	}
	else {
		printf("Pattern found at position %d...\n", pos);
	}

	return 0;
}


int* createBadSymTable(char* str) {
	int* table = (int*) calloc(256, sizeof(int));
	int len = strlen(str);
	
	for(int i=0; i<256; i++) {
		table[i] = len;
	}

	for(int i=0; i<len-1; i++) {
		table[str[i]] = len-i-1;
	}

	return table;
}

int* createGoodSuffTable(char* pat) {
    int m = strlen(pat);

    int* table = (int*) calloc(m, sizeof(int));

    for(int i=1; i<m; i++) {
        int k=m-i; 

        for(int j=0; j<m-i; j++) {
            int l = 0;

            while(l<i && pat[j+l]==pat[k+l]) {
                l++;
            }

            if(l == i && (j == 0 || pat[j-1] != pat[k-1])) {
                table[i] = m-j-i;
            }
        }

        if(table[i] > 0) {
            k = k+1;
            int l = 0;
            while(k < m && pat[k] == pat[l]) {
                k++; l++;
            }

            if(k == m) {
                table[i] = m-i+1;
            }
            else {
                table[i] = table[i-1];
            }
        }
    }

    return table;
}

int strmatch(char* text, char* pat) {
    int m = strlen(pat);
    int n = strlen(text);

    int* badSym = createBadSymTable(pat);
    int* goodSuf = createGoodSuffTable(pat);

    int i = m-1;

	while(i<n) {
	    printf("%d\n", i);
		int k = 0;

		while(k<m && pat[m-1-k]==text[i-k]) {
			k++;
		}

		if(k == m) {
			return i-m+1;
		}
		else {
            int d1 = MAX(badSym[text[i-k]]-k, 1);
            int d2 = goodSuf[k];

            if(k == 0) {
                i += d1;
            }
            else {
                i += MAX(d1, d2);
            }
		}
	}

    return -1;
}