//
// Created by x0lotl on 18.04.23.
//

#pragma once

#include <string>
#include <iostream>

class City {
public:
  City();
  City(const std::string& name, int population);

  std::string getName() const;
  int getPopulation() const;

  void setName(const std::string& newName);
  void setPopulation(int newPopulation);

private:
  std::string name;
  int population;
};
