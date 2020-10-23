// Starting A* search
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::sort;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::abs;

enum class State {kEmpty, kObstacle, kClosed, kPath};

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

int Heuristic(int coordX1, int coordY1, int coordX2, int coordY2) {
    return abs(coordX2 - coordX1) + abs(coordY2 - coordY1);
}

void AddToOpen(int x,
               int y,
               int g,
               int h,
               vector<vector<int>> &openNode,
               vector<vector<State>> &grid) {

    openNode.push_back(vector<int> {x, y, g, h});
    grid[x][y] = State::kClosed;
}

bool Compare(vector<int> node1, vector<int> node2) {
    int node1_g = node1[2];
    int node1_h = node1[3];
    int node2_g = node2[2];
    int node2_h = node2[3];

    int node1_fValue = node1_g + node1_h;
    int node2_fValue = node2_g + node2_h;

    return node1_fValue > node2_fValue;
}

void CellSort(vector<vector<int>> *v) {
    sort(v->begin(), v->end(), Compare);
}

vector<vector<State>> Search(vector<vector<State>> board,
                             int init[2],
                             int goal[2]) {

    vector<vector<int>> open{};
    int current_x = init[0];
    int current_y = init[1];
    int goal_x = goal[0];
    int goal_y = goal[1];
    int g = 0;
    int h = Heuristic(current_x, current_y, goal_x, goal_y);

    AddToOpen(current_x, current_y, g, h, open, board);

    while(open.size() > 0) {
        CellSort(&open);
        auto currentNode = open.back();
        open.pop_back();
        current_x = currentNode[0];
        current_y = currentNode[1];
        board[current_x][current_y] = State::kPath;

        // Check if we've reached the goal
        if (current_x == goal_x && current_y == goal_y) {
            return board;
        }
    }

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

#include "test_aStarSearch.cpp"

int main() {
    int init[2] {0,0};
    int goal[2] {4,5};
    auto board = ReadBoardFile("files/1.board");
    auto solution = Search(board, init, goal);
    PrintBoard(solution);

    // For testing
    TestHeuristics();
    TestAddToTopen();
    TestCompare();
    TestSearch();
    return 0;
}
