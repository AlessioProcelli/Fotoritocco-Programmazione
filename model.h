#ifndef MODEL_H
#define MODEL_H
#include <QList>
#include <QGraphicsScene>
#include "subject.h"




class Model:Subject
{

public:
    Model();
    void addState(QPixmap  lastview);//aggiungere il nuovo stato alla lista
    void removeState();//rimuove lo stato corrente (operazione di annulla)
    QPixmap* getCurrentState();//rende la vista corrente

    //soggetto observer
    void  addObserver(Observer* o);
    void  removeObserver(Observer* o);
    void  notify();
    int get();




private:
    QPixmap currentState;
    std::list<QPixmap> state;// lo stato di tutte le cose fatte
    std::list<Observer*> observers;// lista osservatori
    Observer* prova;


};

#endif // MODEL_H
