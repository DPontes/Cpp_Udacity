// References
#include <iostream>
using std::cout;
using std::endl;

int main() {
    int i = 1;

    // Declare a reference to i
    int& j = i;
    cout << "The value of j is: " << j << endl;

    // Change the value of i
    i = 5;
    cout << "The value of i is changed to: " << i << endl;
    cout << "The value of j is now: " << j << endl;

    // Change the value of the reference
    j = 7;
    cout << "The value of j is now: " << j << endl;
    cout << "The value of i is changed to: " << i << endl;

    return 0;
}
