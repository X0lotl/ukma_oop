//
// Created by x0lotl on 09.03.23.
//
#pragma once
#include "iostream"
class  TComplex{
private:
    double _r;
    double _fi;
    int* pointer;
public:
    TComplex(double r, double fi);

    TComplex(const TComplex &);

    ~TComplex();

    double &r();

    double &fi();

    const double &r() const;

    const double &fi() const;

    TComplex &operator=(const TComplex &TComplex);
};

std::ostream &operator<<(std::ostream &os, const TComplex &TComplex);

const TComplex operator *(const TComplex &z_1, const TComplex &z_2);

const TComplex operator /(const TComplex &z_1, const TComplex &z_2);

