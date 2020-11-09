// Initialization List
#include <assert.h>
#include <string>

class Person {
  public:
    // Define a public constructor with an Initialization list
    Person(std::string name) : name(name) {}
    // Define a public member variable 'name'
    std::string name;
};

int main() {
    Person alice("Alice");
    Person bob("Bob");
    assert(alice.name != bob.name);

    return 0;
}
