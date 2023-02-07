//
// Created by x0lotl on 05.02.23.
//
#pragma once

#include <iostream>

//*******************************************

//Every point posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a point created or resp. deleted
//Developed by .....................
//on ....................
//Version 1.0

//*******************************************

class Point {
private:
    static int _freeID;
    int _pointID;
    double _x;
    double _y;

public:
    Point(double x = 0, double y = 0) {
      _pointID = _freeID++;
      _x = x;
      _y = y;
    };

    Point(const Point &);

    ~Point() {
    };

    Point &operator=(const Point &point) {
      _x = point.x();
      _y = point.y();
      _pointID = point.getID();
    };

    double &x() {
      return _x;
    };

    double &y() {
      return _y;
    };

    [[nodiscard]] const double &x() const {
      return _x;
    };

    [[nodiscard]] const double &y() const {
      return _y;
    };

    [[nodiscard]] const int getID() const {
      return _pointID;
    };

    static int amount() {
      return _freeID;
    };

};

int Point::_freeID = 0;

std::ostream &operator<<(std::ostream &os, const Point &point) {
  return os << " (" << point.x() << ", " << point.y() << ") ";
}

const Point operator+(const Point &u, const Point &v) {
  return Point(u.x() + v.x(), u.y() + v.y());
};

Point operator+=(Point &u, const Point &v) {
  u = u + v;
  return  u + v;
};

bool operator==(const Point &u, const Point &v) {
  if (u.x() == v.x() && u.y() == v.y()) {
    return true;
  } else {
    return false;
  }
};

bool operator!=(const Point &u, const Point &v) {
  if (u.x() != v.x() || u.y() != v.y()) {
    return true;
  } else {
    return false;
  }
};

