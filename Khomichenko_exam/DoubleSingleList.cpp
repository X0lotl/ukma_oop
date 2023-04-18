//
// Created by x0lotl on 18.04.23.
//

#include "DoubleSingleList.h"

DoubleSingleList::~DoubleSingleList() {
  while (head != nullptr) {
    deleteFront();
  }
}

void DoubleSingleList::insertFront(int value) {
  Node *newNode = new Node(value);

  if (head == nullptr) {
    head = tail = newNode;
  } else {
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void DoubleSingleList::insertBack(int value) {
  Node *newNode = new Node(value);

  if (tail == nullptr) {
    head = tail = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
}

void DoubleSingleList::deleteFront() {
  if (head == nullptr) {
    return;
  }

  Node *temp = head;
  head = head->next;

  if (head != nullptr) {
    head->prev = nullptr;
  } else {
    tail = nullptr;
  }

  delete temp;
}

void DoubleSingleList::deleteBack() {
  if (tail == nullptr) {
    return;
  }

  Node *temp = tail;
  tail = tail->prev;

  if (tail != nullptr) {
    tail->next = nullptr;
  } else {
    head = nullptr;
  }

  delete temp;
}

int DoubleSingleList::size() const {
  size_t count = 0;
  Node* current = head;

  while (current != nullptr) {
    count++;
    current = current->next;
  }

  return count;
}