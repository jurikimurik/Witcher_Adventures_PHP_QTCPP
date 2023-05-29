#include "../../headers/character/charactermodel.h"
#include <QDebug>

const QString CharacterModel::modelSplitter = "[::CHARACTERS::]";

CharacterModel::CharacterModel(QObject *parent, QMap<int, Character> database)
    : QObject{parent}
{
    swap(database);
    emit dataUpdated(getAllIdsAndNames());
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

CharacterModel *CharacterModel::fromString(QString str)
{
    CharacterModel* model = new CharacterModel();
    QStringList info = str.split(getModelSplitter());
    QStringList items = info.at(1).split(DatabaseItem::getItemSplitter());
    for(const auto& elem: items)
    {
        if(elem.isEmpty())
            continue;

        QStringList properties = elem.split(DatabaseItem::getSplitter());
        int mapId = properties.takeFirst().toInt();
        Character character = Character::fromString(properties.join(DatabaseItem::getSplitter()));
        model->addCharacter(character);
    }
    return model;
}

QString CharacterModel::toString()
{
    QString properties = getModelSplitter();
    QString itemSplitter = DatabaseItem::getItemSplitter();
    QString splitter = DatabaseItem::getSplitter();

    for(const auto& elem : keys())
    {
        properties += itemSplitter + QString::number(elem) + splitter + value(elem).toString() + itemSplitter;
    }
    properties += getModelSplitter();
    return properties;
}

QString CharacterModel::getModelSplitter()
{
    return modelSplitter;
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
        emit dataUpdated(getAllIdsAndNames());
    }
}

void CharacterModel::deleteCharacter(const Character &charToDelete)
{
    remove(charToDelete.id());
    emit dataUpdated(getAllIdsAndNames());
}


void CharacterModel::addCharacter(const Character &newChar)
{
    insert(newChar.id(), newChar);
    emit dataUpdated(getAllIdsAndNames());
}
