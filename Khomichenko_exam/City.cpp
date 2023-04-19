//
// Created by x0lotl on 18.04.23.
//

#include "City.h"

City::City() : name(""), population(0) {}

City::City(const std::string &name, int population) : name(name), population(population) {}

std::string City::getName() const {
  return name;
}

int City::getPopulation() const {
  return population;
}

void City::setName(const std::string &newName) {
  name = newName;
}

void City::setPopulation(int newPopulation) {
  population = newPopulation;
}

std::ostream &operator<<(std::ostream &os, const City &city) {
  os << "Назва міста: " << city.getName() << ", Популяція: " << city.getPopulation();
  return os;
}

City &City::operator=(const City &other) {
  if (this != &other) {
    name = other.name;
    population = other.population;
  }
  return *this;
}
