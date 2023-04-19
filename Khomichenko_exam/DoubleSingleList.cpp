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
  int count = 0;
  Node* current = this->head;

  while (current != nullptr) {
    count++;
    current = current->next;
  }

  return count;
}

template<typename T>
DoubleSingleList<T> &DoubleSingleList<T>::operator=(const DoubleSingleList<T> &other) {
  if (this != &other) {

    while (this->head != nullptr) {
      Node *temp = this->head;
      this->head = this->head->next;
      delete temp;
    }
    this->tail = nullptr;

    int size = other.size();
    int counter = 0;

    Node *current = other.head;
    while (current != nullptr && counter < size) {
      Node *newNode = new Node(current->data);

      if (this->tail == nullptr) {
        this->head = this->tail = newNode;
      } else {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
      }

      current = current->next;
      counter++;
    }
  }
  return *this;
}


template <typename T>
const T& DoubleSingleList<T>::get(int index) const {
  if (index < 0 || index >= size()) {
    throw std::out_of_range("Index out of range");
  }

  Node* current = this->head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }
  return current->data;
}


template <typename T>
void DoubleSingleList<T>::insert(const T& data, int index) {
  if (index < 0 || index > size()) {
    throw std::out_of_range("Index out of range");
  }

  if (index == 0) {
    insertFront(data);
  } else if (index == size()) {
    insertBack(data);
  } else {
    Node* newNode = new Node(data);
    Node* current = this->head;
    for (int i = 0; i < index - 1; ++i) {
      current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
  }
}

template <typename T>
void DoubleSingleList<T>::remove(int index) {
  if (index < 0 || index >= size()) {
    throw std::out_of_range("Index out of range");
  }

  if (index == 0) {
    deleteFront();
  } else if (index == size() - 1) {
    deleteBack();
  } else {
    Node* current = this->head;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
  }
}