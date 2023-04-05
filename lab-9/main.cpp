#include <iostream>
#include "Sequence.h"

int main() {
  Sequence<int> seq;

  seq.append(1);
  seq.append(2);
  seq.append(3);
  seq.append(4);
  seq.append(5);
  std::cout << "Тест int послідовності:" << std::endl;
  std::cout << "Послідовність: " << seq << std::endl;

  seq.remove(3);
  std::cout << "Послідовність після видалення 3: " << seq << std::endl;

  seq.removeElementByIndex(0);
  std::cout << "Послідовність після видалення 1-го елементу (з індексом 0): " << seq << std::endl;

  std::cout << "Чи належить елемент 4 до послідовності? " << (seq.contains(4) ? "Так" : "Ні") << std::endl;
  std::cout << "Чи належить елемент 7 до послідовності? " << (seq.contains(7) ? "Так" : "Ні") <<  std::endl;


  Sequence<std::string> str_seq;

  str_seq.append("one");
  str_seq.append("two");
  str_seq.append("three");
  str_seq.append("four");
  str_seq.append("five");


  std::cout << "\n\nТест string послідовності:" << std::endl;
  std::cout << "Послідовність: " << str_seq << std::endl;

  str_seq.remove("three");
  std::cout << "Послідовність після видалення 'three': " << str_seq << std::endl;

  str_seq.removeElementByIndex(0);
  std::cout << "Послідовність після видалення 1-го елементу (з індексом 0): " << str_seq << std::endl;

  std::cout << "Чи належить елемент 'four' до послідовності? " << (str_seq.contains("four") ? "Так" : "Ні") << std::endl;
  std::cout << "Чи належить елемент 'seven' до послідовності? " << (str_seq.contains("seven") ? "Так" : "Ні") << std::endl;

  Sequence<double> double_seq;

  double_seq.append(1.1);
  double_seq.append(2.2);
  double_seq.append(3.3);
  double_seq.append(4.4);
  double_seq.append(5.5);


  std::cout << "\n\nТест double послідновності:" << std::endl;
  std::cout << "Послідовність: " << double_seq << std::endl;

  double_seq.remove(3.3);
  std::cout << "Послідовність після видалення 3.3: " << double_seq << std::endl;

  double_seq.removeElementByIndex(0);
  std::cout << "Послідовність після видалення 1-го елементу (з індексом 0): " << double_seq << std::endl;

  std::cout << "Чи належить елемент 4.4 до послідовності? " << (double_seq.contains(4.4) ? "Так" : "Ні") << std::endl;
  std::cout << "Чи належить елемент 7.7 до послідовності? " << (double_seq.contains(7.7) ? "Так" : "Ні") << std::endl;
  return 0;
}
