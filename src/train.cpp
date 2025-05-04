// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : stepCount(0), headCarriage(nullptr) {}

void Train::addCarriage(bool lightStatus) {
    Carriage* newCarriage = new Carriage{lightStatus, nullptr, nullptr};

    if (headCarriage == nullptr) {
        headCarriage = newCarriage;
        headCarriage->nextCarriage = headCarriage;
        headCarriage->previousCarriage = headCarriage;
    } else {
        Carriage* lastCarriage = headCarriage->previousCarriage;
        lastCarriage->nextCarriage = newCarriage;
        newCarriage->previousCarriage = lastCarriage;
        newCarriage->nextCarriage = headCarriage;
        headCarriage->previousCarriage = newCarriage;
    }
}

int Train::getStepCount() {
    return stepCount;
}

int Train::getTotalLength() {
    stepCount = 0; 
    Carriage* currentCarriage = headCarriage;

    if (!currentCarriage) return 0; 

    unsigned int totalCarriages = 0; 

    do {
        if (!currentCarriage->lightStatus) {
            currentCarriage->lightStatus = true;
            totalCarriages++;
        }
        
        currentCarriage = currentCarriage->nextCarriage;
        stepCount += 2;

    } while (currentCarriage != headCarriage); 

    return totalCarriages;
}

Train::~Train() {
    if (!headCarriage) return; 

    Carriage* currentCarriage = headCarriage;
    do {
        Carriage* nextCarriage = currentCarriage->nextCarriage;
        delete currentCarriage;
        currentCarriage = nextCarriage;
    } while (currentCarriage != headCarriage); 

    headCarriage = nullptr; 
}
