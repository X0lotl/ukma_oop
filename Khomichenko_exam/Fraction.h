//
// Created by x0lotl on 18.04.23.
//

#pragma once

#include <iostream>

class Fraction {
public:
  Fraction(int p, int q);

  Fraction(double decimal);

  int getNumerator() const;

  int getDenominator() const;

  void setNumerator(int p);

  void setDenominator(int q);

  friend std::ostream &operator<<(std::ostream &os, const Fraction &fraction);

  Fraction operator+(const Fraction &other) const;

  Fraction operator-(const Fraction &other) const;

  Fraction operator*(const Fraction &other) const;

  Fraction operator/(const Fraction &other) const;

  Fraction &operator+=(const Fraction &other);

  Fraction &operator-=(const Fraction &other);

  Fraction &operator*=(const Fraction &other);

  Fraction &operator/=(const Fraction &other);

  bool operator==(const Fraction &other) const;

  bool operator!=(const Fraction &other) const;

  bool operator>(const Fraction &other) const;

  bool operator<(const Fraction &other) const;

  double toDecimal() const;

  static Fraction fromDecimal(double decimal, int precision = 1000);

private:
  int p;
  int q;

  static int gcd(int a, int b);

  void simplify();
};