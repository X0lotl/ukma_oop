//
// Created by x0lotl on 09.03.23.
//

#include "AComplex.h"
#include "iostream"
#include "cmath"

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

AComplex::AComplex(const AComplex &) {
  _a = a();
  _b = b();
}

AComplex::~AComplex() {
  delete pointer;
}

AComplex &AComplex::operator=(const AComplex &aComplex) {
  _a = aComplex.a();
  _b = aComplex.b();

  return *this;
}

std::ostream &operator<<(std::ostream &os, const AComplex &aComplex) {
  return os << "(" << aComplex.a() << " +  i * " << aComplex.b() << ")";
}

const AComplex operator+(const AComplex &z_1, const AComplex &z_2) {
  return AComplex(z_1.a() + z_2.a(), z_1.b() + z_2.b());
}


const AComplex operator*(const AComplex &z_1, const AComplex &z_2) {
  return AComplex((z_1.a() * z_1.b() - z_1.b() * z_2.b()), (z_1.a() * z_2.b() + z_1.b() * z_1.a()));
}

const AComplex operator-(const AComplex &z_1, const AComplex &z_2) {
  return AComplex(z_1.a() - z_2.a(), z_1.b() - z_2.b());
}

const AComplex operator/(const AComplex &z_1, const AComplex &z_2) {
  return AComplex((z_1.a() * z_2.a() + z_1.b() * z_2.b()) / (z_2.a() * z_2.a() + z_2.b() * z_2.b()),
                  (z_1.b() * z_2.a() - z_1.a() * z_2.b()) / (z_2.a() * z_2.a() + z_2.b() * z_2.b()));
}