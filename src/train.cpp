// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {}

void Train::addCar(bool light) {
  Car *newCar = new Car(light);
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car *tail = first->prev;
    tail->next = newCar;
    newCar->prev = tail;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (!first) return 0;

  int length = 0;
  countOp = 0;
  Car *current = first;

  do {
    countOp++;
    if (current->light) {
      current->light = false;
      length++;
    }
    current = current->next;
  } while (current != first);

  return length;
}

int Train::getOpCount() const { 
  return countOp; 
}
