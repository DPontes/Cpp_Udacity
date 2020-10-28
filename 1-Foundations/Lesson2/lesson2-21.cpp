// Write a function 'void ReadBoardFile' which reads lines from a file.
// Write each line to cout, followed by a newline

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

void ReadBoardFile(string pathToFile) {
   ifstream my_file;
   my_file.open(pathToFile);

   if(my_file) {
        cout << "File has been accessed" << endl;
        string line;

        while (getline(my_file, line)) {
            cout << line << endl;
        }
   }
}

int main() {

    string path = "files/1.board";

    ReadBoardFile(path);

    return 0;
}
