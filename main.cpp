#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "modelcontroller.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    ModelController obj;
    obj.requestWeatherData("hei", "pådeg");//har bare lagt inn noen random strings siden funksjonen krever det


    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/Weatherapp_innlevering/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
