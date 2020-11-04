// Scope Resolution
#include <iostream>
#include <cassert>

class Date {
  public:
   Date(int d, int m, int y) {
       Day(d);
       Month(m);
       Year(y);
   }
    int Day() const { return day; }
    void Day(int dday);
    int Month() const { return month; }
    void Month(int month);
    int Year() const { return year; }
    void Year(int year);

  private:
    int day {1};
    int month {1};
    int year {0};
};

void Date::Day(int day) { if( day > 0 && day <= 31) Date::day = day; }
void Date::Month(int month) { if( month > 0 && month <= 12) Date::month = month; }
void Date::Year(int year) { Date::year = year; }

int main() {
    Date date {29,8,1981};

    assert(date.Day() == 29);
    assert(date.Month() == 8);
    assert(date.Year() == 1981);

    std::cout << date.Day() << "/" << date.Month() << "/" << date.Year();

    return 0;
}
