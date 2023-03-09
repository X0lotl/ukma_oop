//
// Created by x0lotl on 09.03.23.
//

#include "AComplex.h"
#include "iostream"

AComplex::AComplex(double a, double b) {
 _a = a;
 _b = b;
 pointer = new int;
}

double &AComplex::b() {
  return _b;
}

double &AComplex::a() {
  return _a;
}

const double &AComplex::a() const {
  return _a;
}

const double &AComplex::b() const {
  return _b;
}

std::ostream &operator<<(std::ostream &os, const AComplex &aComplex) {
  return os << "("<< aComplex.a() << " +  i * " << aComplex.b() << ")";
}