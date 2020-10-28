// Primitive variable Types

#include <iostream>
#include <string>

using std::cout;	// not completly sure this is a good idea

int main() {
	// Declaring and initializing an int variable
	int a = 9;

	// Declaring a string varaible without initializing it right away
	std::string b;

	// Initializing the string b
	b = "Here is a string";

	cout << a << std::endl;		// using std::endl instead of the suggested "\n"
	cout << b << std::endl;

	return 0;	// Adding a return seems like a good idea, given that it has a return type
}
