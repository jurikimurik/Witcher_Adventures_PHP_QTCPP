#include "item.h"


int Item::getMc_id() const
{
    return mc_id;
}

QString Item::name() const
{
    return m_name;
}

void Item::setName(const QString &newName)
{
    m_name = newName;
}

QString Item::ImagePath() const
{
    return m_ImagePath;
}

void Item::setImagePath(const QString &newImagePath)
{
    m_ImagePath = newImagePath;
}

QString Item::description() const
{
    return m_description;
}

void Item::setDescription(const QString &newDescription)
{
    m_description = newDescription;
}

QVector<Buff> Item::increases() const
{
    return m_increases;
}

void Item::setIncreases(const QVector<Buff> &newIncreases)
{
    m_increases = newIncreases;
}

Item::Item(int id, QString name, QVector<Buff> increases, QString imagePath) : mc_id(id), m_name(name), m_ImagePath(imagePath), m_increases(increases)
{

}
