#ifndef BRUSH_H
#define BRUSH_H
#include <QPixmap>
#include <QColor>


class Brush
{
public:
    Brush();
   void draw(QPixmap& matrix,int x,int y);
private:
   QColor color;
   int tickness;
};

#endif // BRUSH_H
