#ifndef ITEMSMODEL_H
#define ITEMSMODEL_H

#include <QObject>
#include <QMap>
#include <QVector>
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
    void addItem(Item newItem);
    void addItems(QVector<Item> newItems);

public slots:
    void dataChanged(Item newItem);

signals:
    void dataSaved();
};

#endif // ITEMSMODEL_H
