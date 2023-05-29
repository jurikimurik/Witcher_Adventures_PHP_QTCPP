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
    QStringList getEveryItemIdAndName();
    QStringList getEveryItemName();
    QStringList getEveryItemIdStr();
    QStringList getEveryItemType();
    void addItem(Item newItem);
    void addItems(QVector<Item> newItems);

    QString toString();
    static ItemsModel* fromString(QString str);

public:
    static const QString modelSplitter;
    static QString getModelSplitter();

public slots:
    void dataChanged(Item newItem);
    void idsAndNamesNeeded();

signals:
    void dataSaved();
    void sendIdsAndNames(QStringList list);
};

#endif // ITEMSMODEL_H
