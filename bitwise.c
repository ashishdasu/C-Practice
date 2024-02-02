/* command line bitwise sum calculator */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
  int temp = atoi(argv[2]), carry, sum = atoi(argv[1]);
  printf("%d", temp);  
  while (temp != 0) {
    
    carry = sum & atoi(argv[2]);
    sum = sum ^ atoi(argv[2]);

    temp = carry << 1;

  }

  printf("Sum: %d\n", sum);
  return 0;  
}
