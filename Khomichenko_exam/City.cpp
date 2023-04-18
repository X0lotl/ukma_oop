//
// Created by x0lotl on 18.04.23.
//

#include "City.h"

City::City() : name(""), population(0) {}

City::City(const std::string& name, int population) : name(name), population(population) {}

std::string City::getName() const {
  return name;
}

int City::getPopulation() const {
  return population;
}

void City::setName(const std::string& newName) {
  name = newName;
}

void City::setPopulation(int newPopulation) {
  population = newPopulation;
}
