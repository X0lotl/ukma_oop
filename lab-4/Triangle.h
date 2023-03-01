//
// Created by x0lotl on 01.03.23.
//
#pragma once

#include "Point.h"
#include "Segment.h"
#include <iostream>

class Triangle {
private:
    Point _a;
    Point _b;
    Point _c;
    int* pointer;
    int _id;
public:
    Triangle(Point A, Point B, Point C);

    Triangle(const Segment &segment1, const Segment &segment2);

    Triangle(const Triangle &triangle);

    ~Triangle();

    const Point &A() const;

    const Point &B() const;

    const Point &C() const;

    Point &A();

    Point &B();

    Point &C();

    Segment AB();

    Segment BC();

    Segment CA();

    Segment median(Point &vertex, Segment side);
};

std::ostream &operator<<(std::ostream &os, const Triangle &triangle);