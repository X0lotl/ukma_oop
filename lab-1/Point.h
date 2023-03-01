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
    int* pointer;
    static int _freeID;
    int _pointID;
    double _x;
    double _y;

public:
    Point(double x = 0, double y = 0) ;

    Point(const Point &);

    ~Point();

    Point &operator=(const Point &point) ;

    double &x() ;

    double &y() ;

    const double &x() const ;

   const double &y() const;

    const int getID() const ;

    static int amount();

};

std::ostream &operator<<(std::ostream &os, const Point &point);

const Point operator+(const Point &u, const Point &v);

Point operator+=(Point &u, const Point &v);

bool operator==(const Point &u, const Point &v);

bool operator!=(const Point &u, const Point &v);