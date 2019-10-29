#include "model.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <iostream>


Model::Model()
{
QPixmap frontImage(widthGraphicsView,heightGraphicsView);
frontImage.fill(Qt::white);
addState(frontImage);
}

void Model::addState(QPixmap img){

    state.push_front(img);

    Model::notify();
}

void Model::removeState(){
    if(state.size()>1){
        deletedStated.push_front(state.front());
        state.pop_front();
    Model::notify();}
}


void Model::cleanDeletedState(){
    deletedStated.clear();
}
void Model::removeDeletedState(){
    deletedStated.pop_front();
}
void Model::setNextDeletedStated(QPixmap pix){
    nextDeletedStated=pix;
}
QPixmap Model::getNextDeletedStated(){
    return nextDeletedStated;
}
QPixmap Model::getCurrentDeletedState(){

    return deletedStated.front();
}



void Model::restoreState(){
    if(!deletedStated.empty()){
        addState(deletedStated.front());
        deletedStated.pop_front();
    }
}

QPixmap* Model::getCurrentState(){
    return &state.front();
}


//implementazione Observer
void Model::addObserver(Observer* o){
    observers.push_front(o);


}

void Model::removeObserver(Observer* o){
   observers.remove(o);
}
void Model::notify(){
  for(auto observer:observers){
        observer->update();}
}

void Model::setDrawing(bool allowed){
    allowDrawing=allowed;
}
bool Model::getDrawing(){
    return allowDrawing;
}

void Model::setShape(bool allowed){
    allowShape=allowed;
}

bool Model::getShape(){
    return allowShape;}


