//
// Created by x0lotl on 05.04.23.
//
#pragma once
#include <iostream>
#include "vector"
#include "algorithm"

template <typename T>
class Sequence {
private:
  std::vector<T> data;

public:
  Sequence() {}

  void append(const T& value) {
    data.push_back(value);
  }

  bool remove(const T& value) {
    auto it = std::find(data.begin(), data.end(), value);
    if (it != data.end()) {
      data.erase(it);
      return true;
    }
    return false;
  }

  bool contains(const T& value) const {
    return std::find(data.begin(), data.end(), value) != data.end();
  }

  void print() const {
    for (const auto&elem : data) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }

  friend std::ostream& operator<<(std::ostream& os, const Sequence& seq) {
    for (const auto& elem : seq.data) {
      os << elem << " ";
    }
    return os;
  }
};