//
// Created by x0lotl on 18.04.23.
//

#pragma once
#include "DoubleList.h"

template <typename T>
class DoubleSingleList : public DoubleList<T> {
public:
  using typename DoubleList<T>::Node;

  ~DoubleSingleList() override;

  void insertFront(T value) override;
  void insertBack(T value) override;
  void deleteFront() override;
  void deleteBack() override;

  int size() const override;
};

template class DoubleSingleList<int>;