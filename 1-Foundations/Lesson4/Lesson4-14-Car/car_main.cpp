// Generates 100 cars with different colors, move each
// and print data about each
#include <iostream>
#include <string>
#include <vector>
#include "car.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main() {
    // Create and empty vector of pointers to Cars
    // and a null pointer to a car
    vector<Car*> carVect;
    Car* cp = nullptr;

    // The vector of colors for the cars
    vector<string> colors {"red","blue","green"};

    // Create 100 cars with different colors and
    // push pointers to each of those cars in the vector
    for (int i = 0; i < 100; i++) {
        cp = new Car(colors[i%3], i+1);
        carVect.push_back(cp);
    }

    // Move each car forward by 1
    for (Car* cp : carVect) {
        cp -> IncrementDistance();
    }

    // Print data about each car
    for (Car* cp : carVect) {
        cp -> PrintCarData();
    }

    return 0;
}
