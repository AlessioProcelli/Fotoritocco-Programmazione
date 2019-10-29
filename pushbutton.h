#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H
#include <QPushButton>


class PushButton: public QPushButton
{
     Q_OBJECT
public:
    PushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr);
    PushButton(const QString &text, QWidget *parent = nullptr);
    PushButton(QWidget *parent = nullptr);
    void style();
};

#endif // PUSHBUTTON_H
