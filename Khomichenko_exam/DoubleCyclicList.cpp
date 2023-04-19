//
// Created by x0lotl on 18.04.23.
//

#include "DoubleCyclicList.h"

template <typename T>
void DoubleCyclicList<T>::insertFront(T value) {
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

  this->listSize++;
}

template <typename T>
void DoubleCyclicList<T>::insertBack(T value) {
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

  this->listSize++;
}

template <typename T>
void DoubleCyclicList<T>::deleteFront() {
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

  this->listSize--;
}

template <typename T>
void DoubleCyclicList<T>::deleteBack() {
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

  this->listSize--;
}

template<typename T>
DoubleCyclicList<T> &DoubleCyclicList<T>::operator=(const DoubleCyclicList<T> &other) {
  if (this != &other) {
    int size = other.size();
    int counterDeleting = 0;
    while (this->head != nullptr && counterDeleting < size) {
      Node *temp = this->head;
      this->head = this->head->next;
      delete temp;
      counterDeleting++;
    }
    this->tail = nullptr;

    int counter = 0;

    Node *current = other.head;
    while (current != nullptr && counter < size) {
      Node *newNode = new Node(current->data);

      if (this->tail == nullptr) {
        this->head = this->tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
      } else {
        newNode->prev = this->tail;
        newNode->next = this->head;
        this->tail->next = newNode;
        this->head->prev = newNode;
        this->tail = newNode;
      }

      current = current->next;
      counter++;
    }
  }
  return *this;
}

template <typename T>
void DoubleCyclicList<T>::insert(const T& data, int index) {
  if (index < 0 || index > this->size()) {
    throw std::out_of_range("Index out of range");
  }

  Node* newNode = new Node(data);

  if (this->head == nullptr) {
    this->head = this->tail = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
    this->listSize++;
  } else if (index == 0) {
    insertFront(data);
  } else if (index == this->size()) {
    insertBack(data);
  } else {
    Node* current = this->head;
    for (int i = 0; i < index - 1; ++i) {
      current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;

    this->listSize++;
  }
}


template <typename T>
const T& DoubleCyclicList<T>::get(int index) const {
  if (index < 0 || index >= this->size()) {
    throw std::out_of_range("Index out of range");
  }

  Node* current = this->head;
  for (int i = 0; i < index; ++i) {
    current = current->next;
  }
  return current->data;
}

template <typename T>
void DoubleCyclicList<T>::remove(int index) {
  if (index < 0 || index >= this->size()) {
    throw std::out_of_range("Index out of range");
  }

  if (this->size() == 1) {
    delete this->head;
    this->head = this->tail = nullptr;
    this->listSize--;
  } else if (index == 0) {
    deleteFront();
  } else if (index == this->size() - 1) {
    deleteBack();
  } else {
    Node* current = this->head;
    for (int i = 0; i < index; ++i) {
      current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    this->listSize--;
  }
}
