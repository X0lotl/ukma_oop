//
// Created by x0lotl on 01.03.23.
//
#include "Segment.h"
#include "cmath"

int Segment::_freeID = 0;

Segment::Segment(const double x1, const double y1, const double x2, const double y2) {
  pointer = new int;
  _myId = _freeID++;
  _a = Point(x1, y1);
  _b = Point(x2, y2);
}

Segment::Segment(const Point &start, const Point &end) {
  pointer = new int;
  _a = start;
  _b = end;
}

Segment::Segment(const Segment &segment) {
  pointer = new int;
  _a = segment._a;
  _b = segment._b;
}

Segment::~Segment() {
  delete pointer;
}

Segment &Segment::operator=(const Segment &segment) {
  _a = segment._a;
  _b = segment._b;
  _myId = segment._myId;
  return * this;
}

const Point &Segment::start() const {
  return _a;
}

const Point &Segment::end() const {
  return _b;
}

Point &Segment::start() {
  return _a;
}

Point &Segment::end() {
  return _b;
}

const double &Segment::startX() const {
  return _a.x();
}

const double &Segment::startY() const {
  return _a.y();
}

const double &Segment::endX() const {
  return _b.x();
}

const double &Segment::endY() const {
  return _b.y();
}

double &Segment::startX() {
  return _a.x();
}

double &Segment::startY() {
  return _a.y();
}

double &Segment::endX() {
  return _b.x();
}

double &Segment::endY() {
  return _b.y();
}

double Segment::length() const {
  return sqrt(pow((_b.x() - _a.x()), 2) + pow((_b.y() - _a.y()), 2));
}

double Segment::distance(const Point &point) const {
  double A = _a.y() - _b.y();
  double B = _a.x() - _b.x();
  double C = _a.y() * _b.x() - _b.y() * _a.x();

  return std::abs((A * point.x() + B * point.y() + C) / sqrt(A * A + B * B));
}

const int Segment::getID() const {
  return _myId;
}

std::ostream &operator<<(std::ostream &os, const Segment &segment){
  return os << "[" << segment.start() << ";" << segment.end() << "] ";
}