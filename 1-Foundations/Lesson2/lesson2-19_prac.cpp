// Write a while loop to iterate over the integers from 1 to 10
// If the integer is even, print it out

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int i = 0;
    while (i <= 10) {
        if (i % 2 == 0) {
            cout << i << endl;
        }
        i++;
    }
    return 0;
}
