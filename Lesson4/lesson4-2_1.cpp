// The contents  of the lesson4-2_1.h are included in
// the corresponding .cpp file using quotes
#include "lesson4-2_1.h"
#include <iostream>

using std::cout;
using std::endl;

void OuterFunction(int i) {
    InnerFunction(i);

    return;
}

void InnerFunction(int i) {
    cout << "The value of the integer is: " << i << endl;

    return;
}

int main() {
    int a = 5;
    OuterFunction(a);

    return 0;
}
