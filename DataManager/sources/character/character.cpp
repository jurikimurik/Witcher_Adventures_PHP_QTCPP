#include "../../headers/character/character.h"

int Character::id() const
{
    return m_id;
}

void Character::setId(int newId)
{
    if(m_id < -1)
        m_id = newId;
}

QString Character::name() const
{
    return m_name;
}

void Character::setName(const QString &newName)
{
    m_name = newName;
}

QString Character::imageName() const
{
    return m_imageName;
}

void Character::setImageName(const QString &newImageName)
{
    m_imageName = newImageName;
}

Buff Character::attributes() const
{
    return m_attributes;
}

void Character::setAttributes(const Buff &newAttributes)
{
    m_attributes = newAttributes;
}

Character::Character(int id, const QString &name, const QString &imageName, const Buff &attributes) : m_id(id),
    m_name(name),
    m_imageName(imageName),
    m_attributes(attributes)
{}
