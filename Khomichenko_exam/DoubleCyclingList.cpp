//
// Created by x0lotl on 18.04.23.
//

#include "DoubleCyclingList.h"

template <typename T>
void DoubleCyclingList<T>::insertFront(T value) {
  Node* newNode = new Node(value);

  if (this->head == nullptr) {
    this->head = newNode;
    this->tail = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
  } else {
    newNode->next = this->head;
    newNode->prev = this->tail;
    this->head->prev = newNode;
    this->tail->next = newNode;
    this->head = newNode;
  }

  // Збільшення розміру списку
  this->listSize++;
}

template <typename T>
void DoubleCyclingList<T>::insertBack(T value) {
  Node* newNode = new Node(value);

  if (this->head == nullptr) {
    this->head = newNode;
    this->tail = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
  } else {
    newNode->next = this->head;
    newNode->prev = this->tail;
    this->head->prev = newNode;
    this->tail->next = newNode;
    this->tail = newNode;
  }

  // Збільшення розміру списку
  this->listSize++;
}

template <typename T>
void DoubleCyclingList<T>::deleteFront() {
  if (this->head == nullptr) {
    return;
  }

  Node* temp = this->head;

  if (this->head != this->tail) {
    this->head = this->head->next;
    this->head->prev = this->tail;
    this->tail->next = this->head;
  } else {
    this->head = nullptr;
    this->tail = nullptr;
  }

  delete temp;

  // Зменшення розміру списку
  this->listSize--;
}

template <typename T>
void DoubleCyclingList<T>::deleteBack() {
  if (this->tail == nullptr) {
    return;
  }

  Node* temp = this->tail;

  if (this->head != this->tail) {
    this->tail = this->tail->prev;
    this->tail->next = this->head;
    this->head->prev = this->tail;
  } else {
    this->head = nullptr;
    this->tail = nullptr;
  }

  delete temp;

  // Зменшення розміру списку
  this->listSize--;
}
