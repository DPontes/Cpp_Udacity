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
