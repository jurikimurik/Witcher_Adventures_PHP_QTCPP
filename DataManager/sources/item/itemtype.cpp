#include "../../headers/item/itemtype.h"

QString ItemType::toString()
{
    QString properties;
    QString splitter = DatabaseItem::getSplitter();

    properties += typeName + splitter + typeDescription + splitter;
    return properties;
}

ItemType ItemType::fromString(QString& str)
{
    QStringList list = str.split(DatabaseItem::getSplitter());
    ItemType type = ItemType({list.takeFirst(), list.takeFirst()});
    str = list.join(DatabaseItem::getSplitter());
    return type;
}
