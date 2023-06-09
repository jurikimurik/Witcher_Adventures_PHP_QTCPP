#ifndef ITEMTYPEMODEL_H
#define ITEMTYPEMODEL_H

#include <QVector>
#include <QObject>
#include "itemtype.h"

class ItemTypeModel : public QObject, public QVector<ItemType>
{
    Q_OBJECT
public:
    ItemTypeModel(QObject *parent = nullptr);
    ItemType getItemType(QString name);

public slots:
    void addItemType(ItemType type);
    void updateItemType(ItemType type);
    QStringList getAllTypesNames();
    QStringList getAllTypesDescriptions();

signals:
    void dataUpdated();
};

#endif // ITEMTYPEMODEL_H
