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

    QQmlApplicationEngine engine;

    ModelController myModel;
    DayInfo myDayInfo;
    WeatherInfo myWeatherInfo;
    currentWeather myWeather;
    qDebug() << "Is myWeather object valid?" << (myWeather.isValid() ? "Yes" : "No");

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
