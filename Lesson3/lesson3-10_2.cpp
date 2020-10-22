// Passing references
#include <iostream>
using std::cout;
using std::endl;

int MultiplyByTwo(int &i) { // only difference towards lesson3-10_1 is the '&'
    i = 2*i;
    return i;
}

int main() {
    int a = 5;
    cout << "The int a equals: " << a << endl;
    int b = MultiplyByTwo(a);
    cout << "The int b equals: " << b << endl;
    cout << "The int a now equals: " << a << endl;

    return 0;
}
