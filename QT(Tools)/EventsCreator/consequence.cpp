#include "consequence.h"

int Consequence::id() const
{
    return m_id;
}

bool Consequence::isOn() const
{
    return m_isOn;
}

void Consequence::setOn(bool newIsOn)
{
    m_isOn = newIsOn;
}

Consequence::Consequence(const int &id, const bool &isOn) : m_id(id), m_isOn(isOn)
{}
