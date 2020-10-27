// Returning a pointer from a function
#include <iostream>
using std::cout;
using std::endl;

int* AddOne(int& j) {
    // Increment the referenced int and
    // return the address of j
    j++;
    return &j;
}

int main() {
    int i = 1;

    cout << "The value of i is: " << i << endl;

    // Declare a pointer and initialize it to the
    // value returned by AddOne
    int* j_value = AddOne(i);
    cout << "The value of i is now: " << i << endl;
    cout << "The value of the int pointed at by j_value is: " << *j_value << endl;

    return 0;
}
