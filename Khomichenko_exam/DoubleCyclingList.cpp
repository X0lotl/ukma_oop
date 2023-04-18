//
// Created by x0lotl on 18.04.23.
//

#include "DoubleCyclingList.h"

void DoubleCyclingList::insertFront(int value) {
  Node* newNode = new Node(value);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
  } else {
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    head = newNode;
  }

  // Збільшення розміру списку
  listSize++;
}

void DoubleCyclingList::insertBack(int value) {
  Node* newNode = new Node(value);

  if (head == nullptr) {
    head = newNode;
    tail = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
  } else {
    newNode->next = head;
    newNode->prev = tail;
    head->prev = newNode;
    tail->next = newNode;
    tail = newNode;
  }

  // Збільшення розміру списку
  listSize++;
}

void DoubleCyclingList::deleteFront() {
  if (head == nullptr) {
    return;
  }

  Node* temp = head;

  if (head != tail) {
    head = head->next;
    head->prev = tail;
    tail->next = head;
  } else {
    head = nullptr;
    tail = nullptr;
  }

  delete temp;

  // Зменшення розміру списку
  listSize--;
}

void DoubleCyclingList::deleteBack() {
  if (tail == nullptr) {
    return;
  }

  Node* temp = tail;

  if (head != tail) {
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
  } else {
    head = nullptr;
    tail = nullptr;
  }

  delete temp;

  // Зменшення розміру списку
  listSize--;
}
