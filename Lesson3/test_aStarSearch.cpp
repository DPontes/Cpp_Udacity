void PrintVectorOFVectors(vector<vector<int>> v) {
    for (auto row : v) {
        cout << "{";
        for (auto col : row) {
            cout << col << " ";
        }
        cout << "}" << endl;
    }
}

void PrintVectorOFVectors(vector<vector<State>> v) {
    for (auto row : v) {
        cout << "{";
        for (auto col : row) {
            cout << CellString(col) << " ";
        }
        cout << "}" << endl;
    }
}

void TestHeuristics() {
    cout << "--------------------------------" << endl;
    cout << "Heuristic Function Test: ";
    if (Heuristic(1,2,3,4) != 4) {
        cout << "failed" << endl;
        cout << endl << "Heuristic(1,2,3,4) = " << Heuristic(1,2,3,4) << endl;
        cout << "Correct result: 4" << endl;
        cout << endl;
    } else if (Heuristic(2, -1, 4, -7) != 8) {
        cout << "failed" << endl;
        cout << endl << "Heuristic(2, -1, 4, -7) = " << Heuristic(1,2,3,4) << endl;
        cout << "Correct result: 8" << endl;
        cout << endl;
    } else {
        cout << "Passed" << endl;
    }
    cout << "--------------------------------" << endl;
}

void TestAddToTopen() {
    cout << "--------------------------------" << endl;
    cout << "AddToOpen Function Test: ";
    int x = 3;
    int y = 0;
    int g = 5;
    int h = 7;
    vector<vector<int>> open{ {0,0,2,9},
                              {1,0,2,2},
                              {2,0,2,4}};
    vector<vector<int>> solution_open = open;
    solution_open.push_back(vector<int> {3,0,5,7});

    vector<vector<State>> grid {{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kEmpty, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}};
    vector<vector<State>> solution_grid = grid;

    solution_grid[3][0] = State::kClosed;

    AddToOpen(x,y,g,h,open,grid);
    if ( open != solution_open) {
        cout << "failed" << endl;
        cout << endl;
        cout << "Your open list is: " << endl;
        PrintVectorOFVectors(open);
        cout << "Solution open list is: " << endl;
        PrintVectorOFVectors(solution_open);
        cout << endl;
    } else if (grid != solution_grid) {
        cout << "failed" << endl;
        cout << endl;
        cout << "Your grid is: " << endl;
        PrintVectorOFVectors(grid);
        cout << endl;
        cout << "Solution grid is: " << endl;
        PrintVectorOFVectors(solution_grid);
        cout << endl;
    } else {
        cout << "Passed" << endl;
    }
    cout << "--------------------------------" << endl;

    return;
}
