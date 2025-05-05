// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
  Train train;
  int count = 60; // кол-во вагонов

  while (count--)
    train.addCarriage(false);

  std::cout << train.getTotalLength() << std::endl;
  std::cout << train.getOperationCount() << std::endl;
  return 0;
}
