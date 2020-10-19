/*
    Update ReadBoardFile to use ParseLine and return
    the board as a vector<vector<int>>.
    Update the main function to pass the results of
    ReadBoardFile to the PrintBoard function.
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

    while (this_stream >> value >> comma && comma == ',') {
        lineVector.push_back(value);
    }
    return lineVector;
}

vector<vector<int>> ReadBoardFile(string path) {
    ifstream myfile (path);
    vector<vector<int>> board;

    if(myfile) {
        string line;
        while(getline(myfile, line)) {
            vector<int> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

void PrintBoard(const vector<vector<int>> board) {
    for (auto& line : board) {
        for (auto& item : line) {
            cout << item;
        }
        cout << endl;
    }
}

int main() {
    auto board = ReadBoardFile("files/1.board");
    PrintBoard(board);
    return 0;
}
