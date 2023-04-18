//
// Created by x0lotl on 18.04.23.
//

#pragma once
#include "DoubleList.h"

class DoubleSingleList : public DoubleList {
public:
  ~DoubleSingleList() override;

  void insertFront(int value) override;
  void insertBack(int value) override;
  void deleteFront() override;
  void deleteBack() override;
};
