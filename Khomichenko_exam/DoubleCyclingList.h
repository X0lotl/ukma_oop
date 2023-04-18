//
// Created by x0lotl on 18.04.23.
//

#pragma once

#include "DoubleList.h"

class DoubleCyclingList : public DoubleList {
public:
  void insertFront(int value) override;
  void insertBack(int value) override;

  void deleteFront() override;
  void deleteBack() override;
};