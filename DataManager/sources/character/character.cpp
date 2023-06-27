#include "../../headers/character/character.h"

#include <QDebug>

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

QVector<Buff> Character::buffs() const
{
    return m_buffs;
}

void Character::setBuffs(const QVector<Buff> &newBuffs)
{
    m_buffs = newBuffs;
}

QString Character::toString()
{
    QString properties = DatabaseItem::toString();
    QString splitter = DatabaseItem::getSplitter();
    QString arraySplitter = DatabaseItem::getArraySplitter();

    properties += m_imageName + splitter + m_basicStatistics.toString() + splitter;
    for(Buff& buff : buffs())
    {
        properties += buff.toString() + arraySplitter;
    }
    return properties;
}

Character Character::fromString(QString str)
{
    QStringList props = str.split(DatabaseItem::getSplitter());
    int id = props.takeFirst().toInt();
    QString name = props.takeFirst();
    QString imageName = props.takeFirst();

    //String for Buff reading
    QString leftStr = props.join(DatabaseItem::getSplitter());
    QStringList strBuffs = leftStr.split(DatabaseItem::getArraySplitter());

    Buff basicAttributes = Buff::fromString(strBuffs.takeFirst());

    QVector<Buff> buffs;
    for(QString& strBuff : strBuffs)
    {
        if(!strBuff.isEmpty())
            buffs += Buff::fromString(strBuff);
    }
    return Character(id, name, imageName, basicAttributes, buffs);
}

Character::Character(int id, const QString &name, const QString &imageName, const Buff &attributes, const QVector<Buff> &buffs) : DatabaseItem(id, name),
    m_imageName(imageName),
    m_basicStatistics(attributes),
    m_buffs(buffs)
{}
