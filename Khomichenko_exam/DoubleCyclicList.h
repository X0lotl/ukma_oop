//
// Created by x0lotl on 18.04.23.
//

#pragma once

#include "DoubleList.h"
#include "City.h"

template <typename T>
class DoubleCyclicList : public DoubleList<T> {
public:
  using typename DoubleList<T>::Node;

  void insertFront(T value) override;
  void insertBack(T value) override;

  void deleteFront() override;
  void deleteBack() override;

  const T &get(int index) const;

  void insert(const T &data, int index);

  void remove(int index);

  DoubleCyclicList &operator=(const DoubleCyclicList &other);
};

template class DoubleCyclicList<int>;
template class DoubleCyclicList<City>;