#include <iostream>
#include "Segment.h"
#include "Point.h"

int main() {
  Point point1(1,1);
  Point point2(5,6);
  Point point3(3,4);

  Segment segmet(point1, point2);
  std::cout << "My segment: " << segmet << std::endl;
  std::cout << "My segment length: " << segmet.length() << std::endl;
  std::cout << "Distance from point: " << point3 << "to my segment = " << segmet.distance(point3) << std::endl;
  return 0;
}
