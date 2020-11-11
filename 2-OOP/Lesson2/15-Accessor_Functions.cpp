/*
    Encapsulation 2
    Cpp Guidelines mentions that one should not add trivial getter and setter
    functions if these are only getting and retrieving info.
    Core guidelines suggest having the variables made public
*/
#include <iostream>
#include <string>

class BankAccount {
  private:

  public:
    double funds;
    int number;
    std::string owner;
};


int main() {
    BankAccount account;

    account.number = 12345678;
    account.owner  = "Tom Brady";
    account.funds  = 100000;

    std::cout << "Account Information:" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "Owner: " << account.owner << std::endl;
    std::cout << "Number: " << account.number << std::endl;
    std::cout << "Funds: " << account.funds << "€" << std::endl;
    return 0;
}
