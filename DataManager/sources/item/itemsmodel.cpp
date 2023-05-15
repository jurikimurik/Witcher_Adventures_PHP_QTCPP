#include "../../headers/item/itemsmodel.h"

ItemsModel::ItemsModel(QObject *parent, QMap<int, Item> data) : QObject(parent), QMap<int, Item>(data)
{}

Item *ItemsModel::findById(int id)
{
    return &operator [](id);
}

Item *ItemsModel::findByName(QString name)
{
    for(Item& elem : *this)
    {
        if(elem.name() == name)
        {
            return &elem;
        }
    }

    return nullptr;
}

QStringList ItemsModel::getEveryItemName()
{
    QStringList names;
    for(const Item& elem : *this)
    {
        names.push_back(elem.name());
    }
    return names;
}

QStringList ItemsModel::getEveryItemIdStr()
{
    QStringList ids;
    for(const Item& elem : *this)
    {
        ids.push_back(QString::number(elem.getId()));
    }
    return ids;
}

QStringList ItemsModel::getEveryItemType()
{
    QStringList types;
    for(const Item& elem : *this)
    {
        types.push_back(elem.type().typeName);
    }
    types.removeDuplicates();
    return types;
}

void ItemsModel::addItem(Item newItem)
{
    insert(newItem.getId(), newItem);
}

void ItemsModel::addItems(QVector<Item> newItems)
{
    for(Item& item : newItems)
        insert(item.getId(), item);
}

void ItemsModel::dataChanged(Item newItem)
{
    addItem(newItem);
    emit dataSaved();
}
