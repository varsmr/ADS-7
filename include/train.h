// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
private:
    struct Carriage {
        bool lightStatus;
        Carriage *nextCarriage;
        Carriage *previousCarriage;
    };
    
    int stepCount;
    Carriage *headCarriage;

public:
    Train();
    void addCarriage(bool lightStatus);
    int getTotalLength();
    int getStepCount();
    ~Train();
};

#endif  // INCLUDE_TRAIN_H_
