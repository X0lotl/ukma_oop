#include <iostream>
#include "String.h"

int main() {
  String s1("Danylo");
  std::string s2(" Khomichenko");
  const char* p = " Sergiyovich";

  std::cout << s1 << s2 << p << std::endl;

  std::cout << "First leter of name: " << s1[0] << std::endl;

  String s3 = s1 + s2;
  std::cout << s3 << std::endl;

  std::string s4 = s2 + s1;
  std::cout << s4 << std::endl;

  String s5 = p + s1;
  std::cout << s5 << std::endl;

  String s6 = s1 + p;
  std::cout << s6 << std::endl;
  return 0;
}
