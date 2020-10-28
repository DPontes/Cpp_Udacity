// 2D vector access
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main () {
	vector<vector<int>> b = {{1, 1, 2, 3},
				 {2, 1, 2, 3},
				 {3, 1, 5, 3}};
	cout << b[2][2] << endl;
	
	return 0;
}
