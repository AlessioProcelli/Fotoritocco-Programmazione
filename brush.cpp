#include "brush.h"
#include <QImage>
#include <iostream>

Brush::Brush()
{
tickness=5;
color.setRgb(0,0,0);
}
Brush::Brush(int tick,QRgb color){
  tickness=tick;
  this->color.setRgb(color);
}
void Brush::setColor(int red,int blue, int green){
    color.setRgb(red,green,blue);
}
void Brush::setTickness(int t){
    tickness=t;
}

void Brush::draw(QPixmap* matrix,int x, int y){
    QImage img(matrix->toImage());
    int halfSide;
    if(tickness>1){
    halfSide=((tickness-1)/2);}
    else{
        halfSide=0;
    }


   for(int i=0;i<tickness;i++){
       for(int j=0;j<tickness;j++){
            if(x-halfSide+i<img.width() && x-halfSide+i>=0){
            if(y-halfSide+j<img.height() && y-halfSide+j>=0){

                img.setPixel(x-halfSide+i,y-halfSide+j,color.rgba());
        }}

    }}
matrix->convertFromImage(img);

}
int Brush::getTickness(){
    return tickness;
}

QColor Brush::getColor(){
    return  color;
}
