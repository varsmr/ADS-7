// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : operationCount(0), head(nullptr) {}

void Train::addCar(bool light) {
  Carriage* newCarriage = new Carriage{light, nullptr, nullptr};
  
  if (head == nullptr) {
    head = newCarriage;
    head->next = head;
    head->prev = head;
  } else {
    Carriage* tail = head->prev;
    tail->next = newCarriage;
    newCarriage->prev = tail;
    newCarriage->next = head;
    head->prev = newCarriage;
  }
}

int Train::getOpCount() {
  return operationCount;
}

int Train::getLength() {
  if (head == nullptr) return 0;
  
  int Train::getLength() {
  if (head == nullptr) return 0;

  int countCarriages = 0;
  Carriage* current = head;

  do {
    if (!current->light) {
      countCarriages++;
    }
    current = current->next;
    operationCount++;
  } while (current != head);
  return countCarriages;
}

Train::~Train() {
  if (head == nullptr) return;
  
  Carriage* current = head;
  Carriage* nextCarriage;

  do {
    nextCarriage = current->next;
    delete current;
    current = nextCarriage;
  } while (current != head);
  
  head = nullptr;
}
