//
// Created by x0lotl on 29.03.23.
//
#pragma once

#include <stdexcept>
#include <iostream>

template <size_t n, typename T>
class Array {
public:
  Array();
  T& operator[](size_t index);
  const T& operator[](size_t index) const;

  class OutOfRangeException : public std::exception {
  public:
    const char* what() const noexcept override;
  };

  template <size_t N, typename U>
  friend std::ostream& operator<<(std::ostream& os, const Array<N, U>& array);

private:
  T data[n];
};

template <size_t n, typename T>
Array<n, T>::Array() {
  for (size_t i = 0; i < n; ++i) {
    data[i] = T();
  }
}

template <size_t n, typename T>
T& Array<n, T>::operator[](size_t index) {
  if (index >= n) {
    throw OutOfRangeException();
  }
  return data[index];
}

template <size_t n, typename T>
const T& Array<n, T>::operator[](size_t index) const {
  if (index >= n) {
    throw OutOfRangeException();
  }
  return data[index];
}

template <size_t n, typename T>
const char* Array<n, T>::OutOfRangeException::what() const noexcept {
  return "Array index out of range";
}

template <size_t n, typename T>
std::ostream& operator<<(std::ostream& os, const Array<n, T>& array) {
  os << "[";
  for (size_t i = 0; i < n; ++i) {
    os << array[i];
    if (i < n - 1) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}