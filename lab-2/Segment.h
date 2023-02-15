//
// Created by x0lotl on 14.02.23.
//
#pragma once
//*******************************************
//Every segment posesses its unique ID.
//In debug mode both constructor and destructor
//report the ID and the coordinates
//of a segment created or resp. deleted
//Developed by .....................
//at ....................
//Version 1.0

//*******************************************
#include <iostream>
#include "Point.h"
#include "cmath"

class Segment {
private:
    static int _freeID;
    int _myId;
    Point _a;
    Point _b;

public:
    Segment(const double x1 = 0, const double y1 = 0,
            const double x2 = 1, const double y2 = 0) {
      _a = Point(0, 0);
      _b = Point(1, 0);
      _myId = _freeID++;
    };

    Segment(const Point &start, const Point &end) {
      _a = start;
      _b = end;
    };

    Segment(const Segment &segment) {
      _a = segment._a;
      _b = segment._b;
    };

    ~Segment() {

    };

    Segment &operator=(const Segment &segment) {
      _a = segment._a;
      _b = segment._b;
      _myId = segment._myId;
    };

    const Point &start() const {
      return _a;
    };

    const Point &end() const {
      return _b;
    };

    Point &start() {
      return _a;
    };

    Point &end() {
      return _b;
    };

    const double &startX() const {
      return _a.x();
    };

    const double &startY() const {
      return _a.y();
    };

    const double &endX() const {
      return _b.x();
    };

    const double &endY() const {
      return _b.y();
    };

    double &startX() {
      return _a.x();
    };

    double &startY() {
      return _a.y();
    };

    double &endX() {
      return _b.x();
    };

    double &endY() {
      return _b.y();
    };

    double length() const {
      return sqrt(pow((_b.x() - _a.x()), 2) + pow((_b.y() - _a.y()), 2));
    };

    double distance(const Point &point) const {
      double A = _a.y() - _b.y();
      double B = _a.x() - _b.x();
      double C = _a.y() * _b.x() - _b.y() * _a.x();

      return std::abs((A * point.x() + B * point.y() + C) / sqrt(A * A + B * B));
    };

    const int getID() const {
      return _myId;
    };
};
int Segment::_freeID = 0;

std::ostream &operator<<(std::ostream &os, const Segment &segment) {
  return os << "[" << segment.start() << ";" << segment.end() << "] ";
};