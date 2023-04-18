#include <iostream>
#include "Date.h"

using namespace std;
int main() {
  // Тестування конструкторів
  Date date1;
  Date date2(14, Date::Month::apr, 2023);
  Date date3(14, 4, 2023);

  // Тестування методів
  cout << "Date1: " << date1 << endl;
  cout << "Date2: " << date2 << endl;
  cout << "Date3: " << date3 << endl;

  cout << "Month name: " << date2.getMonthName() << endl;

  // Тестування статичних методів
  Date::setDefault(1, Date::Month::jan, 2000);
  Date::showDefault();

  // Перевірка обробки некоректних дат
  try {
    Date badDate(32, 13, -1);
  } catch (Date::BadDate& bd) {
    cout << "Caught exception: " << bd << endl;
  }

  return 0;
}