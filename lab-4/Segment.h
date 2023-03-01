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
    int* pointer;
    static int _freeID;
    int _myId;
    Point _a;
    Point _b;

public:
    Segment(const double x1 = 0, const double y1 = 0,
            const double x2 = 1, const double y2 = 0);

    Segment(const Point &start, const Point &end);

    Segment(const Segment &segment);

    ~Segment();

    Segment &operator=(const Segment &segment);

    const Point &start() const;

    const Point &end() const;

    Point &start();

    Point &end();

    const double &startX() const;

    const double &startY() const;

    const double &endX() const;

    const double &endY() const;

    double &startX();

    double &startY();

    double &endX();

    double &endY();

    double length() const;

    double distance(const Point &point) const;

    const int getID() const;
};

std::ostream &operator<<(std::ostream &os, const Segment &segment);