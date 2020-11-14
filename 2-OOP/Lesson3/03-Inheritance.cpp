#include <iostream>
#include <string>
using std::string;

class Vehicle {
  public:
    int wheels = 0;
    string color = "blue";
    string make  = "generic";

    void Print() const {
        std::cout << "This " << color << " " << make << " has " << wheels << " wheels." << std::endl;
    }
};

class Car : public Vehicle {
  public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
  public:
    bool kickstand = true;
};

class Scooter : public Vehicle {
  public:
    bool electric = true;
};

int main() {
    Car car;
    car.wheels = 4;
    car.sunroof = true;
    car.Print();
    if(car.sunroof) {
        std::cout << "And a sunroof!" << std::endl;
    }

    Scooter scooter;
    scooter.wheels = 2;
    scooter.Print();
}
