//
// Created by x0lotl on 12.04.23.
//

#pragma once

#include <iostream>
#include <stdexcept>
#include "IQueue.h"

template<typename T>
class ArrayUnboundedQueue : public IQueue<T> {
private:
  T *data;
  size_t capacity_;
  size_t head;
  size_t tail;
  size_t count;

  void resize(size_t new_capacity) {
    T *new_data = new T[new_capacity];
    for (size_t i = 0; i < count; ++i) {
      new_data[i] = data[(head + i) % capacity_];
    }
    delete[] data;
    data = new_data;
    capacity_ = new_capacity;
    head = 0;
    tail = count;
  }

public:
  ArrayUnboundedQueue(size_t initial_capacity) : data(new T[initial_capacity]), capacity_(initial_capacity), head(0),
                                                 tail(0), count(0) {}

  ~ArrayUnboundedQueue() {
    delete[] data;
  }

  bool empty() const override {
    return count == 0;
  }

  bool full() const override {
    return false;
  }

  const T &front() const override {
    if (empty()) {
      throw std::runtime_error("Queue is empty");
    }
    return data[head];
  }

  void pop() override {
    if (empty()) {
      throw std::runtime_error("Queue is empty");
    }
    head = (head + 1) % capacity_;
    --count;
  }

  void put(const T &value) override {
    if (count == capacity_) {
      resize(capacity_ * 2);
    }
    data[tail] = value;
    tail = (tail + 1) % capacity_;
    ++count;
  }

  size_t capacity() const override {
    return capacity_;
  }

  size_t size() const override {
    return count;
  }
};
