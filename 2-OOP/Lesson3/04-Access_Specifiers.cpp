/*
    Update the derived classes so that one has proteced inheritance
    and one has private inheritance
*/
#include <iostream>
#include <string>
using std::string;

class Vehicle {
  public:
    int wheels = 0;
    string color = "blue";

    void Print() const{
        std::cout << "This " << color << " vehicle has " << wheels << " wheels." << std::endl;
    }
};

class Car : public Vehicle {
  public:
    bool sunroof = true;
};

class Bicycle : protected Vehicle {
  public:
    bool kickstand = true;

    void PrintBike() const {
        Print();
    }
};

class Scooter : private Vehicle {
  public:
    bool electric = false;
    void PrintScooter() const {
        Print();
    }
};

int main () {
    Car car;
    Bicycle bicycle;
    Scooter scooter;

    //bicycle.Print();      // Not possible to Access a protected member
    //scooter.Print();      // Not possible to access a private member
    bicycle.PrintBike();    // Access a member of the base class ( Print() ) from within the derived class with protected inheritance
    scooter.PrintScooter(); // Access a member of the base class ( Print() ) from within the derived class with private inheritance
}
