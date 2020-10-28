#include <iostream>
#include "car.h"

// Method definitions for the Car class
void Car::PrintCarData() {
    cout << "The distance that the " << color << " car "
         << number << " has travelled is: " << distance << endl;
}

void Car::IncrementDistance() {
    distance++;
}
