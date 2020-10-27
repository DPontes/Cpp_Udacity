// Getting an Object back from a Pointer Address
#include <iostream>
using std::cout;
using std::endl;

int main() {
    int i = 5;

    // A pointer pointer_to_i is declared and initialized to the address of i
    int* pointer_to_i = &i;

    // Print the memory addresses of i and pointer_to_i
    cout << "The address of i is:          " << &i << endl;
    cout << "The variable pointer_to_i is: " << pointer_to_i << endl;

    // The value of i changed
    i = 7;
    cout << "The new value of i is: " << i << endl;
    cout << "The value of the variable pointed to by pointer_to_i is: " << *pointer_to_i << endl;
    cout << "The address of i is still: " << &i << endl;

    return 0;
}
