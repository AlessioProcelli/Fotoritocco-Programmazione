#include "view.h"
#include "ui_view.h"
#include "baseeffect.h"
#include "graphicsview.h"
#include <QString>
#include <QFileDialog>
#include <iostream>
#include <QObject>
#include <QColorDialog>



View::View(Model* mod,Controller* cont,QWidget *parent) :QMainWindow(parent),ui(new Ui::View)
{

    ui->setupUi(this);
QObject::connect( ui->graphicsView,&GraphicsView::drawing,this,&View::on_draw);
QObject::connect( ui->graphicsView,&GraphicsView::beginDrawing,this,&View::begin_draw);

    model=mod;
    controller=cont;
    model->addObserver(this);

    brush.setTickness(10);
    brush.setColor(0,0,0);

currentColor= QPixmap(ui->currentColor->width(),ui->currentColor->height());
currentColor.fill(QColor(0,0,0));
ui->currentColor->setPixmap(currentColor);

}

View::~View()
{
    delete ui;

}

void View::effectPressed(std::shared_ptr<EffectsInterface> effect){
    controller->effectPressed(effect);
}

void View::paintPressed(){
 controller->paintPressed();
}

void View::openFile(QString filename){
 controller->openFile(filename);


}

//Aggiora la view col puntatore alla scena corrente
void View::update(){

    QPixmap* matrix=model->getCurrentState();
    resize(matrix);
    scene=std::make_shared<QGraphicsScene>(new QGraphicsScene(matrix->width(),matrix->height(),0,0));
    scene->addPixmap(*model->getCurrentState());
    ui->graphicsView->setScene(scene.get());
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
void View::on_blur_clicked()
{
  std::shared_ptr<EffectsInterface> effect=std::make_shared<BaseEffect>(BaseEffect::effect::Blur);
   View::effectPressed(effect);
}

void View::on_paint_clicked(){
 View::paintPressed();

}



//disegno
void View::on_draw(int x,int y){
    if(model->getDrawing()){
        controller->draw(x,y,&brush);
    }
    if(model->getShape()){
        controller->drawShape(x,y,&brush,shape);
    }
}

void View::begin_draw(int x, int y){
     if(model->getDrawing()){
     controller->beginDrawing(x,y,&brush);
     }
     if(model->getShape()){
       controller->beginShape(x,y,shape);
     }
}

void View::undo(){
    controller->undo();
}
void View::redo(){
    controller->redo();
}


void View::on_line_clicked()
{
    shape=std::make_shared<Line>(Line());
    controller->shapePressed();
}



void View::resize(QPixmap *matrix){
    if(matrix->width()*2<widthGraphicsView && matrix->height()*2<heightGraphicsView){
        int j=2;
        while(matrix->width()<widthGraphicsView && matrix->height()<heightGraphicsView){
         controller->enlargeResize(matrix,j);
         j++;
        }
    }
}

void View::on_edgeDetection_clicked()
{
    std::shared_ptr<EffectsInterface> effect=std::make_shared<BaseEffect> (BaseEffect::effect::EdgeDetection);
   View::effectPressed(effect);
}

void View::on_sharpening_clicked()
{
    std::shared_ptr<EffectsInterface> effect=std::make_shared<BaseEffect>(BaseEffect::effect::Sharpening);
   View::effectPressed(effect);
}


void View::on_contrast_clicked()
{   std::shared_ptr<EffectsInterface> effect=std::make_shared<BaseEffect>(BaseEffect::effect::Contrast);
     View::effectPressed(effect);

}

void View::saveFile(QString fileName){
    controller->saveFile(fileName);

}



void View::changeColor(int red, int green, int blue){
    currentColor.fill(QColor(red,blue,green));
    ui->currentColor->setPixmap(currentColor);
    brush.setColor(red,green,blue);
}



void View::on_red_clicked()
{
   changeColor(255,0,0);

}


void View::on_green_clicked()
{
    changeColor(0,0,255);
}

void View::on_blue_clicked()
{
    changeColor(0,255,0);
}

void View::on_black_clicked()
{
    changeColor(0,0,0);
}

void View::on_white_clicked()
{
    changeColor(255,255,255);
}

void View::on_orange_clicked()
{
    changeColor(255,39,127);
}


void View::on_gray_clicked()
{
    changeColor(195,195,195);
}

void View::on_pink_clicked()
{
    changeColor(255,198,170);
}

void View::on_brown_clicked()
{
    changeColor(185,87,122);
}

void View::on_thickness_valueChanged(int arg1)
{
    brush.setTickness(arg1);
}

void View::on_chooseColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::black, this );
    if(color.isValid()){
     changeColor(color.red(),color.blue(),color.green());
    }
}



void View::on_actionUndo_triggered()
{
    View::undo();
}

void View::on_actionRedo_triggered()
{
    View::redo();
}



void View::on_rightRotate_clicked()
{
   controller->rotate(Direction::Right);
}



void View::on_leftRotate_clicked()
{
    controller->rotate(Direction::Left);
}

void View::on_reverse_clicked()
{
    controller->rotate(Direction::Reverse);
}



void View::on_rectangle_clicked()
{

    shape=std::make_shared<Rectangle>(Rectangle());
    controller->shapePressed();
}

void View::on_triangle_clicked()
{
    shape=std::make_shared<Triangle>(Triangle());
    controller->shapePressed();
}

void View::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(0,QObject::tr("Salva"), QDir::homePath());
    View::saveFile(fileName);
}
