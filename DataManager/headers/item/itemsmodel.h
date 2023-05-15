#ifndef ITEMSMODEL_H
#define ITEMSMODEL_H

#include <QObject>
#include <QMap>
#include "item.h"

#include <QStringList>

class ItemsModel : public QObject, public QMap<int, Item>
{
    Q_OBJECT
public:
    ItemsModel(QObject* parent = nullptr, QMap<int, Item> database = QMap<int, Item>());
    Item* findById(int id);
    Item* findByName(QString name);
    QStringList getEveryItemName();
    QStringList getEveryItemIdStr();
    QStringList getEveryItemType();

//public slots:
   // void dataChanged(Item newItem);
};

#endif // ITEMSMODEL_H
