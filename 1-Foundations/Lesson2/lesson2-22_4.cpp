/*
    String with mixed types
    Below, the number '3' in the string will not be printed.
    The expression will try to print an int followed by a char.
    Since there is no char after 3, the stream will fail.
*/

#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;
using std::endl;

int main() {
    string a = "1,2,3";
    istringstream my_stream(a);
    int n;
    char c;

    // Testing to see if the stream was successful and printing results
    while (my_stream >> n >> c) {
            cout << "That stream was successful: " << n << c << endl;
    }
    cout << "That stream was not sucessful!" << endl;

    return 0;
}
