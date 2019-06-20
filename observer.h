#ifndef OBSERVER_H
#define OBSERVER_H


class Observer{
public:
    virtual ~Observer(){}
    void virtual update()=0;
};

#endif // OBSERVER_H
