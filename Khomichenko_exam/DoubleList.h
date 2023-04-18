//
// Created by x0lotl on 18.04.23.
//

#pragma once
#include <iostream>

class DoubleList {
public:
  virtual ~DoubleList() = default;

  virtual void insertFront(int value) = 0;
  virtual void insertBack(int value) = 0;
  virtual void deleteFront() = 0;
  virtual void deleteBack() = 0;

  friend std::ostream& operator<<(std::ostream& os, const DoubleList& list);

protected:
  struct Node {
    int data;
    Node* prev;
    Node* next;

    explicit Node(int data, Node* prev = nullptr, Node* next = nullptr)
      : data(data), prev(prev), next(next) {}
  };

  Node* head = nullptr;
  Node* tail = nullptr;

  void print(std::ostream& os) const;
};
