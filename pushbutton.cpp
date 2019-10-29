#include "pushbutton.h"

PushButton::PushButton(const QIcon &icon, const QString &text, QWidget *parent ):QPushButton::QPushButton(icon,text,parent=nullptr)
{
 style();
}

PushButton::PushButton(const QString &text, QWidget *parent):QPushButton::QPushButton(text,parent=nullptr){
    style();
}

PushButton::PushButton(QWidget *parent):QPushButton::QPushButton(parent=nullptr){
    style();
}

void PushButton::style(){
    setStyleSheet("background-color:rgb(255,255,255);opacity:0.8");
}
