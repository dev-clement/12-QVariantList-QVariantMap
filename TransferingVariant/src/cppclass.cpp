#include <QDate>
#include <QColor>
#include <QDebug>
#include "cppclass.hpp"

CppClass::CppClass(QObject *parent): QObject{parent},
                                     _qmlRootObject{nullptr} {}

void CppClass::passFromQmlToCpp(const QVariantList &list /*array*/, const QVariantMap &map /*object*/) {
    qDebug() << "Received variant list and map from QML";
    qDebug() << "List :";
    for (int i = 0; i < list.size(); ++i) {
        qDebug() << "List item: " << list.at(i).toString();
    }

    qDebug() << "Map : ";
    for (int i = 0; i < map.keys().size(); ++i) {
        qDebug() << "Map item : " << map[map.keys().at(i)].toString();
    }
}

QVariantList CppClass::getVariantListFromCpp() const {
    QVariantList list;
    list << 123.3 << QColor(Qt::cyan) << "Qt is great" << 10;
    return list;
}

QVariantMap CppClass::getVariantMapFromCpp() const {
    QVariantMap map;
    map.insert("movie", "game of thrones");
    map.insert("names", "John Snow");
    map.insert("role", "main character");
    map.insert("release", QDate(2011, 4, 7));
    return map;
}

void CppClass::setQmlRootObject(QObject *object) {
    _qmlRootObject = object;
}

void CppClass::triggerJSCall() {
    qDebug() << "Calling JS";
    QVariantList list = getVariantListFromCpp();
    QVariantMap map = getVariantMapFromCpp();

    QMetaObject::invokeMethod(_qmlRootObject, "arrayObjectFunc"
                              , Q_ARG(QVariant, QVariant::fromValue(list))
                              , Q_ARG(QVariant, QVariant::fromValue(map)));
    qDebug() << "Called JS";
}
