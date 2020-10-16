// 1D vector accesswith a auto for-loop
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main () {
	vector<int> a = {0,1,2,3,4};
	
	for (auto& i : a)
		cout << i << " ";
	cout << endl;

	return 0;
}
