#ifndef BASEEFFECT_H
#define BASEEFFECT_H
#include "effectsinterface.h"
#include "QColor"
#include "QImage"


class BaseEffect:public EffectsInterface
{
public:
    enum class effect{Blur,
                      Sharpening,
                      EdgeDetection,
                      Contrast
                     };
    BaseEffect(enum effect e);
    void virtual apply(QPixmap* originalmatrix);
    //effetti


private:


    void processing (QImage & img,int height, int width);
    void processingBlur (QImage* img,int height, int width);
    int divisore;
    float **matrixeffect;
};

#endif // BASEEFFECT_H
