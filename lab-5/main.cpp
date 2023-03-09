#include <iostream>
#include "AComplex.h"
#include "TComplex.h"
#include "cmath"

int main() {
  AComplex aComplex1(1,2);
  AComplex aComplex2(10, 2);
  std::cout << "Testin A complex" << std::endl;
  std::cout << "z1 = "<< aComplex1 << std::endl;
  std::cout << "z2 = " << aComplex2 << std::endl;
  std::cout << "z1 + z2 = " << aComplex1 + aComplex2 << std::endl;
  std::cout << "z1 - z2 = " << aComplex1 - aComplex2 << std::endl;
  std::cout << "z1 * z2 = " << aComplex1 * aComplex2 << std::endl;
  std::cout << "z1 / z2 = " << aComplex1 / aComplex2 << std::endl;

  std::cout << "\nTesting T complex" << std::endl;
  TComplex tComplex1(10, M_PI_2);
  TComplex tComplex2(22, M_PI_4);

  std::cout << "z1 = " << tComplex1 << std::endl;
  std::cout << "z2 = " << tComplex2 << std::endl;
  std::cout << "z1 * z2 = " << tComplex1 * tComplex2 << std::endl;
  std::cout << "z1 / z2 = " << tComplex1 / tComplex2 << std::endl;
  return 0;
}
