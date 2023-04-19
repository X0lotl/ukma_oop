//
// Created by x0lotl on 18.04.23.
//

#pragma once

#include "DoubleList.h"

template <typename T>
class DoubleCyclingList : public DoubleList<T> {
public:
  using typename DoubleList<T>::Node;

  void insertFront(T value) override;
  void insertBack(T value) override;

  void deleteFront() override;
  void deleteBack() override;
};

template class DoubleCyclingList<int>;