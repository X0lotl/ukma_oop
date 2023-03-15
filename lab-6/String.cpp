//
// Created by x0lotl on 15.03.23.
//

#include <cstring>
#include <string>
#include "String.h"


String::String() : _data(nullptr), _size(0) {}

String::String(const char *str) {
  _size = std::strlen(str);
  _data = new char[_size + 1];
  std::strcpy(_data, str);
}

String::String(const std::string &str) : String(str.c_str()) {}

String::String(const String &other) : _size(other._size) {
  _data = new char[_size + 1];
  std::strcpy(_data, other._data);
}

String::String(String &&other) : _data(other._data), _size(other._size) {
  other._data = nullptr;
  other._size = 0;
}

String::~String() {
  delete[] _data;
}


String &String::operator=(const String &other) {
  if (this != &other) {
    delete[] _data;
    _size = other._size;
    _data = new char[_size + 1];
    std::strcpy(_data, other._data);
  }
  return *this;
}

String &String::operator=(String &&other) {
  if (this != &other) {
    delete[] _data;
    _data = other._data;
    _size = other._size;
    other._data = nullptr;
    other._size = 0;
  }
  return *this;
}

String &String::operator+=(const String &other) {
  const size_t new_size = _size + other._size;
  char *new_data = new char[new_size + 1];
  std::strcpy(new_data, _data);
  std::strcpy(new_data + _size, other._data);
  delete[] _data;
  _data = new_data;
  _size = new_size;
  return *this;
}

char &String::operator[](size_t index) {
  return _data[index];
}

const char &String::operator[](size_t index) const {
  return _data[index];
}

String String::operator+(const String &other) const {
  String result(*this);
  result += other;
  return result;
}

bool String::operator==(const String &other) const {
  return _size == other._size && std::strcmp(_data, other._data) == 0;
}

bool String::operator!=(const String &other) const {
  return !(*this == other);
}

String operator+(const std::string &lhs, const String &rhs) {
  String result(lhs.c_str());
  result += rhs;
  return result;
}

String::operator std::string() const {
  return std::string(_data);
}

String String::operator+(const char *s) const {
  String result(*this);
  result += s;
  return result;

}

std::ostream& operator<<(std::ostream& os, char c) {
  os << std::string(1, c);
  return os;
}

std::ostream &operator<<(std::ostream &os, const String &s) {
  for (std::size_t i = 0; i < s._size; ++i) {
    os << s._data[i];
  }
  return os;
}
