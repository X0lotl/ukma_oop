//
// Created by x0lotl on 19.04.23.
//

#pragma once

#include <iostream>
#include "City.h"
#include "DoubleSingleList.h"
#include "DoubleCyclicList.h"

template<typename T>
class CitiesList {
public:
  void addCity(const City &city);

  void displayCities() const;

  void sortByAlphabet();

  void sortByPopulation();

  void sortByPopulationDescending();

  void sortByPopulationAscending();

  friend std::ostream &operator<<(std::ostream &os, const CitiesList<DoubleSingleList<City>> &list);

  friend std::ostream &operator<<(std::ostream &os, const CitiesList<DoubleCyclicList<City>> &list);

  friend std::ostream &operator<<(std::ostream &os, const CitiesList<T> &list);

private:
  T citiesList;
  T sortedByAlphabet;

  void updateSortedByAlphabet(const City &city);


};

template
class CitiesList<DoubleSingleList<City>>;

template
class CitiesList<DoubleCyclicList<City>>;
