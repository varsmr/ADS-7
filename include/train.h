// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Car {
    bool light;
    Car *next;
    Car *prev;

    explicit Car(bool isLightOn) : light(isLightOn), next(nullptr), prev(nullptr) {}
  };

  int operationCount;
  Car *head;

 public:
  Train();
  void addCar(bool lightStatus);
  int getLength();
  int getOpCount();
};

#endif  // INCLUDE_TRAIN_H_
