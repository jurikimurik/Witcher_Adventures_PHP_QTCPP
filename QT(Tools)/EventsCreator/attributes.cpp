#include "attributes.h"

int Attributes::maxHP() const
{
    return m_maxHP;
}

void Attributes::setMaxHP(int newMaxHP)
{
    m_maxHP = newMaxHP;
}

int Attributes::maxMP() const
{
    return m_maxMP;
}

void Attributes::setMaxMP(int newMaxMP)
{
    m_maxMP = newMaxMP;
}

int Attributes::atk() const
{
    return m_atk;
}

void Attributes::setAtk(int newAtk)
{
    m_atk = newAtk;
}

int Attributes::def() const
{
    return m_def;
}

void Attributes::setDef(int newDef)
{
    m_def = newDef;
}

int Attributes::agility() const
{
    return m_agility;
}

void Attributes::setAgility(int newAgility)
{
    m_agility = newAgility;
}

int Attributes::currentHp() const
{
    return m_currentHp;
}

void Attributes::setCurrentHp(int newCurrentHp)
{
    m_currentHp = newCurrentHp;
}

int Attributes::currentMp() const
{
    return m_currentMp;
}

void Attributes::setCurrentMp(int newCurrentMp)
{
    m_currentMp = newCurrentMp;
}

Attributes::Attributes()
{

}
