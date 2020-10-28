// Storing a Memory Address (int type)
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

    return 0;
}
