#include "../../headers/consequence/consequence.h"

Consequence::Consequence(int id, const QString &name, bool isOn) : m_id(id),
    m_name(name),
    m_isOn(isOn)
{}

int Consequence::id() const
{
    return m_id;
}

void Consequence::setId(int newId)
{
    if(m_id < 0)
        m_id = newId;
}

QString Consequence::name() const
{
    return m_name;
}

void Consequence::setName(const QString &newName)
{
    m_name = newName;
}

bool Consequence::isOn() const
{
    return m_isOn;
}

void Consequence::setOn(bool newIsOn)
{
    m_isOn = newIsOn;
}


