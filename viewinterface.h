#ifndef VIEWINTERFACE_H
#define VIEWINTERFACE_H
#include "effectsinterface.h"
#include"shape.h"
#include <memory>

class ViewInterface{
public:
    virtual ~ViewInterface(){}
    void virtual effectPressed(std::shared_ptr<EffectsInterface>effect)=0;
    void virtual paintPressed()=0;
    void virtual undo()=0;
    void virtual redo()=0;
};

#endif // VIEWINTERFACE_H
