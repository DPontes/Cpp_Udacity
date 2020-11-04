// Creating a class
#include <iostream>
#include <cassert>

class Date {
  public:
    int Day() { return day; }
    void Day(int d) { if (d > 0 && d <= 31) day = d; }
    int Month() { return month; }
    void Month(int m) { if(m > 0 && m <= 12) month = m; }
    int Year() { return year; }
    void Year(int y) { year = y; }

  private:
    int day {1};
    int month {1};
    int year {0};
};

int main() {
    Date date;
    date.Day(-1);       // The invariances defined in the class above prevents
    date.Month(14);     // these value from being attributed to the variables
    date.Year(2000);

    assert(date.Day() != -1);
    assert(date.Month() != 14);
    assert(date.Year() == 2000);

    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year();

    return 0;
}
