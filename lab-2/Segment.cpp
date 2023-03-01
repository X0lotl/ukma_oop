//
// Created by x0lotl on 01.03.23.
//
#include "Segment.h"

Segment::Segment(const double x1, const double y1, const double x2, const double y2) {
  pointer = new int;
  _myId = _freeID++;
  _a = Point(x1, y1);
  _b = Point(x2, y2);
}

Segment::Segment(const Point &start, const Point &end) {
  _a = start;
  _b = end;
}

Segment::Segment(const Segment &segment) {

}