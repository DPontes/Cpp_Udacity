// The increment operator
#include <iostream>
using std::cout;
using std::endl;

int main() {
    auto i = 1;

    // Post-increment assigns i to c and then increments i
    auto c = i++;

    cout << "Post-increment example: " << endl;
    cout << "The value of c is: " << c << endl;
    cout << "The value of i is: " << i << endl;
    cout << endl;

    // Reset i to 1
    i = 1;

    // Pre-increment increments i, then assigns to c
    c = ++i;

    cout << "Pre-increment example: " << endl;
    cout << "The value of c is: " << c << endl;
    cout << "The value of i is: " << i << endl;
    cout << endl;

    // Decrement i
    i--;
    cout << "Decrement example: " << endl;
    cout << "The value of i is: " << i << endl;

    return 0;
}
