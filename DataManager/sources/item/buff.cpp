#include "./././headers/item/buff.h"

QString Buff::name() const
{
    return m_name;
}

void Buff::setName(const QString &newName)
{
    m_name = newName;
}

int Buff::duration() const
{
    return m_duration;
}

void Buff::setDuration(int newDuration)
{
    m_duration = newDuration;
}

Attributes Buff::changedAttributes() const
{
    return m_changedAttributes;
}

void Buff::setChangedAttributes(const Attributes &newChangedAttributes)
{
    m_changedAttributes = newChangedAttributes;
}

Buff::Buff() :  m_name(QString()), m_duration(-1), m_changedAttributes(Attributes())
{

}

Buff::Buff(int duration, Attributes attr, QString name) : m_name(name), m_duration(duration), m_changedAttributes(attr)
{}
