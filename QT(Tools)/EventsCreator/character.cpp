#include "character.h"

Character::Character(int id, QString name, Attributes attributes, QString imagePath) : mc_id(id), m_Name(name), m_imagePath(imagePath), m_attributes(attributes)
{

}

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

Attributes Character::attributes() const
{
    return m_attributes;
}

void Character::setAttributes(const Attributes &newAttributes)
{
    m_attributes = newAttributes;
}

