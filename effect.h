#ifndef EFFECT_H
#define EFFECT_H

#include <QObject>
#include <QWidget>

class Effect : public QWidget
{
    Q_OBJECT
public:
    explicit Effect(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // EFFECT_H
