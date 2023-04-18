//
// Created by x0lotl on 18.04.23.
//

#include "Fraction.h"

Fraction::Fraction(int p, int q) : p(p), q(q) {
  if (q == 0) {
    throw std::invalid_argument("Denominator must not be zero");
  }
  simplify();
}

Fraction::Fraction(double decimal) {
  Fraction temp = Fraction::fromDecimal(decimal);
  p = temp.p;
  q = temp.q;
}

int Fraction::getNumerator() const {
  return p;
}

int Fraction::getDenominator() const {
  return q;
}

void Fraction::setNumerator(int p) {
  this->p = p;
  simplify();
}

void Fraction::setDenominator(int q) {
  if (q == 0) {
    throw std::invalid_argument("Denominator must not be zero");
  }
  this->q = q;
  simplify();
}

int Fraction::gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

void Fraction::simplify() {
  int divisor = gcd(p, q);
  p /= divisor;
  q /= divisor;
}

std::ostream &operator<<(std::ostream &os, const Fraction &fraction) {
  os << fraction.p << "/" << fraction.q;
  return os;
}

Fraction Fraction::operator+(const Fraction &other) const {
  int newP = p * other.q + other.p * q;
  int newQ = q * other.q;
  return Fraction(newP, newQ);
}

Fraction Fraction::operator-(const Fraction &other) const {
  int newP = p * other.q - other.p * q;
  int newQ = q * other.q;
  return Fraction(newP, newQ);
}

Fraction Fraction::operator*(const Fraction &other) const {
  int newP = p * other.p;
  int newQ = q * other.q;
  return Fraction(newP, newQ);
}

Fraction Fraction::operator/(const Fraction &other) const {
  if (other.p == 0) {
    throw std::invalid_argument("Division by zero");
  }
  int newP = p * other.q;
  int newQ = q * other.p;
  return Fraction(newP, newQ);
}


Fraction &Fraction::operator+=(const Fraction &other) {
  *this = *this + other;
  return *this;
}

Fraction &Fraction::operator-=(const Fraction &other) {
  *this = *this - other;
  return *this;
}

Fraction &Fraction::operator*=(const Fraction &other) {
  *this = *this * other;
  return *this;
}

Fraction &Fraction::operator/=(const Fraction &other) {
  *this = *this / other;
  return *this;
}

bool Fraction::operator==(const Fraction &other) const {
  return p == other.p && q == other.q;
}

bool Fraction::operator!=(const Fraction &other) const {
  return !(*this == other);
}

bool Fraction::operator>(const Fraction &other) const {
  return (static_cast<double>(p) / q) > (static_cast<double>(other.p) / other.q);
}

bool Fraction::operator<(const Fraction &other) const {
  return (static_cast<double>(p) / q) < (static_cast<double>(other.p) / other.q);
}

double Fraction::toDecimal() const {
  return static_cast<double>(p) / static_cast<double>(q);
}

Fraction Fraction::fromDecimal(double decimal, int precision) {
  int sign = (decimal >= 0) ? 1 : -1;
  decimal = std::abs(decimal);
  int integer_part = static_cast<int>(decimal);
  double fractional_part = decimal - integer_part;

  int numerator = static_cast<int>(fractional_part * precision);
  int denominator = precision;

  return Fraction(sign * (integer_part * precision + numerator), denominator);
}


