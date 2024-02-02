/* prints character, word, and line counts of a given file */

#include <stdio.h>
#include <stdbool.h>

int main() {
	int chars, words, lines, c;
	chars = words = lines = c = 0;
	bool state = true;
	bool ending = false;
	while ((c = getchar()) != EOF) {
		++chars;
		if (c == '\n')
			++lines;
		if (c == ' ' || c == '\n' || c == '\t')
			state = false;
		else if (!state) {
			state = true;
			++words;
		}
		if (c == '\r') {
			++lines;
			if (ending)
				return 0;
			else
				ending = true;
		}
	}
	printf("\nchars: %d    words: %d    lines: %d\n", chars, words, lines);			
}


