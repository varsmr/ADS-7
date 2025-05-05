// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : operationCount(0), head(nullptr) {}

void Train::addCar(bool lightStatus) {
  Car *newCar = new Car(lightStatus);
  if (!head) {
    head = newCar;
    head->next = head;
    head->prev = head;
  } else {
    Car *tail = head->prev;
    tail->next = newCar;
    newCar->prev = tail;
    newCar->next = head;
    head->prev = newCar;
  }
}

int Train::getLength() {
  if (!head) return 0;

  head->light = true;
  Car *current = head->next;
  int length = 0;

  while (true) {
    length = 1;
    operationCount++;

    while (!current->light) {
      current = current->next;
      operationCount++;
      length++;
    }

    current->light = false;

    for (int i = 0; i < length; i++) {
      current = current->prev;
      operationCount++;
    }
    if (!current->light) {
      return length;
    }

    current = current->next;
  }
}

int Train::getOpCount() { return operationCount; }

