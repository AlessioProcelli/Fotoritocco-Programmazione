#include "view.h"
#include "ui_view.h"
#include "baseeffect.h"
#include <QString>
#include <QFileDialog>
#include <iostream>


View::View(Model* mod,Controller* cont,QWidget *parent) :QMainWindow(parent),ui(new Ui::View)
{

    ui->setupUi(this);
connect( ui->graphicsView, &GraphicsView::drawing,this, &View::draw);
    model=mod;
    controller=cont;
    model->addObserver(this);


}

View::~View()
{
    delete ui;

}

void View::effectPressed(EffectsInterface *effect){
    controller->effectPressed(effect);
}
void View::shapePressed(){

}
void View::paintPressed(){

}

void View::openFile(QString filename){
 controller->openFile(filename);


}

//Aggiora la view col puntatore alla scena corrente
void View::update(){

    scene.addPixmap(*model->getCurrentState());
    ui->graphicsView->setScene(&scene);
}



//apertura file
void View::on_actionOpen_triggered()
{
  QString filename =  QFileDialog::getOpenFileName(
            this,
            "Open Document",
            QDir::currentPath(),
            "All files (*.*) ;; Document files (*.doc *.rtf);; ");

   View::openFile(filename);

}
//effetto
void View::on_pushButton_clicked()
{
    BaseEffect effect;
    effect.setSharpening();

   View::effectPressed(&effect);
}

void View::on_pushButton_2_clicked()
{QString filename =  QFileDialog::getOpenFileName(
                this,
                "Open Document",
                QDir::currentPath(),
                "All files (*.*) ;; Document files (*.doc *.rtf);; ");

       View::openFile(filename);

}
void View::draw(int x,int y){

std::cout<<"ok"<<std::endl;
}
