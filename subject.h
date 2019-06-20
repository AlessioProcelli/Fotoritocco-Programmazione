#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
class Subject{
public:
    virtual ~Subject(){}
    void virtual addObserver(Observer* o)=0;
    void virtual removeObserver(Observer* o)=0;
    void virtual notify()=0;
};

#endif // SUBJECT_H
