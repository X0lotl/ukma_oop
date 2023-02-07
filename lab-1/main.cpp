#include <iostream>
#include "Point.h"

int main() {
  Point point1(10,5);
  Point point2(3,3);
  Point point3(3, 3);
  std::cout << "Point 1:" << point1 << " Point 2:" << point2 << " Point 3:" << point3 <<  std::endl;
  std::cout << "Points id`s: P1:" << point1.getID() << " P2:"<< point2.getID() << " P3:" << point3.getID() << std::endl;
  std::cout << "P1 + P2 = " << point1 + point2 << std::endl;
  point1 += point2;
  std::cout << "P1 += P2 => P1 =" << point1 <<std::endl;
  std::cout << "P2 == P3 = " << std::boolalpha << (point2 == point3) << std::endl;
  std::cout << "P1 == P2 = " << std::boolalpha << (point1 == point2) << std::endl;
  std::cout << "P1 != P2 = " << std::boolalpha << (point1 != point2) << std::endl;
  std::cout << "P2 != P3 = " << std::boolalpha << (point2 != point3) << std::endl;
  std::cout << "Point 1:" << point1 << " Point 2:" << point2 << " Point 3:" << point3 <<  std::endl;
  return 0;
}