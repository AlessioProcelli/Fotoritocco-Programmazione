#include "triangle.h"
#include "line.h"

Triangle::Triangle()
{

}
void Triangle::setStartCoordinates(int x,int y){
    xStart=x;
    yStart=y;
}
QPoint Triangle::getStartCoordinates(){
    return QPoint(xStart,yStart);
}

void Triangle::draw(QPixmap* matrix, int x, int y, Brush *brush){
Line line;
line.setStartCoordinates(xStart,yStart);
line.draw(matrix,((x-xStart)/2)+xStart+0.3,y,brush);
line.setStartCoordinates(((x-xStart)/2)+0.3+xStart,y);
line.draw(matrix,x,yStart,brush);
if(x-xStart>0){
    for(int i=xStart;i<=x;i++){
        brush->draw(matrix,i,yStart);
    }
}
else{
    for(int i=x;i<=xStart;i++){
        brush->draw(matrix,i,yStart);
    }
}

}
float Triangle::calculateArea(int x, int y){
    int width=x-xStart;
    if(width<0)
        width*=-1;
    int height=y-yStart;
    if(height<0)
        height*=-1;
    return (width*height)/2;
}
