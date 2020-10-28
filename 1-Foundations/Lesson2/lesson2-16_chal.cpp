// Challenge: write a double range-based for loop that
// prints all of the entries of the 2D vector b
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

int main () {
    vector<vector<int>> b = {{1,2},
                             {3,4},
                             {5,6}};

    for (auto& v : b) {
        for (auto& j : v) {
            cout << j << " ";
        }
    cout << endl;
    }

    return 0;
}
