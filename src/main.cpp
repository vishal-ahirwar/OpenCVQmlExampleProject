#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"cvimageprovider.h"
#include<QQmlContext>
#include"streamer.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Streamer stream;
    // Register the custom image provider with the name "cvProvider"
    engine.rootContext()->setContextProperty("stream",&stream);
    engine.addImageProvider(QLatin1String("cvprovider"), new CvImageProvider());

    // Load the main QML file, use the correct path
    engine.load(QUrl("qrc:/qml/Main.qml"));  // Directly load QML file

    return app.exec();
}
