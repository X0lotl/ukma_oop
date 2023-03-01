//
// Created by x0lotl on 01.03.23.
//
#include "Point.h"

Point::Point(double x,double y) {
  pointer = new int;
  _pointID = _freeID++;
  _x = x;
  _y = y;
}

Point::~Point() {

}

Point::Point(const Point & point) {
  _pointID = point._pointID;
  _x = point._x;
  _y = point._y;
}

Point &Point::operator=(const Point &point) {
  _x = point.x();
  _y = point.y();
  _pointID = point.getID();
  return *this;
}

double &Point::x() {
  return _x;
}

double &Point::y() {
  return _y;
}

const double &Point::x() const {
  return _x;
}

const double &Point::y() const {
  return _y;
}

const int Point::getID() const {
  return _pointID;
}

int Point::amount() {
  return _freeID;
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
