/*
    Write a 'vector<int> ParseLine' function which accepts a string as an
    argument. User 'std::istringstream' to parse the line by comma 'char'
    and store int 'int's in a 'vector<int>'. 'ParseLine' should return
    the vector after parsing
*/
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::istringstream;

vector<int> ParseLine(string line) {
    istringstream this_stream(line);
    vector<int> lineVector;
    int value;
    char comma;

    while (this_stream >> value >> comma && comma == ",") {
        lineVector.push_back(value);
    }
    return lineVector;
}

void ReadBoardFile(string path) {
    ifstream myfile (path);

    if(myfile) {
        string line;
        while(getline(myfile, line)) {
            cout << line << endl;
        }
    }
}

void PrintBoard(const vector<vector<int>> board) {
        for (auto& line : board) {
            for (auto& item : line) {
                cout << item;
            }
            cout << endl;
        }
}

#include "test_lesson2-24.cpp"

int main() {
    ReadBoardFile("files/1.board");
    TestParseLine();
    // PrintBoard(board);
    return 0;
}
