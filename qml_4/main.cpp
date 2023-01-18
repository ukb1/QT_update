#include "balltracking.h"
#include "rosnode.h"
#include "project_type.h"

int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);
    rclcpp::init(argc, argv);
    QQmlContext* context;
    QQmlApplicationEngine engine;

    BallTracking ballTrac;

    RosNode node;


    const QUrl url(QStringLiteral("qrc:/main.qml"));

    context = engine.rootContext();
    context->setContextProperty("_ballTrac", &ballTrac);
    context->setContextProperty("_rosNode", &node);

    engine.load(url);

    return app.exec();
}
