#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date {
public:
  struct BadDate {
    int _day, _month, _year;
    BadDate(int d, int m, int y) : _day(d), _month(m), _year(y) {};
  };

  enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

  Date(int d = 0, Month m = Month(0), int y = 0) {
    if (d == 0 && static_cast<int>(m) == 0 && y == 0) {
      *this = defaultDate;
    } else {
      fillDate(d, m, y);
    }
  }

  Date(int d, int m, int y) : Date(d, Month(m), y) {}

  Date(const Date& other) : _day(other._day), _month(other._month), _year(other._year) {}

  Date& operator=(const Date& other) {
    if (this != &other) {
      _day = other._day;
      _month = other._month;
      _year = other._year;
    }
    return *this;
  }

  ~Date() {}

  static void setDefault(int d, Month m, int y) {
    defaultDate.fillDate(d, m, y);
    defaultSet = true;
  }

  static void setDefault() {
    if (!defaultSet) {
      defaultDate.fillDate(1, jan, 1970);
      defaultSet = true;
    }
  }

  static void showDefault() {
    cout << "Default date: " << defaultDate << endl;
  }

  int day() const { return _day; }
  Month month() const { return static_cast<Month>(_month); }
  int year() const { return _year; }

  const string getMonthName() const { return monthNames[_month - 1]; }

  Month setMonth() const { return static_cast<Month>(_month); }

  void setDay(int d) { fillDate(d, static_cast<Month>(_month), _year); }

  void setDYear(int y) { fillDate(_day, static_cast<Month>(_month), y); }
  Date& operator+=(int);
  Date& operator-=(int);
  const Date operator++();
  const Date& operator++(int);
  const Date operator--();
  const Date& operator--(int);

private:
  int _day, _month, _year;

  void fillDate(int d, Month m, int y) {
    if (d < 1 || d > 31 || m < 1 || m > 12 || y < 0) {
      throw BadDate(d, m, y);
    }
    _day = d;
    _month = m;
    _year = y;
  }

  friend ostream &operator<<(ostream &os, const Date &d) {
    os << d._day << "-" << d.getMonthName() << "-" << d._year;
    return os;
  }

  friend ostream& operator<<(ostream& os, const BadDate& bd) {
    os << "Bad date: (" << bd._day << ", " << bd._month << ", " << bd._year << ")";
    return os;
  }

  static string monthNames[12];
  static bool defaultSet;
  static Date defaultDate;
};

int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leapYear(int y) {
  if (y % 4 != 0) {
    return false;
  } else if (y % 100 != 0) {
    return true;
  } else if (y % 400 != 0) {
    return false;
  } else {
    return true;
  }
}

string Date::monthNames[12] = {"January", "February", "March", "April", "May", "June",
                               "July", "August", "September", "October", "November", "December"};

bool Date::defaultSet = false;
Date Date::defaultDate;

Date& Date::operator+=(int n) {
  while (n-- > 0) {
    ++(*this);
  }
  return *this;
}

Date& Date::operator-=(int n) {
  while (n-- > 0) {
    --(*this);
  }
  return *this;
}

const Date Date::operator++() {
  int daysInMonth = (_month == 2 && leapYear(_year)) ? 29 : monthDays[_month - 1];
  if (++_day > daysInMonth) {
    _day = 1;
    if (++_month > 12) {
      _month = 1;
      ++_year;
    }
  }
  return *this;
}

const Date& Date::operator++(int) {
  Date temp(*this);
  ++(*this);
  return temp;
}

const Date Date::operator--() {
  if (--_day < 1) {
    if (--_month < 1) {
      _month = 12;
      --_year;
    }
    int daysInMonth = (_month == 2 && leapYear(_year)) ? 29 : monthDays[_month - 1];
    _day = daysInMonth;
  }
  return *this;
}

const Date& Date::operator--(int) {
  Date temp(*this);
  --(*this);
  return temp;
}
