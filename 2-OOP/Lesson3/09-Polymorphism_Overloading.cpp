/*
    - Create a function hello() that outputs, "Hello, World!"
    - Create a class Human.
    - Overload hello() by creating a function hello(Human human). This function should output, "Hello, Human!"
    - Create 2 more classes and use those classes to further overload the hello() function.
*/
#include <iostream>

class Human {};
class Dog {};
class Cat {};

void hello() { std::cout << "Hello, world" << std::endl; }
void hello(Human human) { std::cout << "Hello, human" << std::endl; }
void hello(Cat cat) { std::cout << "Miau" << std::endl; }
void hello(Dog dog) { std::cout << "Bark" << std::endl; }

int main() {
    hello();

    hello(Human());
    hello(Cat());
    hello(Dog());
}
