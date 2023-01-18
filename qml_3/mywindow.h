#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "project_type.h"

class myWindow: public QObject
{
    Q_OBJECT
public:
   explicit  myWindow();
//    int getValue() const;
    Q_INVOKABLE void setValue(int v);
private:
    int value;

};

#endif // MYWINDOW_H
