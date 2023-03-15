//
// Created by x0lotl on 15.03.23.
//
#pragma once

#include <cstring>
#include <string>

class String {

private:
  char * _data;
  size_t _size;
public:
  String();

  String(const char *str);

  String(const std::string &str);

  String(const String &other);


  String(String &&other);

  ~String() ;

  String &operator=(const String &other) ;

  String &operator=(String &&other);

  String &operator+=(const String &other) ;

  char &operator[](size_t index) ;

  const char &operator[](size_t index) const ;

  String operator+(const String &other) const ;

  bool operator==(const String &other) const ;

  bool operator!=(const String &other) const ;

  friend String operator+(const std::string& lhs, const String& rhs);

  operator std::string() const;

  String operator+(const char* s) const;

  friend std::ostream& operator<<(std::ostream& os, const String& s);
};