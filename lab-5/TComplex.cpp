//
// Created by x0lotl on 09.03.23.
//

#include "TComplex.h"
#include "cmath"

TComplex::TComplex(double r, double fi) {
 _r = r;
 _fi = fi;
 pointer = new int;
}

TComplex::TComplex(const TComplex &) {
  _r = r();
  _fi = fi();
}

TComplex::~TComplex() {

}

double &TComplex::r() {
  return _r;
}

double &TComplex::fi() {
  return _fi;
}

const double &TComplex::fi() const {
  return _r;
}

TComplex &TComplex::operator=(const TComplex &tComplex) {
  _r = tComplex.r();
  _fi = tComplex.fi();
  return * this;
}

const double &TComplex::r() const {
  return _r;
}


std::ostream &operator<<(std::ostream &os, const TComplex &tComplex) {
  return os << tComplex.r() << " * (" << cos(tComplex.fi()) << " + i * " << sin(tComplex.fi()) << ")";
}

const TComplex operator *(const TComplex &z_1, const TComplex &z_2) {
  return TComplex(z_1.r() * z_2.r(), z_1.fi() + z_2.fi() );
}

const TComplex operator /(const TComplex &z_1, const TComplex &z_2 ) {
  return TComplex(z_1.r()/z_2.r(), z_1.fi() - z_2.fi());
}

