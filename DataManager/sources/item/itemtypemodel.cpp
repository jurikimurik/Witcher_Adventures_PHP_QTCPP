#include "../../headers/item/itemtypemodel.h"


ItemTypeModel::ItemTypeModel(QObject *parent) : QObject(parent)
{}

void ItemTypeModel::addItemType(ItemType type)
{
    push_back(type);
}

void ItemTypeModel::updateItemType(ItemType type)
{
    int index = indexOf(type);
    if(index == -1)
        return;

    replace(index, type);
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
