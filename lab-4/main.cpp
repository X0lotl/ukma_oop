#include <iostream>
#include "Triangle.h"
#include "Point.h"
#include "Segment.h"

int main() {
  Point a(1,1);
  Point b(5,6);
  Point c(3,2);

  Triangle triangle(a,b,c);

  std::cout << "My triangle: " << triangle << std::endl;
  std::cout << "Median from A to BC" << triangle.median(triangle.A(), triangle.BC());
  return 0;
}
