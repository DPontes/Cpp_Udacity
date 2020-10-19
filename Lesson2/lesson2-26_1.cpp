// Enums
#include <iostream>

using std::cout;
using std::endl;

int main() {
    // Create the enum Color with fixed values
    enum class Color {white, black, blue, red};

    // Create a Color variable and set it to Collor::blue
    Color my_color = Color::blue;

    // Test to see if my car is red
    if (my_color == Color::red) {
        cout << "The color of my car is red" << endl;
    } else {
        cout << "The color of my car is not red" << endl;
    }

    return 0;
}
