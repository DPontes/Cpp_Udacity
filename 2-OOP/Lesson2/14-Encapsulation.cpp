/*
    Encapsulation
    Add a private member function that calculates the number of days in
    month, and use it to update the class invariants
*/

#include <cassert>
#include <iostream>

class Date {
  public:
    Date(int day, int month, int year);
    int Day() const { return day_; }
    void Day(int day);
    int Month() const { return month_; }
    void Month(int month);
    int Year() const { return year_; }
    void Year(int year);

  private:
    int DaysInAMonth(int month, int year) const;
    bool LeapYear(int year) const;
    int day_{1};
    int month_{1};
    int year_{0};
};

Date::Date(int day, int month, int year) {
    Year(year);
    Month(month);
    Day(day);
}

int Date::DaysInAMonth(int month, int year) const {
    if (month == 2) {
        return LeapYear(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

bool Date::LeapYear(int year) const {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

void Date::Day(int day) {
    if (day >= 1 && day <= DaysInAMonth(Month(), Year())) {
        day_ = day;
    }
}

void Date::Month(int month) {
    if (month >= 1 && month <= 12) {
        month_ = month;
    }
}

void Date::Year(int year) { year_ = year; }

int main() {

    // 2016 is a leap year
    Date date(29,2,2016);

    assert( date.Day()   == 29);
    assert( date.Month() == 2);
    assert( date.Year()  == 2016);

    // 2019 is not a leap year
    Date date2(29,2,2019);

    assert( date2.Day()   != 29);
    assert( date2.Month() == 2);
    assert( date2.Year()  == 2019);

    return 0;
}
