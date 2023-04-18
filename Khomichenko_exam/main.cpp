#include <iostream>
#include "Cities.h"
#include "Fraction.h"
#include "DoubleSingleList.h"

int main() {
  std::cout << "---- Тестування 1 завдання ----" << std::endl;

  City cityArray[] = {
    City("Kyiv", 2884000),
    City("Kharkiv", 1441000),
    City("Odesa", 993000),
    City("Dnipro", 957000),
    City("Lviv", 721000),
  };

  Cities citiesUsingArray(cityArray, 5);

  std::cout << "Таблиця міст:\n" << citiesUsingArray << std::endl;

  std::cout << "\n\n ---- Тестування 2 завдання ---- " << std::endl;

  Cities citiesSorted(5);

  citiesSorted.addCity(City("Kyiv", 2884000));
  citiesSorted.addCity(City("Kharkiv", 1441000));
  citiesSorted.addCity(City("Odesa", 993000));
  citiesSorted.addCity(City("Dnipro", 957000));
  citiesSorted.addCity(City("Lviv", 721000));

  std::cout << "Таблиця міст в відсортованому порядку використовуючи addCity():\n" << citiesSorted << std::endl;


  std::cout << "\n\n ---- Тестування 3 завдання ---- " << std::endl;

  std::cout << "Таблиця відсортована за назвами міст: " << citiesSorted << std::endl;

  citiesSorted.sortByPopulationDescending();
  std::cout << "Таблиця відсотована за популяцією міст: " << citiesSorted << std::endl;

  citiesSorted.sortByAlphabet();
  std::cout << "Повернення до сортування за назвами: " << citiesSorted << std::endl;

  std::cout << "\n\n ---- Тестування 4 завдання ----" << std::endl;

  Fraction fractions[5] = {
    Fraction(5, 10),
    Fraction(15, 35),
    Fraction(30, -42),
    Fraction(-8, -16),
    Fraction(25, 5)
  };

  for (int i = 0; i < 5; ++i) {
    std::cout << "Тестовий випадок №" << (i + 1) << ": ";

    std::cout << fractions[i] << std::endl;
  }


  std::cout << "\n\n ---- Тестування 5 завдання ---- " << std::endl;

  Fraction f1(2, 3);
  Fraction f2(4, 6);

  std::cout << "f1: " << f1 << std::endl;
  std::cout << "f2: " << f2 << std::endl;
  std::cout << "f1 + f2: " << f1 + f2 << std::endl;
  std::cout << "f1 - f2: " << f1 - f2 << std::endl;
  std::cout << "f1 * f2: " << f1 * f2 << std::endl;
  std::cout << "f1 / f2: " << f1 / f2 << std::endl;

  f1 += f2;
  std::cout << "f1 += f2: " << f1 << std::endl;

  f1 -= f2;
  std::cout << "f1 -= f2: " << f1 << std::endl;

  f1 *= f2;
  std::cout << "f1 *= f2: " << f1 << std::endl;

  f1 /= f2;
  std::cout << "f1 /= f2: " << f1 << std::endl;

  std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
  std::cout << "f1 != f2: " << (f1 != f2) << std::endl;
  std::cout << "f1 > f2: " << (f1 > f2) << std::endl;
  std::cout << "f1 < f2: " << (f1 < f2) << std::endl;

  std::cout << "\n\n ---- Тестування 6 завдання ----" << std::endl;

  Fraction fraction1(3, 5);
  double decimal = fraction1.toDecimal();
  Fraction fraction2 = Fraction::fromDecimal(decimal);
  Fraction fraction3(decimal);

  std::cout << "f1: " << fraction1 << std::endl;
  std::cout << "f1 as decimal: " << decimal << std::endl;
  std::cout << "f2 (from decimal): " << fraction2 << std::endl;
  std::cout << "f3 (constructed from decimal): " << fraction3 << std::endl;

  std::cout << "\n\n ---- Тестування 7 завдання ----" << std::endl;
  std::cout << "Тестування завдання неможливе оскільки полягає в створені інтерфейсу (дивіться клас DoubleList)" << std::endl;

  std::cout << "\n\n ---- Тестування 8 завдання ----" << std::endl;
  DoubleSingleList list;

  list.insertFront(1);
  list.insertFront(2);
  list.insertFront(3);

  std::cout << "Список після додавання 1, 2 ,3 вперед списку: " << list << std::endl;

  list.insertBack(0);
  list.insertBack(-1);
  list.insertBack(-2);

  std::cout << "Список після додавання 0, -1, -2 в кінець списку: " << list << std::endl;

  list.deleteFront();
  list.deleteFront();

  std::cout << "Список після видалення перших 2-ох елементів: " << list << std::endl;

  list.deleteBack();
  list.deleteBack();

  std::cout << "Список після видалення останніх двох: " << list << std::endl;

  return 0;
}
