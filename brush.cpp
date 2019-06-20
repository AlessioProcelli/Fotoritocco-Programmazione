#include "brush.h"
#include <QImage>

Brush::Brush()
{

}
void Brush::draw(QPixmap& matrix,int x, int y){
    QImage img(matrix.toImage());
    img.setPixelColor(x,y,color);
    for(int i=1;i<=(tickness-1)/2;i++){
        if(y+i<img.height()){
            img.setPixelColor(x,y+i,color);
        }
        if(y-i>0){
            img.setPixelColor(x,y-i,color);
        }
    }

}
