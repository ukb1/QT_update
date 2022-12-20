#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString str = "ilk konsol app";
    qDebug("hello world");
    qDebug() << str;
    return a.exec();
}
