// Practice
// Make it so that the DoubleString function accepts a reference
// so that it is passed variable can directly modified by the function
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void DoubleString(string &value) {
    // Concatenate the string with a space and itself
    value = value + " " + value;
}

int main() {
    string s = "Hello";
    cout << "The string is: " << s << endl;
    DoubleString(s);
    cout << "The string now is: " << s << endl;

    return 0;
}
