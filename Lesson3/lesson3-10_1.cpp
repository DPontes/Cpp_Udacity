// Passing values
#include <iostream>
using std::cout;
using std::endl;

int MultiplyByTwo(int i) {
    i = 2*i;
    return i;
}

int main() {
    int a = 5;
    cout << "The int a equals: " << a << endl;
    int b = MultiplyByTwo(a);
    cout << "The int b equals: " << b << endl;
    cout << "The int a still equals: " << a << endl;

    return 0;
}
