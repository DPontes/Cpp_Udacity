/*
    - Declare Vehicle as the base class
    - Derive Car from Vehicle
    - Derive Sedan from Car
    - Update main to pass the tests
*/
#include <cassert>

class Vehicle {};

class Car : public Vehicle {
  public:
    int wheels {4};
};

class Sedan : public Car {
  public:
    int seats {4};
    bool trunk {true};
};

int main() {

    Sedan sedan;

    assert( sedan.trunk == true );
    assert( sedan.seats == 4 );
    assert( sedan.wheels == 4 );
}
