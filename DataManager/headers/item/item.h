#ifndef ITEM_H
#define ITEM_H

#include <QVector>
#include <QString>
#include "itemtype.h"
#include "buff.h"
#include "../basic/databaseitem.h"

class Item : public DatabaseItem
{
private:
    ItemType m_type;
    QString m_description;
    QString m_imageName;
    int m_money;
    QVector<Buff> m_buffs;

public:
    Item();
    virtual ~Item();
    Item(const int& id, QString name, ItemType type, int money, QVector<Buff> buffs, QString description = QString(), QString imageName = QString());
    Item(const int& id, QString name, ItemType type, int money, Buff buff, QString description = QString(), QString imageName = QString());

    ItemType type() const;
    void setType(const ItemType &newType);
    QString description() const;
    void setDescription(const QString &newDescription);
    QString imageName() const;
    void setImageName(const QString &newImageName);
    int money() const;
    void setMoney(int newMoney);
    QVector<Buff> buffs() const;
    void setBuffs(const QVector<Buff> &newBuffs);
    void setId(int newId);


    Item &operator=(const Item& newItem);

    // DatabaseItem interface
public:
    virtual QString toString();
    static Item fromString(QString str);
};

#endif // ITEM_H
