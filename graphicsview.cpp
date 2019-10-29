#include "graphicsview.h"
#include <QPointF>
#include <QMouseEvent>
#include <iostream>


GraphicsView::GraphicsView(QWidget* parent):QGraphicsView::QGraphicsView (parent)
{
this->show();
    setAlignment(Qt::AlignTop | Qt::AlignLeft);
    setBackgroundBrush(QColor(240,240,240));

}

void GraphicsView::mousePressEvent(QMouseEvent *event){

   emit  beginDrawing(event->x(),event->y());

}
void GraphicsView::mouseMoveEvent(QMouseEvent *event){
   emit  drawing(event->x(),event->y());
}
void GraphicsView::mouseReleaseEvent(QMouseEvent *event){

}
