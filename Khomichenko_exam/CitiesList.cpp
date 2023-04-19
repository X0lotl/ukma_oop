//
// Created by x0lotl on 19.04.23.
//

#include "CitiesList.h"
#include "DoubleSingleList.h"

template<typename T>
void CitiesList<T>::addCity(const City &city) {
  citiesList.insertBack(city);
  updateSortedByAlphabet(city);
}

template<typename T>
void CitiesList<T>::displayCities() const {
  std::cout << citiesList;
}

template<typename T>
void CitiesList<T>::sortByAlphabet() {
  citiesList = sortedByAlphabet;
}

template<typename T>
void CitiesList<T>::sortByPopulationAscending() {
  int size = citiesList.size();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (citiesList.get(j).getPopulation() > citiesList.get(j + 1).getPopulation()) {
        City temp = citiesList.get(j);
        citiesList.remove(j);
        citiesList.insert(temp, j + 1);
      }
    }
  }
}

template<typename T>
void CitiesList<T>::sortByPopulationDescending() {
  int size = citiesList.size();
  for (int i = 0; i < size - 1; ++i) {
    for (int j = 0; j < size - i - 1; ++j) {
      if (citiesList.get(j).getPopulation() < citiesList.get(j + 1).getPopulation()) {
        City temp = citiesList.get(j);
        citiesList.remove(j);
        citiesList.insert(temp, j + 1);
      }
    }
  }
}


template<typename T>
void CitiesList<T>::updateSortedByAlphabet(const City &city) {
  int size = sortedByAlphabet.size();
  int pos = 0;
  for (; pos < size; ++pos) {
    if (city.getName() < sortedByAlphabet.get(pos).getName()) {
      break;
    }
  }
  sortedByAlphabet.insert(city, pos);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const CitiesList<T>& list) {
  for (int i = 0; i < list.citiesList.size(); ++i) {
    os << list.citiesList.get(i);
    if (i != list.citiesList.size() - 1) {
      os << std::endl;
    }
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const CitiesList<DoubleSingleList<City>> &list) {
  os << "\n[\n";
  for (int i = 0; i < list.citiesList.size(); ++i) {
    os << list.citiesList.get(i);
    if (i != list.citiesList.size() - 1) {
      os << std::endl;
    }
  }
  os << "\n]";
  return os;
}

std::ostream &operator<<(std::ostream &os, const CitiesList<DoubleCyclicList<City>> &list) {
  os << "\n[\n";
  for (int i = 0; i < list.citiesList.size(); ++i) {
    os << list.citiesList.get(i);
    if (i != list.citiesList.size() - 1) {
      os << std::endl;
    }
  }
  os << "\n]";
  return os;
}
