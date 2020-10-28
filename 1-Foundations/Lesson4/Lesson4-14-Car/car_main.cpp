#include <iostream>
#include <string>
#include "car.h"

using std::string;
using std::cout;
using std::endl;

int main() {
    // Create class instances for each car
    Car car1 = Car("green", 1);
    Car car2 = Car("red", 2);
    Car car3 = Car("blue", 3);

    // Increment Car 1 distance
    car1.IncrementDistance();

    // Print out the position of the cars
    car1.PrintCarData();
    car2.PrintCarData();
    car3.PrintCarData();

    return 0;
}
