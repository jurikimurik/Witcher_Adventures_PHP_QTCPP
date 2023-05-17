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
