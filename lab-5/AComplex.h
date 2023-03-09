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

    AComplex(const AComplex &);

    ~AComplex();

    double &a();

    double &b();

    const double &a() const;

    const double &b() const;

    AComplex &operator=(const AComplex &aComplex);
};

std::ostream &operator<<(std::ostream &os, const AComplex &aComplex);

const AComplex operator +(const AComplex &z_1, const AComplex &z_2);

const AComplex operator *(const AComplex &z_1, const AComplex &z_2);

const AComplex operator -(const AComplex &z_1, const AComplex &z_2);

const AComplex operator /(const AComplex &z_1, const AComplex &z_2);
