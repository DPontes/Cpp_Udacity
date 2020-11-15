/* Exercise

    - Define a class Animal.
    - Define 3 member variables: color, name, age.
    - Define a derived class Snake that inherits from the base class Animal.
    - Create a member variable length for the Snake class.
    - Create a derived class Cat that inherits from the base class Animal.
    - Create a member variable height for the Cat class.
    - Create MakeSound() member functions for each of the derived classes.
    - In the main() function instantiate Snake and Cat objects. Initialize both their unique and derived attributes. Program them to make a sound.

*/
#include <iostream>
#include <string>

using std::string;

class Animal {
  public:
    string color;
    string name;
    int age;
};

class Snake : public Animal {
  public:
    int length;
    void MakeSound() const {
        std::cout << "Tss-sss-sss" << std::endl;
    }
};

class Cat : public Animal {
  public:
    int height;
    void MakeSound() const {
        std::cout << "Le mao" << std::endl;
    }
};

int main() {
    Snake snake;
    Cat cat;

    cat.color = "black";
    cat.name = "Snuffles";
    cat.age = 5;

    snake.color = "Green/Grey";
    snake.name = "Black mamba";
    snake.age = 14;

    cat.height = 3;
    snake.length = 10;

    cat.MakeSound();
    snake.MakeSound();
}
