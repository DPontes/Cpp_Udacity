#include <iostream>
#include <vector>
#include "lesson4-increment_and_sum.h"
using std::vector;
using std::cout;
using std::endl;

int main() {
    vector<int> v {1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << endl;

    return 0;
}
