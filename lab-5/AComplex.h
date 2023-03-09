//
// Created by x0lotl on 09.03.23.
//
#pragma once
#include "iostream"
class AComplex {
private:
    double _a;
    double _b;
    int* pointer;
public:
    AComplex(double a, double b);

    double &a();

    double &b();

    const double &a() const;

    const double &b() const;
};

std::ostream &operator<<(std::ostream &os, const AComplex &aComplex);