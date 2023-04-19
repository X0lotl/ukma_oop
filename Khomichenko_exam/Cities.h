//
// Created by x0lotl on 18.04.23.
//

#pragma once

#include "City.h"

class Cities {
public:
  Cities(int initialCapacity);

  Cities(const City* cityArray, int arraySize);

  ~Cities();

  void addCity(const City& city);

  City& operator[](int index);

  City& getCity(int index);

  int getSize() const;

  friend std::ostream& operator<<(std::ostream& os, const Cities& cities);

  void sortByPopulationDescending();

  void sortByPopulationAscending();

  void sortByAlphabet();

private:
  City* cityArray;
  City* sortedByAlphabet;
  int size;
  int capacity;

  static std::string toUpperString(const std::string& input);

  void updateSortedByAlphabet();

  void resizeArray();
};