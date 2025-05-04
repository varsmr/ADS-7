// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
  Train train;

    train.addCarriage(false);
    train.addCarriage(true);
    
    std::cout << train.getTotalLength() << std::endl;
    std::cout << train.getStepCount() << std::endl;

    return 0;
}
