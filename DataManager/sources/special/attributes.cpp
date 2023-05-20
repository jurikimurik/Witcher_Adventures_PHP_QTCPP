#include "././headers/special/attributes.h"

#include "../../headers/basic/databaseitem.h"
#include <QDebug>

QString Attributes::toString()
{
    QString properties;
    for(const auto& elem : AttributesPointers)
    {
        properties += QString::number(this->*elem) + DatabaseItem::getSplitter();
    }
    return properties;
}

Attributes Attributes::fromString(QString str)
{
    Attributes newAttr;
    QStringList list = str.split(DatabaseItem::getSplitter());
    for(int c = 0; c < list.size(); c++)
    {
        if(!list.at(c).isEmpty())
            newAttr.*AttributesPointers[c] = list.at(c).toInt();
    }

    return newAttr;
}
