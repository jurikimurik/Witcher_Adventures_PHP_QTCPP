#include "../../headers/item/item.h"

Item::Item(const int &id, QString name, ItemType type, int money, QVector<Buff> buffs, QString description, QString imageName) : id(id), m_name(name), m_type(type),
    m_description(description), m_imageName(imageName), m_money(money),  m_buffs(buffs)
{

}

int Item::getId() const
{
    return id;
}

QString Item::name() const
{
    return m_name;
}

void Item::setName(const QString &newName)
{
    m_name = newName;
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
