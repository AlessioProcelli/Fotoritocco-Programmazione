#ifndef MODEL_H
#define MODEL_H
#include <QList>
#include <QGraphicsScene>
#include "subject.h"
#include "brush.h"
#include "directions.h"


const int widthGraphicsView=832;
const int heightGraphicsView=612;

class Model:Subject
{

public:
    Model();
    void addState(QPixmap  lastview);//aggiungere il nuovo stato alla lista
    void removeState();//rimuove lo stato corrente (operazione di annulla)
    void cleanDeletedState();
    void removeDeletedState();
    QPixmap getCurrentDeletedState();
    QPixmap getNextDeletedStated();



    void setNextDeletedStated(QPixmap pix);
    void restoreState();
    QPixmap* getCurrentState();//rende la vista corrente

    //soggetto observer
    void  virtual addObserver(Observer* o);
    void  virtual removeObserver(Observer* o);
    void virtual notify();


    //verifica disegno autorizzato
    void setDrawing(bool allowed);
    bool getDrawing();
    void setShape(bool allowed);
    bool getShape();




private:
    std::list<QPixmap> state;// lo stato di tutte le cose fatte
    std::list<QPixmap> deletedStated;//matiene gli stati eliminati
    QPixmap nextDeletedStated; //mantiene lo stato che si aspetta di trovare per rendo o undo
    std::list<Observer*> observers;// lista osservatori
    bool allowDrawing=false; //verificare se può disegnare
    bool allowShape=false;


};

#endif // MODEL_H
