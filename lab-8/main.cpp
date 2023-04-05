#include <iostream>
#include "Array.h"

int main() {
  try {
    Array<5, int> intArray;
    for (size_t i = 0; i < 5; ++i) {
      intArray[i] = static_cast<int>(i);
    }
    std::cout << "Integer array: " << intArray << std::endl;

    Array<3, double> doubleArray;
    for (size_t i = 0; i < 3; ++i) {
      doubleArray[i] = i * 1.5;
    }
    std::cout << "Double array: " << doubleArray << std::endl;

    Array<4, std::string> stringArray;
    stringArray[0] = "One";
    stringArray[1] = "Two";
    stringArray[2] = "Three";
    stringArray[3] = "Four";
    std::cout << "String array: " << stringArray << std::endl;

    std::cout << "Accessing out of bounds element:" << std::endl;
    std::cout << intArray[5] << std::endl;

  } catch (const Array<5, int>::OutOfRangeException &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
