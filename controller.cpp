#include "controller.h"
#include <QImage>
#include <QImageReader>
#include <QGraphicsScene>

Controller::Controller(Model* mod)
{
model=mod;
}


void Controller::openFile(QString filename){

    QImage  image (filename);
    QPixmap pixmap;
    pixmap.convertFromImage(image);
    model->addState(pixmap);

}

void Controller::effectPressed(EffectsInterface *effect){
    QPixmap item =*(model->getCurrentState());
    effect->apply(item);
    model->addState(item);

}
void Controller::shapePressed(){}

void Controller::paintPressed(){}
