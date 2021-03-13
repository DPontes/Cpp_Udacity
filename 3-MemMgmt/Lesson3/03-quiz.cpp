/*
Create a function AddFive that:
 - modifies the int input variable by adding 5
 - modifies the bool input variable to be true
*/
#include <iostream>

void AddFive(int &val, bool &success)
{
  val += 5;
  success = true;
}

int main()
{
  int val = 0;
  bool success = false;

  AddFive(val, success);

  val += 2;

  std::cout << "Val: " << val << std::endl;
  std::cout << "Success: " << success << std::endl;

  return 0;
}
