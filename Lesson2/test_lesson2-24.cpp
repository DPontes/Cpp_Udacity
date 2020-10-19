void PrintVector(vector<int> v) {
    cout << "{ ";
    for (auto& item : v) {
        cout << item << " ";
    }
    cout << "}" << endl;
}

void TestParseLine() {
    cout << "---------------------------------------" << endl;
    cout << "TestParseLine: ";
    string line = "0,1,0,0,0,0,";
    vector<int> solution_vect{0,1,0,0,0,0};
    vector<int> test_vect;
    test_vect = ParseLine(line);
    if (test_vect != solution_vect) {
        cout << "failed" << endl;
        cout << endl << "Test input string: " << line << endl;
        cout << "Your parsed line: ";
        PrintVector(test_vect);
        cout << endl;
    } else {
        cout << "passed" << endl;
    }
    cout << "---------------------------------------" << endl;
    return;
}
