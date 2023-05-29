#include "../../headers/item/itemsmodel.h"

const QString ItemsModel::modelSplitter = "[::ITEMS::]";

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

QStringList ItemsModel::getEveryItemIdAndName()
{
    QStringList namesAndIds;
    for(const Item& elem : *this)
    {
        namesAndIds.push_back(QString::number(elem.id()) + " - " + elem.name());
    }
    return namesAndIds;
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
        ids.push_back(QString::number(elem.id()));
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
    insert(newItem.id(), newItem);
}

void ItemsModel::addItems(QVector<Item> newItems)
{
    for(Item& item : newItems)
        insert(item.id(), item);
}

QString ItemsModel::toString()
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

ItemsModel *ItemsModel::fromString(QString str)
{
    ItemsModel* model = new ItemsModel();
    QStringList info = str.split(getModelSplitter());
    QStringList items = info.at(1).split(DatabaseItem::getItemSplitter());
    for(const auto& elem: items)
    {
        if(elem.isEmpty())
            continue;

        QStringList properties = elem.split(DatabaseItem::getSplitter());
        int mapId = properties.takeFirst().toInt();
        Item item = Item::fromString(properties.join(DatabaseItem::getSplitter()));
        model->insert(mapId, item);
    }
    return model;
}

QString ItemsModel::getModelSplitter()
{
    return modelSplitter;
}

void ItemsModel::dataChanged(Item newItem)
{
    addItem(newItem);
    emit dataSaved();
}

void ItemsModel::idsAndNamesNeeded()
{
    emit getEveryItemIdAndName();
}
