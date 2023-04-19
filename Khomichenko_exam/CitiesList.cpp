//
// Created by x0lotl on 19.04.23.
//

#include "CitiesList.h"

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
void CitiesList<T>::sortByPopulation() {
  T temp = citiesList;
  T sortedList;
  int size = citiesList.size();

  for (int i = 0; i < size; ++i) {
    int minIndex = 0;
    for (int j = 1; j < temp.size(); ++j) {
      if (temp.get(j).getPopulation() < temp.get(minIndex).getPopulation()) {
        minIndex = j;
      }
    }
    sortedList.insertBack(temp.get(minIndex));
    temp.remove(minIndex);
  }
  citiesList = sortedList;
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
  int size = list.citiesList.size();

  for (int i = 0; i < list.citiesList.size(); ++i) {
    os << list.citiesList.get(i);
    if (i != list.citiesList.size() - 1) {
      os << std::endl;
    }
  }
  return os;
}
