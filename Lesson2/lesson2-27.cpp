/*
    Write a function CellString which accepts a state as input and returns
    the following string:
    - "⛰️  " if the input equals "kObstacle"
    - "0  " otherwise
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

enum class State {kEmpty, kObstacle};

vector<int> ParseLine (string line) {
    istringstream sline(line);
    int item;
    char comma;
    vector<int> row;

    while (sline >> item >> comma && comma == ',') {
        row.push_back(item);
    }
    return row;
}

vector<vector<int>> ReadBoardFile(string path) {
    ifstream myfile(path);
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

string CellString(State state) {
    switch(state) {
        case State::kObstacle : return "⛰  ";
        default: return "0  ";
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

int main() {
    auto board = ReadBoardFile("files/1.board");
    PrintBoard(board);

    return 0;
}
