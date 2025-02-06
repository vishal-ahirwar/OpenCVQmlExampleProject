#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include"cvimageprovider.h"
#include<QQmlContext>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    auto provider=new CvImageProvider();

    // Register the custom image provider with the name "cvprovider"
    engine.rootContext()->setContextProperty("stream",provider);
    engine.addImageProvider(QLatin1String("cvprovider"),provider);

    // Load the main QML file, use the correct path
    engine.load(QUrl("qrc:/qml/Main.qml"));  // Directly load QML file

    return app.exec();
}
