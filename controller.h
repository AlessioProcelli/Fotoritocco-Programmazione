#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "viewinterface.h"
#include "effectsinterface.h"
#include "model.h"

class Controller:ViewInterface
{
public:
    Controller(Model* mod);
    void effectPressed(EffectsInterface *effect);
    void shapePressed();
    void paintPressed();
    void openFile(QString filename);

private:
    Model* model;
};

#endif // CONTROLLER_H
