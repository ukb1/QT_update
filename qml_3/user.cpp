#include "user.h"

User::User(QString name): name(name)
{

}

QString User::getName() const
{
//    qDebug() << "deneme";
    return name;
}

void User::setName(const QString &newName)
{
    if (name == newName)
        return;
    name = newName;
    emit nameChanged();
}
