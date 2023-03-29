//
// Created by x0lotl on 22.03.23.
//

#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>

class Screen {
public:
  Screen();

  void displayMenu();
  void processInput();

private:
  void clearScreen();
  void printText(const std::string &text);
  void addText();
  void removeText();
  void editText();
  void listTexts();

  std::vector<std::string> texts;
};

#endif // SCREEN_H