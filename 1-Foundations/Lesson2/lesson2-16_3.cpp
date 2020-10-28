// For loop with a Container 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main() {

    vector<int> a = {1,2,3,4,5};
    for (int i : a) {
        cout << i << endl;
    }

    return 0;
}
