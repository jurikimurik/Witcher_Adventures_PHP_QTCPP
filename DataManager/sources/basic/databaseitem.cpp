#include "../../headers/basic/databaseitem.h"

const QString DatabaseItem::splitter = "[::|::]";
const QString DatabaseItem::arraySplitter = "[--|--]";
const QString DatabaseItem::itemSplitter = "[:{:}:]";

int DatabaseItem::id() const
{
    return m_id;
}

void DatabaseItem::setId(int newId)
{
    if(m_id < 0)
        m_id = newId;
}

QString DatabaseItem::name() const
{
    return m_name;
}

void DatabaseItem::setName(const QString &newName)
{
    m_name = newName;
}

QString DatabaseItem::toString()
{
    return QString::number(m_id) + getSplitter() + m_name + getSplitter();
}

DatabaseItem DatabaseItem::fromString(QString str)
{
    QStringList splitted = str.split(getSplitter());
    return DatabaseItem(splitted.at(0).toInt(), splitted.at(1));
}

QString DatabaseItem::getItemSplitter()
{
    return itemSplitter;
}

QString DatabaseItem::getArraySplitter()
{
    return arraySplitter;
}

QString DatabaseItem::getSplitter()
{
    return splitter;
}


DatabaseItem::DatabaseItem(int id, const QString &name) : m_id(id),
    m_name(name)
{

}

DatabaseItem::~DatabaseItem()
{

}


