// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train(): countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *temp = new Car;
  temp->light = light;
  temp->prev = nullptr;
  temp->next = nullptr;
  if (first == nullptr) {
    first = temp;
  } else if (first->next == nullptr) {
    first->next = temp;
    temp->prev = first;
    first->prev = temp;
    temp->next = first;
  } else {
    first->prev->next = temp;
    temp->prev = first->prev;
    first->prev = temp;
    temp->next = first;
  }
}
int Train::getLength() {
  int count = 0;
  int i;
  countOp = 0;
  first->light = true;
  Car* temp = first;
  while (true) {
    countOp++;
    count++;
    temp = temp->next;
    if (temp->light) {
      temp->light = false;
      for (int j = count; j > 0; j--) {
        temp = temp->prev;
        countOp++;
      }
      if (!temp->light) {
        return count;
      }
    }
  }
  return count;
}

int Train::getOpCount() {
  return countOp;
}
