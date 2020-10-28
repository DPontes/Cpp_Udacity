// Vector push_back
#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main() {
    vector v {1,2,3};       // WARN: this type of declaration requires c++17

    // Print the contents of the vector
    for (auto& i : v){
        cout << i << endl;
    }

    // Push 4 to the back of the vector
    v.push_back(4);

    // Print the contents again
    for (auto& i :v) {
        cout << i << endl;
    }

    return 0;
}
