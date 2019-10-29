#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <QGraphicsView>
#include <QObject>




class GraphicsView: public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(QWidget* w);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
signals:
     Q_SIGNAL void beginDrawing(int x, int y);
     Q_SIGNAL void drawing(int x,int y);
};
#endif // GRAPHICSVIEW_H
