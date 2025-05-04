// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Carriage {
    bool light;
    Carriage *next;
    Carriage *prev;
  };
  
  int operationCount;
  Carriage *head;

 public:
  Train();
  void addCarriage(bool light);
  int getTotalLength();
  int getOperationCount();
  ~Train();
};

#endif  // INCLUDE_TRAIN_H_

