//
// Created by x0lotl on 12.04.23.
//
#pragma once

template<typename T>
class IQueue {
public:
  virtual ~IQueue() {}

  virtual bool empty() const = 0;

  virtual bool full() const = 0;

  virtual const T &front() const = 0;

  virtual void pop() = 0;

  virtual void put(const T &value) = 0;

  virtual size_t capacity() const = 0;

  virtual size_t size() const = 0;
};
