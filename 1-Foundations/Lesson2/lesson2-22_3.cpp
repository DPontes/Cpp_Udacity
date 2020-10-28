/*
    The extraction operator >> writes the stream to the variable on the right
    of the operator and returns the istringstream object, so the entire
    expression 'my_stream >> n' is an istringstream object and can be used as
    a boolean
*/

#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;
using std::endl;

int main() {
    string a = "1 2 3";
    istringstream my_stream(a);
    int n;

    // Testing to see if the stream was successful and printing results
    while (my_stream >> n) {
            cout << "That stream was successful: " << n << endl;
    }
    cout << "That stream was not sucessful!" << endl;

    return 0;
}
