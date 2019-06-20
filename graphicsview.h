#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <QGraphicsView>




class GraphicsView: public QGraphicsView
{
public:
    GraphicsView(QWidget* w);
    void mousePressEvent(QMouseEvent *event);
signals:
    void drawing(int x,int y);
};
#endif // GRAPHICSVIEW_H
