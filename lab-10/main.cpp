#include <iostream>
#include "ListBasedQueue.h"
#include "ArrayBoundedQueue.h"
#include "ArrayUnboundedQueue.h"

int main() {

  std::cout << "---- Тестування обмеженої черги на базі масиву ----" << std::endl;
  ArrayBoundedQueue<int> arrayBoundedQueue(3);

  std::cout << "Тест 1: перевірка на спробу підгляду в порожню чергу" << std::endl;
  try {
    arrayBoundedQueue.front();
  } catch (const std::runtime_error &e) {
    std::cout << "Запланована помилка: " << e.what() << std::endl;
  }

  std::cout << "Тест 2: додавання елементів до черги" << std::endl;
  arrayBoundedQueue.put(1);
  arrayBoundedQueue.put(2);
  arrayBoundedQueue.put(3);

  std::cout << "Тест 3: перевірка на спробу додати до повної черги" << std::endl;
  try {
    arrayBoundedQueue.put(4);
  } catch (const std::runtime_error &e) {
    std::cout << "Запланована помилка: " << e.what() << std::endl;
  }

  std::cout << "Тест 4: перевірка на підглядання та видалення елементів" << std::endl;
  while (!arrayBoundedQueue.empty()) {
    std::cout << arrayBoundedQueue.front() << std::endl;
    arrayBoundedQueue.pop();
  }


  std::cout << "\n\n ---- Тестування необмеженої черги на базі масиву ----" << std::endl;
  ArrayUnboundedQueue<int> arrayUnboundedQueue(3);

  std::cout << "Тест 1: перевірка на спробу підгляду в порожню чергу" << std::endl;
  try {
    arrayUnboundedQueue.front();
  } catch (const std::runtime_error &e) {
    std::cout << "Запланована помилка: " << e.what() << std::endl;
  }

  std::cout << "Тест 2: додавання елементів до черги" << std::endl;
  arrayUnboundedQueue.put(1);
  arrayUnboundedQueue.put(2);
  arrayUnboundedQueue.put(3);
  arrayUnboundedQueue.put(4); // Черга збільшиться, щоб вмістити ще один елемент

  std::cout << "Тест 3: перевірка на підглядання та видалення елементів" << std::endl;
  while (!arrayUnboundedQueue.empty()) {
    std::cout << arrayUnboundedQueue.front() << std::endl;
    arrayUnboundedQueue.pop();
  }

  std::cout << "Тест 4: додавання більше елементів, ніж початкова місткість" << std::endl;
  for (int i = 1; i <= 10; ++i) {
    arrayUnboundedQueue.put(i);
  }

  std::cout << "Тест 5: перевірка на підглядання та видалення елементів зі збільшеною чергою" << std::endl;
  while (!arrayUnboundedQueue.empty()) {
    std::cout << arrayUnboundedQueue.front() << std::endl;
    arrayUnboundedQueue.pop();
  }

  std::cout << "\n\n ---- Тестування черги на базі власного списку з Лаборатоної 9 ----" << std::endl;
  ListBasedQueue<int> listQueue;

  std::cout << "Тест 1: перевірка на спробу підгляду в порожню чергу" << std::endl;
  try {
    listQueue.front();
  } catch (const std::runtime_error &e) {
    std::cout << "Запланована помилка " << e.what() << std::endl;
  }

  std::cout << "Тест 2: додавання елементів до черги" << std::endl;
  listQueue.put(1);
  listQueue.put(2);
  listQueue.put(3);
  listQueue.put(4);

  std::cout << "Тест 3: перевірка на підглядання та видалення елементів" << std::endl;
  while (!listQueue.empty()) {
    std::cout << listQueue.front() << std::endl;
    listQueue.pop();
  }

  std::cout << "Тест 4: додавання більше елементів, ніж початкова місткість" << std::endl;
  for (int i = 1; i <= 10; ++i) {
    listQueue.put(i);
  }

  std::cout << "Тест 5: перевірка на підглядання та видалення елементів зі збільшеною чергою" << std::endl;
  while (!listQueue.empty()) {
    std::cout << listQueue.front() << std::endl;
    listQueue.pop();
  }

  return 0;
}

