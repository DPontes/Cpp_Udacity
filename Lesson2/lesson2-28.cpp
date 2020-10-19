/*
    Update the program to store a board of State variables. The board should
    print:
    0   ⛰️   0   0   0   0
    0   ⛰️   0   0   0   0
    0   ⛰️   0   0   0   0
    0   ⛰️   0   0   0   0
    0   0   0   0   ⛰️   0
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

vector<State> ParseLine (string line) {
    istringstream sline(line);
    int item;
    char comma;
    vector<State> row;

    while (sline >> item >> comma && comma == ',') {
        if( item == 0) {
            row.push_back(State::kEmpty);
        } else {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
    ifstream myfile(path);
    vector<vector<State>> board;

    if(myfile) {
        string line;
        while(getline(myfile, line)) {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

string CellString(State cell) {
    switch(cell) {
        case State::kObstacle : return "⛰  ";
        default: return "0  ";
    }
}

void PrintBoard(const vector<vector<State>> board) {
    for (auto& line : board) {
        for (auto& item : line) {
            cout << CellString(item);
        }
        cout << endl;
    }
}

int main() {
    auto board = ReadBoardFile("files/1.board");
    PrintBoard(board);

    return 0;
}
