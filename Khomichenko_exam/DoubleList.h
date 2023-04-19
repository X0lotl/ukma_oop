//
// Created by x0lotl on 18.04.23.
//

#pragma once

#include <iostream>

template<typename T>
class DoubleList {
public:
  virtual ~DoubleList() = default;

  virtual void insertFront(T value) = 0;

  virtual void insertBack(T value) = 0;

  virtual int size() const;

  virtual void deleteFront() = 0;

  virtual void deleteBack() = 0;

  friend std::ostream& operator<<(std::ostream& os, const DoubleList<T>& list) {
    if (list.head == nullptr) {
      os << "List is empty." << std::endl;
      return os;
    }

    DoubleList<T>::Node* current = list.head;
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

  class Node {
  public:
    T data;
    Node* prev;
    Node* next;

    Node(T value) : data(value), next(nullptr), prev(nullptr) {}
  };

protected:

  Node *head = nullptr;
  Node *tail = nullptr;

  int listSize;

};

template class DoubleList<int>;
