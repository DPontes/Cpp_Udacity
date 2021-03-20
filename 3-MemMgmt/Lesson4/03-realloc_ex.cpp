#include <stdio.h>
#include <stdlib.h>

int main() {
  // reserve memory for 2 ints
  int *p = (int*)malloc(2*sizeof(int));
  p[0] = 1; p[1] = 2;       // even though p was not defined as an array, it can be treated as one to input data

  // resize memory to hold 4 ints
  p = (int*)realloc(p, 4*sizeof(int));
  p[2] = 3; p[3] = 4;       // with realloc, the data from the previous memory is retained

  /*
    Depending on the compiler, the reserved memory is either:
    a) expanded (if there is enough memory in the heap
    b) a new memory area is reserved in the desired size and the
    old memory is released afterwards.
  */

  // resize memory again to hold only 2 ints
  p = (int*)realloc(p, 2*sizeof(int));

  printf("address=%p, value=%d\n", p+0, *(p+0));
  printf("address=%p, value=%d\n", p+1, *(p+1));

  printf("address=%p, value=%d\n", p+2, *(p+2));    // These pointers and data can still be accessed - realloc doesn't erase memory,
  printf("address=%p, value=%d\n", p+3, *(p+3));    // it only makes it available for future allocations. Accessing deallocated data should be avoided

  free(p);

  return 0;
}
