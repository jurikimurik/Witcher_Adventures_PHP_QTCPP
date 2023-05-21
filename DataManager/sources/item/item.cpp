#include "../../headers/item/item.h"

#include <QDebug>

Item::Item()
{

}

Item::~Item()
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

Item Item::fromString(QString str)
{
    QStringList list = str.split(DatabaseItem::getSplitter());

    int id = list.takeFirst().toInt();
    QString name = list.takeFirst();

    QString someStr = list.join(DatabaseItem::getSplitter());
    ItemType type = ItemType::fromString(someStr);
    list = someStr.split(DatabaseItem::getSplitter());


    QString desc = list.takeFirst();
    QString image = list.takeFirst();
    int money = list.takeFirst().toInt();

    QString remainStr = list.join(DatabaseItem::getSplitter());

    QVector<Buff> buffs;
    QStringList buffsProp = remainStr.split(DatabaseItem::getArraySplitter());
    for(auto& elem : buffsProp)
    {
        if(!elem.isEmpty())
            buffs.push_back(Buff::fromString(elem));
    }
    return Item(id, name, type, money, buffs, desc, image);
}

QString Item::toString()
{
    QString properties = DatabaseItem::toString();

    QString splitter = DatabaseItem::getSplitter();
    QString arraySplitter = DatabaseItem::getArraySplitter();

    properties += m_type.toString() + m_description + splitter + m_imageName + splitter + QString::number(m_money) + splitter;


    for(auto& elem : m_buffs)
    {
        properties += arraySplitter;

        properties += elem.toString();

        properties += arraySplitter;
    }

    return properties;
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
