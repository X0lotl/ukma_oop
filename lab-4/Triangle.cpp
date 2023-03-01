//
// Created by x0lotl on 01.03.23.
//

#include "Triangle.h"

Triangle::Triangle(Point A, Point B, Point C) {
  _a = A;
  _b = B;
  _c = C;
  pointer = new int;
}

Triangle::Triangle(const Segment &segment1, const Segment &segment2) {
  if(segment1.end() == segment2.start()) {
    _a = segment1.start();
    _b = segment1.end();
    _c = segment2.end();
    pointer = new int;
  }
}

Triangle::Triangle(const Triangle &triangle) {
  _a = triangle._a;
  _b = triangle._b;
  _c = triangle._c;
  pointer = new int;
}

const Point &Triangle::A() const {
  return _a;
}

const Point &Triangle::B() const {
  return _b;
}

const Point &Triangle::C() const {
  return _c;
}

Point &Triangle::A() {
  return _a;
}

Point &Triangle::B() {
  return _b;
}

Point &Triangle::C() {
  return _c;
}

Triangle::~Triangle() {
  delete pointer;
}

Segment Triangle::AB() {
  return Segment(A(), B());
}

Segment Triangle::BC() {
  return Segment(B(), C());
}

Segment Triangle::CA() {
  return Segment(C(), A());
}

Segment Triangle::median(Point &vertex, Segment side) {
  Point middle((side.startX() + side.endX())/2, (side.startY() + side.endY())/2);

  return Segment(vertex, middle);
}


std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
  return os << "{ a:" << triangle.A() << ", b:" << triangle.B() << ", c:" << triangle.C() << "}";
};