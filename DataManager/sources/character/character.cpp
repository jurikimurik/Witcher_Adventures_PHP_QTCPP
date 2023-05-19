#include "../../headers/character/character.h"


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

Character::Character(int id, const QString &name, const QString &imageName, const Buff &attributes) : DatabaseItem(id, name),
    m_imageName(imageName),
    m_attributes(attributes)
{}
