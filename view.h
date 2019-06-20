

#include <QMainWindow>
#include <QGraphicsView>
#include "viewinterface.h"
#include "effectsinterface.h"
#include "controller.h"
#include "observer.h"
#include "model.h"



namespace Ui {
class View;
}

class View : public QMainWindow,ViewInterface,Observer
{
    Q_OBJECT

public:
    //metodi dell'interfaccia
    void effectPressed(EffectsInterface* effect);
    void shapePressed();
    void paintPressed();
    void openFile(QString file);
    void update();

    explicit View(Model* mod,Controller* cont,QWidget *parent = nullptr);
    ~View();

public slots:
    void draw(int x,int y);
private slots:
    void on_actionOpen_triggered();



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::View *ui;
    Controller* controller;
    Model* model;
    QGraphicsScene scene;

};


