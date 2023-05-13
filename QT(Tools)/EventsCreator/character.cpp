#include "character.h"

int Character::getMc_id() const
{
    return mc_id;
}

QString Character::Name() const
{
    return m_Name;
}

void Character::setName(const QString &newName)
{
    m_Name = newName;
}

QString Character::imagePath() const
{
    return m_imagePath;
}

void Character::setImagePath(const QString &newImagePath)
{
    m_imagePath = newImagePath;
}

int Character::maxHP() const
{
    return m_maxHP;
}

void Character::setMaxHP(int newMaxHP)
{
    m_maxHP = newMaxHP;
}

int Character::maxMP() const
{
    return m_maxMP;
}

void Character::setMaxMP(int newMaxMP)
{
    m_maxMP = newMaxMP;
}

int Character::atk() const
{
    return m_atk;
}

void Character::setAtk(int newAtk)
{
    m_atk = newAtk;
}

int Character::def() const
{
    return m_def;
}

void Character::setDef(int newDef)
{
    m_def = newDef;
}

int Character::agility() const
{
    return m_agility;
}

void Character::setAgility(int newAgility)
{
    m_agility = newAgility;
}

int Character::currentHp() const
{
    return m_currentHp;
}

void Character::setCurrentHp(int newCurrentHp)
{
    m_currentHp = newCurrentHp;
}

int Character::currentMp() const
{
    return m_currentMp;
}

void Character::setCurrentMp(int newCurrentMp)
{
    m_currentMp = newCurrentMp;
}

Character::Character()
{

}
