#ifndef CPPCLASS_HPP
#define CPPCLASS_HPP

#include <QObject>
#include <QVariantMap>
#include <QVariantList>
#include <QtQml/qqmlregistration.h>

class CppClass : public QObject
{
    Q_OBJECT
public:
    explicit CppClass(QObject *parent = nullptr);

    Q_INVOKABLE void passFromQmlToCpp(const QVariantList &list, const QVariantMap &map);
    Q_INVOKABLE QVariantList getVariantListFromCpp() const;
    Q_INVOKABLE QVariantMap getVariantMapFromCpp() const;

    void setQmlRootObject(QObject *ptr);
signals:

public slots:
    void triggerJSCall();

private:
    QObject *_qmlRootObject;
};

#endif // CPPCLASS_HPP
