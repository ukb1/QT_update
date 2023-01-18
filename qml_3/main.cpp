<<<<<<< HEAD

#include "user.h"
#include "balltracking.h"
// #include "joycontrole.h"
=======
#include <QGuiApplication>
#include <QQmlApplicationEngine>

>>>>>>> origin/main

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
<<<<<<< HEAD
    QQmlContext* context;
    QQmlApplicationEngine engine;

//    qmlRegisterUncreatableType<User>("User data", 1,0,"User","Acces to Role enum names");
    User EMS("EMS");


    BallTracking ballTrac;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    // qmlRegisterType<JoyControle>("JoyLibrary", 1, 0, "JoyControle");

    context = engine.rootContext();
    context->setContextProperty("_user", &EMS);
    context->setContextProperty("_ballTrac", &ballTrac);

    context->setContextProperty("_colorXRTC", QColor(XRTC_COLOR));
    context->setContextProperty("_colorUDRL", QColor(UDRL_COLOR));
    context->setContextProperty("_recXRTC",   QSize(REC_XRTC_WIDTH,REC_XRTC_HEIGHT));
    context->setContextProperty("_recUDRL",   QSize(REC_UDRL_WIDTH, REC_UDRL_HEIGHT));
    
    engine.load(url);

    QObject* myQmlObject = engine.rootObjects().first();
    QQmlProperty property(myQmlObject, "right_control_x");
    int value = property.read().toInt();
    qDebug() << value;

=======

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

>>>>>>> origin/main
    return app.exec();
}
