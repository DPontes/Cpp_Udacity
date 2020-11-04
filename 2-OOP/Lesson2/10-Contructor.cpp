// Creating a class
#include <iostream>
#include <cassert>

class Date {
  public:
   Date(int d, int m, int y) {
       Day(d);
       Month(m);
       Year(y);
   }
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
    Date date {29,8,1981};

    assert(date.Day() == 29);
    assert(date.Month() == 8);
    assert(date.Year() == 1981);

    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year();

    return 0;
}
