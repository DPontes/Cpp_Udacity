// Vector Containers - Practice
// Declare a vector<int> and assign the value {6, 7, 8}

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main() {
	vector<int> v{6,7,8};
	for (auto& i : v) {
		cout << i << " ";
	}
	cout << endl;
	cout << "Nice, a vector was created" << endl;

	return 0;
}
