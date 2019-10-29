#ifndef LINE_H
#define LINE_H
#include"shape.h"

class Line:public Shape
{
public:
    Line();
    void virtual draw(QPixmap* matrix,int x,int y,Brush* brush);
    void virtual  setStartCoordinates(int x, int y);
    QPoint virtual getStartCoordinates();

private:
    float computesAngularCoefficient(float y2,float y1,float x2, float x1);
    int xStart;
    int yStart;
};

#endif // LINE_H
