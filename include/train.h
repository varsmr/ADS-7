// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Car {
    bool hasLight;
    Car *next;
    Car *prev;
  };
  
  int operationCount;
  Car *head;

 public:
  Train();
  void addCar(bool hasLight);
  int getLength();
  int getOpCount();
  ~Train();
};

#endif  // INCLUDE_TRAIN_H_
