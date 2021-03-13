#include <stdio.h>

void CallByValue(int i)
{
  int j = 1;
  printf("call by value: %p\n", &j);
}

void CallByPointer(int *i)
{
  int j = 1;
  printf("call by pointer: %p\n", &j);
}

void CallByReference(int &i)
{
  int j = 1;
  printf("call by reference: %p\n", &j);
}

int main()
{
  int i = 0;
  printf("stack bottom: %p\n", &i);

  CallByValue(i);
  CallByPointer(&i);
  CallByReference(i);

  return 0;
}

/*
  Resulting output:
  
  stack bottom:      0x7ffeedcc59f8
  call by value:     0x7ffeedcc59d8
  call by pointer:   0x7ffeedcc59d4
  call by reference: 0x7ffeedcc59d4

  `CallByValue` required 32 bytes of memory. This is reserved for the function return address and for the local variables within the function, including a copy of i.

  `CallByPointer` requires 36 bytes of memory. The size of the pointer variable is larger than the actual data type.

  `CallByReference` required 36 bytes of memory. To benefit from pass-by-reference, the size of the data passed must be larger than the size of the pointer on the respective arquitecture (32 and 64 bytes)
*/
