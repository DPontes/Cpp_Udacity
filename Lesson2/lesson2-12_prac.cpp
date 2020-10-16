// Using Auto - Practice
// Initialize a vector v with values {7,8,9,10} using auto
#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;

int main() {

	auto v_me = {7,8,9,10};
	
	for (auto& i : v_me) {
		cout << i << " ";		
	}
	cout << endl;
	cout << "Sucess" << endl;

	return 0;
}
