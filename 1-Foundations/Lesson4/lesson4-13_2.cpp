// Adding a Constructor
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// The Car class
class Car {
    public:
        // Method to print data
        void PrintCarData() {
            cout << "The distance that the " << color << " car " << number
                 << " has travelled " << distance << endl;
        }

        // Method to increment the distance travelled
        void IncrementDistance() {
            distance++;
        }

        // Adding a constructor here
        Car(string c, int n) {
            // Setting the class attributes with the
            // values passed into the constructor
            color = c;
            number = n;
        }

        // Class/object attributes
        string color;
        int distance = 0;
        int number;
};

int main() {
    // Create car instances for each car
    Car car1 = Car("blue", 1);
    Car car2 = Car("green", 2);
    Car car3 = Car("red", 3);

    // Increment car1 position by 1
    car1.IncrementDistance();

    // Printout position and color of each car
    car1.PrintCarData();
    car2.PrintCarData();
    car3.PrintCarData();

    return 0;
}
