#include "../../headers/item/itemtypemodel.h"


ItemTypeModel::ItemTypeModel(QObject *parent) : QObject(parent)
{}

ItemType ItemTypeModel::getItemType(QString name)
{
    for(const auto& elem : *this)
    {
        if(elem.typeName == name)
            return elem;
    }
    return ItemType();
}

void ItemTypeModel::addItemType(ItemType type)
{
    push_back(type);
    emit dataUpdated();
}

void ItemTypeModel::updateItemType(ItemType type)
{
    int index = -1;
    for(int i = 0; i < size(); ++i)
    {
        if(type.typeName == at(i).typeName) {
            index = i;
            break;
        }

    }

    if(index == -1)
        return;

    replace(index, type);

    emit dataUpdated();
}

QStringList ItemTypeModel::getAllTypesNames()
{
    QStringList list;
    for(const auto& elem : *this)
    {
        list.push_back(elem.typeName);
    }
    return list;
}

QStringList ItemTypeModel::getAllTypesDescriptions()
{
    QStringList list;
    for(const auto& elem : *this)
    {
        list.push_back(elem.typeDescription);
    }
    return list;
}
