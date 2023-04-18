//
// Created by x0lotl on 18.04.23.
//

#include "DoubleList.h"

std::ostream& operator<<(std::ostream& os, const DoubleList& list) {
  if (list.head == nullptr) {
    os << "List is empty." << std::endl;
    return os;
  }

  DoubleList::Node* current = list.head;
  int count = 0;
  int maxCount = list.size();
  while (count < maxCount) {
    os << current->data << " ";
    current = current->next;
    count++;
  }
  os << std::endl;
  return os;
}

int DoubleList::size() const {
  return listSize;
}