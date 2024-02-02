/* prints number of white space, single digit numbers, and other characters in a given file */

#include <stdio.h>

int main() {
	int c, i, nwhite, nother;
	int ndigits[10];
	nwhite = nother = 0;

	for (i = 0; i < 10; i++) {
		ndigits[i] = 0;
	}
	
	while((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			++ndigits[c - '0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}
	
	int count = 0;
	printf("Digits: ");
	while (count < 10) {
		printf("%d", ndigits[count]);
		count++;
	}
	
	printf("\nwhite space: %d\n other: %d\n", nwhite, nother);
}
