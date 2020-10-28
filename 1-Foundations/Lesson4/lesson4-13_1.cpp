// COding with Objects
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

        // Class/object attributes
        string color;
        int distance = 0;
        int number;
};

int main() {
    // Create car instances for each car
    Car car1, car2, car3;

    // Set each intance's color
    car1.color = "blue";
    car2.color = "green";
    car3.color = "red";

    // Set each instance's number
    car1.number = 1;
    car2.number = 2;
    car3.number = 3;

    // Increment car1 position by 1
    car1.IncrementDistance();

    // Printout position and color of each car
    car1.PrintCarData();
    car2.PrintCarData();
    car3.PrintCarData();

    return 0;
}
