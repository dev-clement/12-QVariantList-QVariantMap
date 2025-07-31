#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "cppclass.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CppClass cppClass;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("CppClass", &cppClass);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("TransferingVariant", "Main");

    if (engine.rootObjects().isEmpty()) {
        return -1;
    } else {
        cppClass.setQmlRootObject(engine.rootObjects().first());
    }

    return app.exec();
}
