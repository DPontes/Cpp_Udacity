// Print the board
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void PrintBoard(vector<vector<int>> board) {
    for (auto& line : board) {
        for (int i : line) {
            cout << i;
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board = {{0,1,0,0,0,0},
                                 {0,1,0,0,0,0},
                                 {0,1,0,0,0,0},
                                 {0,1,0,0,0,0},
                                 {0,0,0,0,1,0}};

    PrintBoard(board);
    return 0;
}
