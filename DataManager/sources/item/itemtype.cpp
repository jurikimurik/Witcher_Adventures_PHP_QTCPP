#include "../../headers/item/itemtype.h"

QString ItemType::toString()
{
    QString properties;
    QString splitter = DatabaseItem::getSplitter();

    properties += typeName + splitter + typeDescription + splitter;
    return properties;
}

ItemType ItemType::fromString(QString str)
{
    QStringList list = str.split(DatabaseItem::getSplitter());
    return ItemType({list.takeFirst(), list.takeFirst()});
}
