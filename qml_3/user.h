#ifndef USER_H
#define USER_H

#include "project_type.h"

class User: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
public:
    User(QString name);
    Q_INVOKABLE QString getName() const;
    void setName(const QString &newName);


signals:
    void nameChanged();

private:
    QString name;

};

#endif // USER_H
