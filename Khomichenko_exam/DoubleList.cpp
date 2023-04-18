//
// Created by x0lotl on 18.04.23.
//

#include "DoubleList.h"

std::ostream& operator<<(std::ostream& os, const DoubleList& list) {
  list.print(os);
  return os;
}

void DoubleList::print(std::ostream& os) const {
  Node* current = head;
  while (current != nullptr) {
    os << current->data << " ";
    current = current->next;
  }
}
