//Header files Practice
#include "lesson4-2_prac.h"
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void AddOneToEach (vector<int> &v) {
    /*
        Note that the function passes a reference to v
        and the for loop below uses references to
        each item in v. This means that the actual ints
        that v holds will be actually incremented
    */
    for (auto& i : v) {
        i++;
    }
    return;
}

int IncrementAndConputeVectorSum(vector<int> v) {
    int total = 0;
    AddOneToEach(v);

    for (auto i : v) {
        total += i;
    }
    return total;
}

int main () {
    vector<int> v {1,2,3,4};
    int total = IncrementAndConputeVectorSum(v);

    cout << "The total is: " << total << endl;
    return 0;
}
