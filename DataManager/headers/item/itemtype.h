#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <QString>

struct ItemType
{
    QString typeName;
    QString typeDescription;
    bool operator == (const ItemType& another) const
    {
        return typeName == another.typeName && typeDescription == another.typeDescription;
    }
};

#endif // ITEMTYPE_H
