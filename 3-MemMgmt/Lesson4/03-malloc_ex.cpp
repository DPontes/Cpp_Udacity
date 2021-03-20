#include <stdio.h>
#include <stdlib.h>

int main()
{
  // void *p = malloc(3*sizeof(int));   <- Throws an error/warning as it's not possible to know the offset of the memory block.
  int *p = (int*)malloc(3*sizeof(int));
  printf("address=%p, value=%d\n", p, *p);

  free(p);

  return 0;
}
