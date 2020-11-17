/*

    - Create a class Dog to inherit from Animal.
    - Define Dog::Talk() to override the virtual function Animal::Talk().
    - Confirm that the tests pass.

*/
#include <cassert>
#include <string>

class Animal {
  public:
    virtual std::string Talk() const = 0;
};

class Dog : public Animal {
  public:
    std::string Talk() const;
};

std::string Dog::Talk() const { return "Woof"; }

int main() {
    Dog dog;
    assert( dog.Talk() == "Woof" );

    return 0;
}
