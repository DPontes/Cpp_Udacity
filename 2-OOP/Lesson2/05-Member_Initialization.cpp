/*
    Member initialization
    In order to ensure that objects of our structure always start with a valid
    state, we can initiate the members from within the structure definition
*/
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

struct Date {
    int day {1};
    int month{1};
    int year{2000};
};

int main() {
    Date date;

    // Test the initialization values
    assert(date.day = 1);
    assert(date.month = 1);
    assert(date.year = 2000);

    cout << "Date: " << date.day << "/" << date.month << "/" << date.year << endl;

    return 0;
}
