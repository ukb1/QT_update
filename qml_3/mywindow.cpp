#include "mywindow.h"

myWindow::myWindow( )
{
    value = 10;

}


//int  myWindow::getValue() const
//{
//    return value;
//}

void myWindow::setValue(int v){
    qDebug() << value;
    value = v;
}
