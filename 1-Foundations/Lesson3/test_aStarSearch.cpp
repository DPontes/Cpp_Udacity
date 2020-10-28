void PrintVector(vector<int> v) {
    cout << "{ ";
    for (auto item : v) {
        cout << item << " ";
    }
    cout << "}" << endl;
}

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
    cout << "--------------------------------------" << endl;
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
    cout << "--------------------------------------" << endl;
}

void TestAddToTopen() {
    cout << "--------------------------------------" << endl;
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
    cout << "--------------------------------------" << endl;

    return;
}

void TestCompare() {
    cout << "--------------------------------------" << endl;
    cout << "Compare Function Test: ";
    vector<int> test_1 {1,2,5,6};
    vector<int> test_2 {1,2,5,7};
    vector<int> test_3 {1,2,5,8};
    vector<int> test_4 {1,3,5,7};

    if (Compare(test_1, test_2)) {
        cout << "failed" << endl;
        cout << endl << "a = ";
        PrintVector(test_1);
        cout << "b = ";
        PrintVector(test_2);
        cout << "Compare(a, b): " << Compare(test_1, test_2) << endl;
        cout << "Correct answer: 0" << endl;
        cout << endl;
    } else if (!Compare(test_3, test_4)) {
        cout << "failed" << endl;
        cout << endl << "a = ";
        PrintVector(test_3);
        cout << "b = ";
        PrintVector(test_4);
        cout << "Compare(a, b): " << Compare(test_3, test_4) << endl;
        cout << "Correct answer: 1" << endl;
        cout << endl;
    } else {
        cout << "Passed" << endl;
    }
    cout << "--------------------------------------" << endl;
}

void TestSearch() {
    cout << "--------------------------------------" << endl;
    cout << "Search Function Test: ";
    int init[2] {0, 0};
    int goal[2] {4, 5};
    auto board = ReadBoardFile("files/1.board");

    std::cout.setstate(std::ios_base::failbit);  // Disable cout
    auto output = Search(board, init, goal);
    std::cout.clear();                           // Enable cout

    vector<vector<State>> solution{{State::kStart, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                   {State::kPath, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                   {State::kPath, State::kObstacle, State::kEmpty, State::kClosed, State::kClosed, State::kClosed},
                                   {State::kPath, State::kObstacle, State::kClosed, State::kPath, State::kPath, State::kPath},
                                   {State::kPath, State::kPath, State::kPath, State::kPath, State::kObstacle, State::kFinish}};

    if (output != solution) {
        cout << "failed" << endl;
        cout << "Search(board, {0,0}, {4,5}" << endl;
        cout << "Solution board: " << endl;
        PrintVectorOFVectors(solution);
        cout << "Your board: " << endl;
        PrintVectorOFVectors(output);
        cout << endl;
    } else {
        cout << "Passed" << endl;
    }
    cout << "--------------------------------------" << endl;
}

void TestCheckValidCell() {
    cout << "--------------------------------------" << endl;
    cout << "CheckValidCell Function Test: ";

    vector<vector<State>> board{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}
                               };

    if (CheckValidCell(0, 0, board)) {
        cout << "failed" << endl;
        cout << endl << "Test board is: " << endl;
        PrintVectorOFVectors(board);
        cout << "Cell checked {0, 0}" << endl;
        cout << endl;
    } else if (CheckValidCell(4, 1, board)) {
        cout << "failed" << endl;
        cout << endl << "Test board is: " << endl;
        PrintVectorOFVectors(board);
        cout << "Cell checked {4, 1}" << endl;
        cout << endl;
    } else {
        cout << "Passed" << endl;
    }

   cout << "--------------------------------------" << endl;
}

void TestExpandNeighbors() {
    cout << "--------------------------------------" << endl;
    cout << "ExpandNeighbors Function Test: ";
    vector<int> current{4, 2, 7, 3};
    int goal[2] {4, 5};
    vector<vector<int>> open{{4,2,7,3}};
    vector<vector<int>>solution_open = open;
    solution_open.push_back(vector<int> {3,2,8,4});
    solution_open.push_back(vector<int> {4,3,8,2});
    vector<vector<State>> board{{State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kObstacle, State::kEmpty, State::kEmpty, State::kEmpty, State::kEmpty},
                                {State::kClosed, State::kClosed, State::kEmpty, State::kEmpty, State::kObstacle, State::kEmpty}
                               };
    vector<vector<State>> solution_board = board;

    solution_board[3][2] = State::kClosed;
    solution_board[4][3] = State::kClosed;
    ExpandNeighbors(current, goal, open, board);
    CellSort(&open);
    CellSort(&solution_open);

    if (open != solution_open) {
        cout << "failed" << endl;
        cout << endl;
        cout << "Your open list is: " << endl;
        PrintVectorOFVectors(open);
        cout << "Solution open list is: " << endl;
        PrintVectorOFVectors(solution_open);
        cout << endl;
    } else if (board != solution_board) {
        cout << "failed" << endl;
        cout << endl;
        cout << "Your open board is: " << endl;
        PrintVectorOFVectors(board);
        cout << "Solution open board is: " << endl;
        PrintVectorOFVectors(solution_board);
        cout << endl;
    } else {
        cout << "Passed" << endl;
    }
    cout << "--------------------------------------" << endl;
    return;
}
