#include <iostream>

void AddFour(int &val)
{
  val += 4;
}

int main()
{
  int val = 0;
  AddFour(val);

  val += 2;

  std::cout << "Val: " << val << std::endl;

  return 0;
}

/*
The function receives a reference to the parameter, rather than a copy of its value.
The function can now modify the argument such that the changes also happen on the caller side.
In addition to the possibility to directly exchange information between function and caller,
passing variables by reference is also faster as no information needs to be copied,
as well as more memory-efficient.
A major disadvantage is that the caller does not always know what will happen to the data it passes to a function.
Since a reference to a variable is treated exactly the same as the variable itself,
any changes made to the reference are passed through to the argument.
*/
