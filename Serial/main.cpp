#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


//#include <QSerialPort>
//#include <QDebug>

//int main(int argc, char *argv[])
//{
//    QSerialPort serial;
//    serial.setPortName("COM7"); // seri portun adını belirleyin
//    serial.setBaudRate(115200); // baud rate'i belirleyin
//    serial.open(QIODevice::ReadOnly); // okuma modunda açın

//    while (true) {
//        qDebug() <
//        if (serial.waitForReadyRead(10)) { // veri okumaya hazır olduğunda devam et
//            QByteArray data = serial.read(8); // 1 byte veri oku
//            if (data.size() == 1) { // veri geldiyse
//                uint8_t gelen_veri = static_cast<uint8_t>(data.at(0));
//                qDebug() << gelen_veri << "----"; // uint8_t türünde veriyi ekrana yaz
//            }
//        }
//    }
//    return 0;
//}
