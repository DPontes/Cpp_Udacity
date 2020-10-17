// Functions
#include <iostream>
using std::cout;
using std::endl;

// Function declared and defined here
int AdditionFunction(int i, int j) {
    return i + j;
}

int main() {
    auto d = 3;
    auto f = 7;

    cout << AdditionFunction(d, f) << endl;

    return 0;
}
