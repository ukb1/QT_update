#include "window.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // window w(argc, argv);
    window w;
    w.show();
    return a.exec();
}
