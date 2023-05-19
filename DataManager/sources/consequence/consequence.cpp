#include "../../headers/consequence/consequence.h"

Consequence::Consequence(int id, const QString &name, bool isOn) : DatabaseItem(id, name),
    m_isOn(isOn)
{}

bool Consequence::isOn() const
{
    return m_isOn;
}

void Consequence::setOn(bool newIsOn)
{
    m_isOn = newIsOn;
}


