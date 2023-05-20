#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <QString>
#include "../basic/databaseitem.h"
struct ItemType
{
    QString typeName;
    QString typeDescription;
    bool operator == (const ItemType& another) const
    {
        return typeName == another.typeName && typeDescription == another.typeDescription;
    }

    QString toString();
    static ItemType fromString(QString str);
};

#endif // ITEMTYPE_H
