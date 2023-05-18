#include "../../headers/character/charactermodel.h"

CharacterModel::CharacterModel(QObject *parent, QMap<int, Character> database)
    : QObject{parent}
{
    swap(database);
}

QStringList CharacterModel::getAllIds()
{
    QStringList list;
    for(const auto& elem : values())
    {
        list.push_back(QString::number(elem.id()));
    }
    return list;
}

QStringList CharacterModel::getAllNames()
{
    QStringList list;
    for(const auto& elem : values())
    {
        list.push_back(elem.name());
    }
    return list;
}

QStringList CharacterModel::getAllIdsAndNames()
{
    QStringList list;
    for(const auto& elem: values())
    {
        list.push_back(QString::number(elem.id()) + " - " + elem.name());
    }
    return list;
}

void CharacterModel::updateCharacter(const Character &updatedChar)
{
    if(value(updatedChar.id()).id() != -1) {
        insert(updatedChar.id(), updatedChar);
        emit dataUpdated();
    }


}

void CharacterModel::addCharacter(const Character &newChar)
{
    insert(newChar.id(), newChar);
    emit dataUpdated();
}
