// Copyright 2021 NNTU-CS
#include "train.h"
#include <cstdlib>

Train::Train() : countOp(0), head(nullptr) {}

void Train::addCar(bool lightOn) {
    Car* newCar = new Car{lightOn, nullptr, nullptr};

    if (!head) {
        head = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    } else {
        Car* lastCar = head->prev;
        newCar->next = head;
        newCar->prev = lastCar;
        lastCar->next = newCar;
        head->prev = newCar;
        head = newCar;
    }
}

int Train::getLength() {
    if (!head) return 0;
    if (head->next == head) return 1;

    countOp = 0;
    Car* currentCar = head;
    int size = 1;

    if (!currentCar->light) {
        currentCar->light = true;
    }

    currentCar = currentCar->next;
    countOp += 2;

    while (!currentCar->light) {
        currentCar = currentCar->next;
        countOp += 2;
        size++;
    }
    currentCar->light = false;

    if (!head->light) {
        return size;
    }

    while (true) {
        currentCar = head;
        size = 1;

        if (!currentCar->light) {
            currentCar->light = true;
        }

        currentCar = currentCar->next;
        countOp += 2;

        while (!currentCar->light) {
            currentCar = currentCar->next;
            countOp += 2;
            size++;
        }
        currentCar->light = false;

        if (!head->light) {
            return size;
        }
    }
}
int Train::getOpCount() {
    return countOp;
}

Train::~Train() {
    if (!head) return;

    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    Car* currentCar = head->next;
    while (currentCar != head) {
        Car* temp = currentCar;
        currentCar = currentCar->next;
        delete temp;
    }

    delete head;
    head = nullptr;
}
