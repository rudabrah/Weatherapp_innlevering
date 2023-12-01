//main.cpp

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
    currentWeather wtrh;
    //obj.requestWeatherData("hei", "pådeg");//har bare lagt inn noen random strings siden funksjonen krever det
    wtrh.getCurrentWeather("Oslo", "41749e5f7ad7e73cce5057a63ed97919");


    QQmlApplicationEngine engine;

    //qmlRegisterType<ModelController>("Model.Controller", 1, 0, "ModelController");

    ModelController myModel;
    DayInfo myDayInfo;
    WeatherInfo myWeatherInfo;
    currentWeather myWeather;

    engine.rootContext()->setContextProperty("myModel", &myModel);
    engine.rootContext()->setContextProperty("myDayInfo", &myDayInfo);
    engine.rootContext()->setContextProperty("myWeatherInfo", &myWeatherInfo);
    engine.rootContext()->setContextProperty("myWeather", &myWeather);



    const QUrl url(u"qrc:/Weatherapp_innlevering/Main.qml"_qs);



    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
