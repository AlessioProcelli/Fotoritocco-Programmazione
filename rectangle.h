#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "brush.h"


class Rectangle : public Shape
{
public:
    Rectangle();
    void virtual draw(QPixmap* matrix,int x,int y,Brush* brush);
    void virtual setStartCoordinates(int x, int y);
    QPoint virtual getStartCoordinates();
    float getArea();
private:
    float calculateArea(int x,int y);
    float area;
    int xStart;
    int yStart;
};

#endif // RECTANGLE_H
