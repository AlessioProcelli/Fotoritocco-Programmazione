#include "model.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <iostream>


Model::Model()
{

}

void Model::addState(QPixmap img){

    state.push_front(img);

    Model::notify();
}

void Model::removeState(){
    if(!state.empty())
        state.pop_front();
    notify();
}
//ricordarsi i controlli lista vuota e prima pagina bianca!
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
