#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle()
{
xStart=0;
yStart=0;
}

void Rectangle::setStartCoordinates(int x, int y){
    xStart=x;
    yStart=y;
}
QPoint Rectangle::getStartCoordinates(){
    return QPoint(xStart,yStart);
}
void Rectangle::draw(QPixmap *matrix,int x,int y,Brush* brush){
if(xStart<x){
    for(int i=xStart;i<=x;i++){
        brush->draw(matrix,i,yStart);
        brush->draw(matrix,i,y);
    }
}
else{
    for(int i=x;i<=xStart;i++){
        brush->draw(matrix,i,yStart);
        brush->draw(matrix,i,y);
    }

}
if(yStart<y){
    for(int j=yStart;j<=y;j++){
        brush->draw(matrix,xStart,j);
        brush->draw(matrix,x,j);
    }
}
else{
    for(int j=y;j<=yStart;j++){
        brush->draw(matrix,xStart,j);
        brush->draw(matrix,x,j);
    }
}
area=calculateArea(x,y);
}


float Rectangle::calculateArea(int x, int y){
    int width=x-xStart;
    if(width<0){
        width*=-1;
        width+=1;}
    else{
        width+=1;
    }
    int height=y-yStart;
    if(height<0){
        height*=-1;
        height+=1;}
    else{
        height+=1;
    }
    return width*height;

}
float Rectangle::getArea()
{
    return area;
}
