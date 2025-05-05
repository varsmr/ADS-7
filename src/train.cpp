// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : operationCount(0), head(nullptr) {}

void Train::addCar(bool hasLight) {
  Car* newCar = new Car{hasLight, nullptr, nullptr};

  if (head == nullptr) {
    head = newCar;
    head->next = head;
    head->prev = head;
    return;
  }

  Car* lastCar = head->prev;
  lastCar->next = newCar;
  newCar->prev = lastCar;
  newCar->next = head;
  head->prev = newCar;
}

int Train::getOpCount() {
  return operationCount;
}

int Train::getLength() {
  if (head == nullptr) return 0;
  int carCount = 0;
  Car* currentCar = head;

  do {
    carCount++;
    currentCar = currentCar->next;
    operationCount += 2;
  } while (currentCar != head);

  return carCount;
}

Train::~Train() {
  if (head == nullptr) return;

  Car* currentCar = head;
  Car* nextCar;

  do {
    nextCar = currentCar->next;
    delete currentCar;
    currentCar = nextCar;
  } while (currentCar != head);

  head = nullptr;
}
