

#include <QMainWindow>
#include <QGraphicsView>
#include "viewinterface.h"
#include "effectsinterface.h"
#include "controller.h"
#include "observer.h"
#include "model.h"
#include "rectangle.h"
#include "shape.h"
#include "line.h"
#include "triangle.h"




namespace Ui {
class View;
}

class View : public QMainWindow,ViewInterface,Observer
{
    Q_OBJECT

public:
    //metodi dell'interfaccia
    void virtual effectPressed(std::shared_ptr<EffectsInterface> effect);
    void virtual paintPressed();
    void openFile(QString file);
    void saveFile(QString file);
    void virtual update();
    void virtual undo();
    void virtual redo();
    void resize(QPixmap* matrix);
    void changeColor(int red,int green,int blue);

    explicit View(Model* mod,Controller* cont,QWidget *parent = nullptr);
    ~View();



private slots:
    void on_actionOpen_triggered();

    void on_draw(int x,int y);
    void begin_draw(int x, int y);
    void on_blur_clicked();
    void on_paint_clicked();
    void on_line_clicked();
    void on_edgeDetection_clicked();
    void on_sharpening_clicked();
    void on_contrast_clicked();
    void on_red_clicked();
    void on_green_clicked();
    void on_blue_clicked();
    void on_black_clicked();
    void on_white_clicked();
    void on_orange_clicked();
    void on_gray_clicked();
    void on_pink_clicked();
    void on_brown_clicked();
    void on_thickness_valueChanged(int arg1);
    void on_chooseColor_clicked();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_rightRotate_clicked();
    void on_leftRotate_clicked();
    void on_reverse_clicked();
    void on_rectangle_clicked();
    void on_triangle_clicked();
    void on_actionSave_triggered();

private:

    Ui::View *ui;
    Controller* controller;
    Model* model;
    std::shared_ptr<QGraphicsScene> scene;
    Brush brush;
    std::shared_ptr<Shape> shape;
    QPixmap currentColor;

};


