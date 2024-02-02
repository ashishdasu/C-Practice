/* command line 4 function calculator */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

int add(int a, int b) {
  return a + b;
}

int divide(int a, int b) {
  return a/b;
}

int multiply(int a, int b) {
  return a * b;
}

int subtract(int a, int b) {
  return a - b;
}

int main(int argc, char *argv[]) {
  int result;
  int (*fptr)(int, int);
  
  if (argc == 4) {
  
    if (strcmp(argv[2], "+") == 0)
      fptr = &add;
    
    else if (strcmp(argv[2], "-") == 0)
      fptr = &subtract;

    else if (strcmp(argv[2], "x") == 0)
      fptr = &multiply;

    else if (strcmp(argv[2], "/") == 0)
      fptr = &divide;

    else {
      printf("invalid operator: %s\n", argv[2]);
      return 1;
    }

    result = fptr(atoi(argv[1]), atoi(argv[3]));
    
  } else {
      printf("Usage: ./calculator [int] [operator(+,-,x,/)] [int]\n");
      return 1;
  }


  printf("result: %d\n", result);

  return 0;
}

  
