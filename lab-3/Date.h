#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
    struct BadDate;
    // to avoid problem 7.2.2002 7 feb or jul 2?
    enum Month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
    Date(int d = 0, Month m = Month(0), int y = 0) {
      this->_day = d;
      this->_month = m;
      this->_year = y;
    };
    Date(int d, int m, int y);
    Date(const Date&);
    Date& operator=(const Date&);
    ~Date();

    static void setDefault(int, Month, int);
    static void setDefault();
    static void showDefault();

    int day() const;
    Month month() const;
    int year() const;
    const string getMonthName() const;
    void setDay(int);
    void setMonth(int);
    void setDYear(int);

//	Arithmetics
    Date& operator+=(int);
    Date& operator-=(int);
    const Date operator++();
    const Date& operator++(int);
    const Date operator--();
    const Date& operator--(int);

private:
    int _day, _month, _year;
    void fillDate(int d, Month m, int y) {
      _day = d;
    };
    static string monthNames[12];
    static bool defaultSet;
    static Date defaultDate;

};

bool leapYear(int y);
ostream& operator<<(ostream& os, const Date& d);

struct Date::BadDate
{
    int _day, _month, _year;
    BadDate(int d, int m, int y) :_day(d), _month(m), _year(y) {};
};
ostream& operator<<(ostream& os, const Date::BadDate& bd);