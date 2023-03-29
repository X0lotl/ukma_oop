//
// Created by x0lotl on 22.03.23.
//
#include "Screen.h"
#include <iostream>
#include <limits>

Screen::Screen() {
}

void Screen::clearScreen() {
  std::cout << "\033[2J\033[1;1H"; // ANSI escape code for clearing screen
}

void Screen::displayMenu() {
  clearScreen();
  std::cout << "Text Screen Menu:\n";
  std::cout << "1. Add text\n";
  std::cout << "2. Remove text\n";
  std::cout << "3. Edit text\n";
  std::cout << "4. List texts\n";
  std::cout << "5. Quit\n";
  std::cout << "Enter your choice: ";
}
void Screen::processInput() {
  int choice;
  while (true) {
    displayMenu();
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
      case 1:
        addText();
        break;
      case 2:
        removeText();
        break;
      case 3:
        editText();
        break;
      case 4:
        listTexts();
        break;
      case 5:
        return;
      default:
        std::cout << "Invalid choice. Please try again.\n";
        break;
    }
  }
}

void Screen::printText(const std::string &text) {
  std::cout << text << std::endl;
}

void Screen::addText() {
  std::string text;
  std::cout << "Enter text to add: ";
  std::getline(std::cin, text);
  texts.push_back(text);
}

void Screen::removeText() {
  int index;
  listTexts();
  std::cout << "Enter the index of the text to remove: ";
  std::cin >> index;
  if (index >= 0 && index < texts.size()) {
    texts.erase(texts.begin() + index);
    std::cout << "Text removed successfully." << std::endl;
  } else {
    std::cout << "Invalid index." << std::endl;
  }
}

void Screen::editText() {
  int index;
  std::string newText;
  listTexts();
  std::cout << "Enter the index of the text to edit: ";
  std::cin >> index;
  if (index >= 0 && index < texts.size()) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter new text: ";
    std::getline(std::cin, newText);
    texts[index] = newText;
    std::cout << "Text updated successfully." << std::endl;
  } else {
    std::cout << "Invalid index." << std::endl;
  }
}

void Screen::listTexts() {
  if (texts.empty()) {
    std::cout << "No texts available." << std::endl;
  } else {
    for (size_t i = 0; i < texts.size(); ++i) {
      std::cout << i << ": " << texts[i] << std::endl;
    }
  }
}