#include "graphicsview.h"
#include <QPointF>
#include <QMouseEvent>
#include <iostream>

GraphicsView::GraphicsView(QWidget* parent):QGraphicsView::QGraphicsView (parent)
{
this->show();
}

void GraphicsView::mousePressEvent(QMouseEvent *event){


emit drawing(event->localPos().x(),event->localPos().y());
}
