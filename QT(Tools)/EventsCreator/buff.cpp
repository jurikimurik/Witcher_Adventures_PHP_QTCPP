#include "buff.h"


int Buff::duration() const
{
    return m_duration;
}

Attributes Buff::attributes() const
{
    return m_attributes;
}

void Buff::setAttributes(const Attributes &newAttributes)
{
    m_attributes = newAttributes;
}

void Buff::setDuration(int newDuration)
{
    m_duration = newDuration;
}

