#include <stdio.h>
#include <stdlib.h>

struct MyStruct{
  int i;
  double d;
  char a[5];
};

int main()
{
  MyStruct *p = (MyStruct*)calloc(4,sizeof(MyStruct));

  p[0].i = 1;
  p[1].d = 3.14159;
  p[2].a[0] = 'a';

  printf("The information in the struct is:\n");
  printf("int address=%p, int value=%d\n", p+0, p[0].i);
  printf("double adress=%p, double value=%f\n", p+1, p[1].d);
  printf("char address=%p, char value=%c", p+2, p[2].a[0]);

  free(p);

  return 0;
}
