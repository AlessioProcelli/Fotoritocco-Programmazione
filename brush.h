#ifndef BRUSH_H
#define BRUSH_H
#include <QPixmap>
#include <QColor>


class Brush
{
public:
    Brush();
    Brush(int tikness,QRgb color);
   void draw(QPixmap* matrix,int x,int y);

   void setTickness(int t);
   void setColor(int red, int green ,int blue);
   int getTickness();
   QColor getColor();

private:
   QColor color;
   int tickness;
};

#endif // BRUSH_H
