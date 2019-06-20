#ifndef BASEEFFECT_H
#define BASEEFFECT_H
#include "effectsinterface.h"
#include "QColor"
#include "QImage"


class BaseEffect:public EffectsInterface
{
public:
    BaseEffect();
    float getMatrixEffect();
    void  apply(QPixmap & originalmatrix);
    //effetti
    void setBlur();//setta l'effetto sfocatura
    void setEdgeDetection();
    void setSharpening();


private:


    void processing (QImage & img,int height, int width);
    int divisore;
    float matrixeffect[3][3];
};

#endif // BASEEFFECT_H
