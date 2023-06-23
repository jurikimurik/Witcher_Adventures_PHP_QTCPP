#include "../../headers/character/character.h"


QString Character::imageName() const
{
    return m_imageName;
}

void Character::setImageName(const QString &newImageName)
{
    m_imageName = newImageName;
}

Buff Character::basicStatistics() const
{
    return m_basicStatistics;
}

void Character::setBasicStatistics(const Buff &newAttributes)
{
    m_basicStatistics = newAttributes;
}

QString Character::toString()
{
    QString properties = DatabaseItem::toString();
    QString splitter = DatabaseItem::getSplitter();

    properties += m_imageName + splitter + m_basicStatistics.toString();
    return properties;
}

Character Character::fromString(QString str)
{
    QStringList props = str.split(DatabaseItem::getSplitter());
    return Character(props.takeFirst().toInt(), props.takeFirst(), props.takeFirst(), Buff::fromString(props.join(DatabaseItem::getSplitter())));
}

Character::Character(int id, const QString &name, const QString &imageName, const Buff &attributes) : DatabaseItem(id, name),
    m_imageName(imageName),
    m_basicStatistics(attributes)
{}
