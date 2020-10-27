// Pointers to Other Object Types
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> v {1,2,3,4};

    vector<int>* vectorAddr = &v;

    for (int a : v) {
        cout << a << " ";
    }
    cout << endl;

    cout << "Index 0 of v with dereferenced pointer: " << (*vectorAddr)[0] << endl;

    return 0;
}
