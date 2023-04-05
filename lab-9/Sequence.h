//
// Created by x0lotl on 05.04.23.
//
#pragma once
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <string>

template <typename T>
class Sequence {
private:
  T* data;
  std::size_t capacity;
  std::size_t size;

  void resize(std::size_t new_capacity) {
    T* new_data = new T[new_capacity];
    for (std::size_t i = 0; i < size; ++i) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
  }

public:
  Sequence() : data(nullptr), capacity(0), size(0) {}

  // Деструктор
  ~Sequence() {
    delete[] data;
  }

  void append(const T& value) {
    if (size == capacity) {
      resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = value;
  }

  bool remove(const T& value) {
    for (std::size_t i = 0; i < size; ++i) {
      if (data[i] == value) {
        for (std::size_t j = i; j < size - 1; ++j) {
          data[j] = data[j + 1];
        }
        --size;
        return true;
      }
    }
    return false;
  }

  bool contains(const T& value) const {
    for (std::size_t i = 0; i < size; ++i) {
      if (data[i] == value) {
        return true;
      }
    }
    return false;
  }

  bool removeElementByIndex(std::size_t index) {
    if (index >= size) {
      return false;
    }

    for (std::size_t i = index; i < size - 1; ++i) {
      data[i] = data[i + 1];
    }
    --size;
    return true;
  }

  friend std::ostream& operator<<(std::ostream& os, const Sequence& seq) {
    for (std::size_t i = 0; i < seq.size; ++i) {
      os << seq.data[i] << " ";
    }
    return os;
  }
};