// Void return type
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;

void PrintStrings(string s1, string s2) {
    cout << s1 +s2 << endl;
}

int main() {
    string s1 = "C++ is ";
    string s2 = "super awesome";

    PrintStrings(s1, s2);

    return 0;
}
