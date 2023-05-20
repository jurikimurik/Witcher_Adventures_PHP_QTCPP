#include "../../headers/consequence/consequence.h"

Consequence::Consequence(int id, const QString &name, bool isOn) : DatabaseItem(id, name),
    m_isOn(isOn)
{}

Consequence::~Consequence()
{

}

bool Consequence::isOn() const
{
    return m_isOn;
}

QString Consequence::toString()
{
    QString properties = DatabaseItem::toString();
    QString splitter = DatabaseItem::getSplitter();

    properties += QString::number(m_isOn) + splitter;
    return properties;
}

Consequence Consequence::fromString(QString str)
{
    QStringList list = str.split(DatabaseItem::getSplitter());
    return Consequence(list.takeFirst().toInt(), list.takeFirst(), list.takeFirst().toInt());
}

void Consequence::setOn(bool newIsOn)
{
    m_isOn = newIsOn;
}


