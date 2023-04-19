//
// Created by x0lotl on 18.04.23.
//

#include "Cities.h"

Cities::Cities(int initialCapacity) : cityArray(new City[initialCapacity]), size(0), capacity(initialCapacity) {}

Cities::Cities(const City *cityArray, int arraySize) : cityArray(new City[arraySize]), size(arraySize),
                                                       capacity(arraySize) {
  for (int i = 0; i < arraySize; ++i) {
    this->cityArray[i] = cityArray[i];
  }
}

Cities::~Cities() {
  delete[] cityArray;
}

void Cities::addCity(const City& city) {
  if (size >= capacity) {
    resizeArray();
  }

  std::string newCityUpperName = toUpperString(city.getName());
  int index = size;
  for (int i = 0; i < size; ++i) {
    if (newCityUpperName < toUpperString(cityArray[i].getName())) {
      index = i;
      break;
    }
  }

  for (int i = size; i > index; --i) {
    cityArray[i] = cityArray[i - 1];
  }
  cityArray[index] = city;
  size++;
}

City& Cities::operator[](int index) {
  return getCity(index);
}

City &Cities::getCity(int index) {
  if (index < 0 || index >= size) {
    std::cerr << "Invalid index!" << std::endl;
    throw std::out_of_range("Invalid index");
  }
  return cityArray[index];
}

int Cities::getSize() const {
  return size;
}

std::ostream &operator<<(std::ostream &os, const Cities &cities) {
  os << "[\n";
  for (int i = 0; i < cities.size; ++i) {
    os << "(" << cities.cityArray[i].getName() << ", " << cities.cityArray[i].getPopulation() << ")" << std::endl;
  }

  os << "]";
  return os;
}

void Cities::resizeArray() {
  int newCapacity = capacity * 2;
  City *newArray = new City[newCapacity];

  for (int i = 0; i < size; ++i) {
    newArray[i] = cityArray[i];
  }

  delete[] cityArray;
  cityArray = newArray;
  capacity = newCapacity;
}

std::string Cities::toUpperString(const std::string& input) {
  std::string upperString = input;
  for (size_t i = 0; i < input.length(); ++i) {
    upperString[i] = std::toupper(input[i]);
  }
  return upperString;
}

void Cities::sortByPopulationDescending() {
  for (int i = 1; i < size; ++i) {
    City key = cityArray[i];
    int j = i - 1;

    while (j >= 0 && cityArray[j].getPopulation() < key.getPopulation()) {
      cityArray[j + 1] = cityArray[j];
      --j;
    }
    cityArray[j + 1] = key;
  }
}

void Cities::sortByPopulationAscending() {
  for (int i = 1; i < size; ++i) {
    City key = cityArray[i];
    int j = i - 1;

    while (j >= 0 && cityArray[j].getPopulation() > key.getPopulation()) {
      cityArray[j + 1] = cityArray[j];
      --j;
    }
    cityArray[j + 1] = key;
  }
}

void Cities::sortByAlphabet() {
  for (int i = 1; i < size; ++i) {
    City key = cityArray[i];
    int j = i - 1;
    std::string keyUpperName = toUpperString(key.getName());

    while (j >= 0 && toUpperString(cityArray[j].getName()) > keyUpperName) {
      cityArray[j + 1] = cityArray[j];
      --j;
    }
    cityArray[j + 1] = key;
  }
}