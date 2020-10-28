// Reading data from stream
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::ifstream;

int main() {
    ifstream my_file;
    my_file.open("files/1.board");

    if (my_file) {
        cout << "The file stream ha been created" << endl;

        string line;
        while (getline(my_file, line)) {
            cout << line << endl;
        }
    }
    return 0;
}
