// Function should accept a vector of int as its argument
// and return the sum of all the int in the vector
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int AdditionFunction(vector<int> v) {
    int sum = 0;

    for (int i : v) {
        sum += i;
    }

    return sum;
}

int main() {
    vector<int> v = {1,2,3};

    cout << AdditionFunction(v) << endl;

    return 0;
}
