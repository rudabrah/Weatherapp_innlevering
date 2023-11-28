#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "modelcontroller.h"
#include "dayinfo.h"
#include "weatherinfo.h"
#include "currentweather.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    ModelController obj;
    obj.requestWeatherData("hei", "pådeg");//har bare lagt inn noen random strings siden funksjonen krever det


    QQmlApplicationEngine engine;

    //qmlRegisterType<ModelController>("Model.Controller", 1, 0, "ModelController");

    ModelController MyModel;
    DayInfo dayInfo;
    WeatherInfo weatherInfo;

    engine.rootContext()->setContextProperty("myModel", &MyModel);
    engine.rootContext()->setContextProperty("dayInfo", &dayInfo);
    engine.rootContext()->setContextProperty("weatherInfo", &weatherInfo);


    const QUrl url(u"qrc:/Weatherapp_innlevering/Main.qml"_qs);



    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
