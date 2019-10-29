
#include "controller.h"
#include <QImage>
#include <QImageReader>
#include <QGraphicsScene>
#include <iostream>

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

void Controller::effectPressed(std::shared_ptr<EffectsInterface>effect){
    QPixmap* item =model->getCurrentState();
    effect->apply(item);
    model->addState(*item);

}
void Controller::shapePressed(){
    model->setShape(true);
    model->setDrawing(false);
}

void Controller::paintPressed(){
    model->setDrawing(true);
    model->setShape(false);

}
void Controller::drawShape(int x, int y, Brush *brush, std::shared_ptr<Shape>shape){
    model->removeState();
    model->addState(*(model->getCurrentState()));
    QPixmap* pixmap=model->getCurrentState();
    *pixmap=pixmap->scaled(pixmap->width()/2,pixmap->height()/2,Qt::KeepAspectRatio);
    int tickness=brush->getTickness();
    if(tickness!=1){
        brush->setTickness(tickness/2);
    }
    shape->draw(pixmap,x/2,y/2,brush);
    brush->setTickness(tickness);
    *pixmap=pixmap->scaled(pixmap->width()*2,pixmap->height()*2,Qt::KeepAspectRatio);
    model->notify();
    }


void Controller::draw(int x, int y, Brush *brush){
    brush->draw(model->getCurrentState(),x,y);
    model->notify();
   }

void Controller::beginDrawing(int x, int y, Brush *brush){
    model->addState(*(model->getCurrentState()));
    brush->draw(model->getCurrentState(),x,y);
}
void Controller::beginShape(int x, int y ,std::shared_ptr<Shape>shape){
    model->addState(*(model->getCurrentState()));
    shape->setStartCoordinates(x/2,y/2);

}


void Controller::undo(){
    if(!isequal(model->getNextDeletedStated(),*(model->getCurrentState()))){
            model->cleanDeletedState();

    }
    model->removeState();
    model->setNextDeletedStated(*(model->getCurrentState()));
}

void Controller::redo(){
    if(Controller::isequal(*(model->getCurrentState()),model->getNextDeletedStated())){
    model->restoreState();
    model->setNextDeletedStated(*(model->getCurrentState()));
    }
    else{
        model->cleanDeletedState();
    }
}
bool Controller::isequal(QPixmap a, QPixmap b){

    if(a.size()!=b.size()){
        return false;
    }
    else{
        QImage img=a.toImage();
        QImage img2=b.toImage();
        for (int i=0;i<a.size().width();i++) {
            for(int j=0;j<a.size().height();j++){
                if(img.pixel(i,j)!=img2.pixel(i,j))
                    return false;
            }
        }
        return true;
    }
}



void Controller::enlargeResize(QPixmap *matrix, int scale){
    *matrix=matrix->scaled((matrix->width()/(scale-1))*scale,(matrix->height()/(scale-1))*scale, Qt::KeepAspectRatio);

}

void Controller::saveFile(QString fileName){

    QImage file=(*model->getCurrentState()).toImage();
    file.save(fileName+".png","PNG");
}

void Controller::rotate(Direction direction){
    QPixmap matrix=*model->getCurrentState();
    QImage img=matrix.toImage();
    QImage rotateImg;
    QImage swap;

switch(direction){
case Direction::Left:
    rotateImg=turnLeft(img);break;


case Direction::Right:
    rotateImg=turnRight(img);break;


case Direction::Reverse:
    reverse(img);
    rotateImg=img;
     break;
}

    matrix.convertFromImage(rotateImg);
    model->addState(matrix);
}

QImage Controller::turnRight(QImage &matrix){
    int height=matrix.height();
    int width=matrix.width();
    QImage rotateImg(height,width,QImage::Format_RGB32);
    for(int j=height-1,originalY=0;j>=0;j--,originalY++){
        for(int i=0;i<width;i++){
            rotateImg.setPixel(j,i,matrix.pixel(i,originalY));
         }
     }
    return rotateImg;
}

QImage Controller::turnLeft(QImage &matrix){
    int height=matrix.height();
    int width=matrix.width();
    QImage rotateImg(height,width,QImage::Format_RGB32);
    for(int j=0;j<height;j++){
        for(int i=width-1,originalJ=0;i>=0;i--,originalJ++){
            rotateImg.setPixel(j,i,matrix.pixel(originalJ,j));
         }
    }
    return rotateImg;
}

void Controller::reverse(QImage &matrix){
    int height=matrix.height();
    int width=matrix.width();
    QImage rotateImg(width,height,QImage::Format_RGB32);
     for(int i=0;i<width;i++){
         for(int j=0;j<height;j++){
             rotateImg.setPixel(width-1-i,height-1-j,matrix.pixel(i,j));
          }
     }
     matrix=rotateImg;
}
