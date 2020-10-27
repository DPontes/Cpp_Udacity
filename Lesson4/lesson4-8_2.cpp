// PAssing pointers to a function
#include <iostream>
using std::cout;
using std::endl;

void AddOne(int* j) {
    // Dereference the pointer and increment the int being pointed to
    (*j)++;
}

int main() {
    int i = 1;
    cout << "The value of i is: " << i << endl;

    // Declare a pointer to i
    int* p_i = &i;

    AddOne(p_i);
    cout << "The new value of i is: " << i << endl;

    return 0;
}
