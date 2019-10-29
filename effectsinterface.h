#ifndef EFFECTSINTERFACE_H
#define EFFECTSINTERFACE_H
#include "QColor"
#include <QPixmap>

class EffectsInterface
{
public:
    virtual ~EffectsInterface(){}
    void virtual apply(QPixmap* pixmap)=0;
};

#endif // EFFECTSINTERFACE_H
