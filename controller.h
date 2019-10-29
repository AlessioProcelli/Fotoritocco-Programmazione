#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "viewinterface.h"
#include "effectsinterface.h"
#include "model.h"
#include "shape.h"
#include "directions.h"
#include <memory>

class Controller
{
public:
    Controller(Model* mod);
    void effectPressed(std::shared_ptr<EffectsInterface> effect);
    void shapePressed();
    void paintPressed();
    void drawShape(int x, int y, Brush* brush,std::shared_ptr<Shape> shape);
    void draw(int x, int y, Brush* brush);
    void beginDrawing(int x, int y, Brush *brush);
    void beginShape(int x, int y, std::shared_ptr<Shape> shape );
    void openFile(QString filename);
    void saveFile(QString filename);
    void undo();
    void redo();
    void enlargeResize(QPixmap* matrix,int scale);

    void rotate(Direction direction);
private:
    QImage turnLeft(QImage &matrix);
    QImage turnRight(QImage &matrix);
    void reverse(QImage &matrix);
    bool isequal(QPixmap a,QPixmap b);
    Model* model;
};

#endif // CONTROLLER_H
