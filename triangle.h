#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"


class Triangle : public Shape
{
public:
    Triangle();
    void virtual draw(QPixmap* matrix,int x,int y,Brush* brush);
    void virtual  setStartCoordinates(int x, int y);
    QPoint virtual getStartCoordinates();
private:
    float calculateArea(int x,int y);
    float area;
    int xStart;
    int yStart;
};

#endif // TRIANGLE_H
