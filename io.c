/* Exercise in validating command line arguments */

#include <stdio.h>
#include <stdlib.h>

void usage(char* arg) {
	printf("usage: %s -s string -n count [-h]\n", arg);
}

int validate_params(int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		printf("argument %d: %s ", i, argv[i]);
	}
	printf("\n");	
	return 0;
}

int main(int argc, char* argv[]) {
	int c;
	if (argc < 5) {
		usage(argv[0]);
		return 1;
	}
	validate_params(argc, argv);
	c = atoi(argv[4]);
	printf("count: %d\n", c);
	for (int i = 0; i < c; i++) {
		printf("%s\n", argv[2]);
	}
	return 0;
}
