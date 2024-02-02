/* print concatenated strings if given as valid command line arguments */

#include <stdio.h>
#include <stdlib.h>

static int mystrlen(const char *instr) {
	char *str;
	int count = 0;

	str = (char*)instr;
	if (str == NULL)
		return -1;
	
	while (*str++ != '\0') {
		count++;
	}

	return count;
}

char* (fnptr_concat*)(const char*, const char*);

static char* concat(const char* str1, const char* str2) {
	int sl1, sl2, sltotal;
	char *ret_str, *concat_str;

	/* string length for malloc */
	sl1 = (mystrlen(str1) != -1) ? mystrlen(str1) : 0;
	sl2 = (mystrlen(str2) != -1) ? mystrlen(str2) : 0;
	sltotal = sl1 + sl2;

	/* if both parameters are null or empty */
	if (sltotal == 0) 
		return NULL;

	ret_str = (char*)malloc(sizeof(char) * sltotal + 1);
	concat_str = ret_str;
	if (ret_str == 0)
		printf("allocation failed\n");

	if (str1) {
		while (*str1 != '\0') {
			*ret_str++ = *str1++;
		}
	}
	
	if (str2) {
		while (*str2 != '\0') {
			*ret_str++ = *str2++;
		}	
	}

	*ret_str = '\0';
	return concat_str;
}

int main(int argc, char* argv[]) {
	int len = mystrlen(argv[1]);
	char *s = concat(argv[1], argv[2]); 

	printf("%d\n", len);
	printf("concatenated string: %s\n", s);

	return 0;
}


