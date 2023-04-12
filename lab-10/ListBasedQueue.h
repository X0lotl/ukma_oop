//
// Created by x0lotl on 12.04.23.
//
#pragma once
#include "Sequence.h"
#include "IQueue.h"

template <typename T>
class ListBasedQueue : public IQueue<T> {
private:
  Sequence<T> sequence;

public:
  ListBasedQueue() {}

  bool empty() const override {
    return sequence.getSize() == 0;
  }

  bool full() const override {
    return false;
  }

  const T& front() const override {
    if (empty()) {
      throw std::runtime_error("Queue is empty");
    }
    return sequence[0];
  }

  void pop() override {
    if (empty()) {
      throw std::runtime_error("Queue is empty");
    }
    sequence.removeElementByIndex(0);
  }

  void put(const T& value) override {
    sequence.append(value);
  }

  size_t capacity() const override {
    return sequence.getCapacity();
  }

  size_t size() const override {
    return sequence.getSize();
  }
};
