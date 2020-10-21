// Starting A* search
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
using std::abs;

enum class State {kEmpty, kObstacle};

vector<State> ParseLine(string line) {
    istringstream sline(line);
    vector<State> row;
    int item;
    char comma;

    while(sline >> item >> comma && comma ==',') {
        if (item == 0) {
            row.push_back(State::kEmpty);
        } else {
            row.push_back(State::kObstacle);
        }
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path) {
    ifstream myfile (path);
    vector<vector<State>> board;
    if (myfile) {
        string line;
        while (getline(myfile, line)) {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

vector<vector<State>> Search(vector<vector<State>> board,
                             int init[2],
                             int goal[2]) {

    cout << "No Path found!" << endl;
    return vector<vector<State>> ();
}

string CellString(State cell) {
    switch(cell) {
        case State::kObstacle: return "⛰️  ";
        default: return "0  ";
    }
}

void PrintBoard(const vector<vector<State>> board) {
    for (auto& line : board) {
        for (auto& item: line) {
            cout << CellString(item);
        }
        cout << endl;
    }
}

int main() {
    int init[2] {0,0};
    int goal[2] {4,5};
    auto board = ReadBoardFile("files/1.board");
    auto solution = Search(board, init, goal);
    PrintBoard(solution);

    return 0;
}
