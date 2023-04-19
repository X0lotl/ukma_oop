//
// Created by x0lotl on 18.04.23.
//

#include "DoubleSingleList.h"

template <typename T>
DoubleSingleList<T>::~DoubleSingleList() {
  while (this->head != nullptr) {
    deleteFront();
  }
}

template <typename T>
void DoubleSingleList<T>::insertFront(T value) {
  Node *newNode = new Node(value);

  if (this->head == nullptr) {
    this->head = this->tail = newNode;
  } else {
    newNode->next = this->head;
    this->head->prev = newNode;
    this->head = newNode;
  }
}

template <typename T>
void DoubleSingleList<T>::insertBack(T value) {
  Node *newNode = new Node(value);

  if (this->tail == nullptr) {
    this->head = this->tail = newNode;
  } else {
    newNode->prev = this->tail;
    this->tail->next = newNode;
    this->tail = newNode;
  }
}

template <typename T>
void DoubleSingleList<T>::deleteFront() {
  if (this->head == nullptr) {
    return;
  }

  Node *temp = this->head;
  this->head = this->head->next;

  if (this->head != nullptr) {
    this->head->prev = nullptr;
  } else {
    this->tail = nullptr;
  }

  delete temp;
}

template <typename T>
void DoubleSingleList<T>::deleteBack() {
  if (this->tail == nullptr) {
    return;
  }

  Node *temp = this->tail;
  this->tail = this->tail->prev;

  if (this->tail != nullptr) {
    this->tail->next = nullptr;
  } else {
    this->head = nullptr;
  }

  delete temp;
}

template <typename T>
int DoubleSingleList<T>::size() const {
  size_t count = 0;
  Node* current = this->head;

  while (current != nullptr) {
    count++;
    current = current->next;
  }

  return count;
}