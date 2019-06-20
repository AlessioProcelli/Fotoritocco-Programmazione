#ifndef VIEWINTERFACE_H
#define VIEWINTERFACE_H
#include "effectsinterface.h"

class ViewInterface{
public:
    virtual ~ViewInterface(){}
    void virtual effectPressed(EffectsInterface *effect)=0;
    void virtual shapePressed()=0;
    void virtual paintPressed()=0;
};

#endif // VIEWINTERFACE_H
