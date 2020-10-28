// 2D vector access
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main () {
	vector<vector<int>> b = {{0,1,2,3,4},
				 {1,1,2,3,4},
				 {2,1,2,3,4}};
	
	// Print the length of an inner vector of b
	cout << b[0].size() << endl;
	
	return 0;
}
