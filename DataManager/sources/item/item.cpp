#include "../../headers/item/item.h"

Item::Item()
{

}


Item &Item::operator=(const Item &newItem)
{
    DatabaseItem::setId(newItem.id());
    setName(newItem.name());
    setType(newItem.type());
    setDescription(newItem.description());
    setImageName(newItem.imageName());
    setMoney(newItem.money());
    setBuffs(newItem.buffs());
    return *this;
}

Item::Item(const int &id, QString name, ItemType type, int money, QVector<Buff> buffs, QString description, QString imageName) : DatabaseItem(id, name), m_type(type),
    m_description(description), m_imageName(imageName), m_money(money),  m_buffs(buffs)
{

}

Item::Item(const int &id, QString name, ItemType type, int money, Buff buff, QString description, QString imageName) : DatabaseItem(id, name), m_type(type),
    m_description(description), m_imageName(imageName), m_money(money), m_buffs({buff})
{

}


ItemType Item::type() const
{
    return m_type;
}

void Item::setType(const ItemType &newType)
{
    m_type = newType;
}

QString Item::description() const
{
    return m_description;
}

void Item::setDescription(const QString &newDescription)
{
    m_description = newDescription;
}

QString Item::imageName() const
{
    return m_imageName;
}

void Item::setImageName(const QString &newImageName)
{
    m_imageName = newImageName;
}

int Item::money() const
{
    return m_money;
}

void Item::setMoney(int newMoney)
{
    m_money = newMoney;
}

QVector<Buff> Item::buffs() const
{
    return m_buffs;
}

void Item::setBuffs(const QVector<Buff> &newBuffs)
{
    m_buffs = newBuffs;
}
