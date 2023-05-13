#include "action.h"

Action::Action()
{

}

QString Action::descriptionText() const
{
    return m_descriptionText;
}

void Action::setDescriptionText(const QString &newDescriptionText)
{
    m_descriptionText = newDescriptionText;
}

QString Action::descriptionText() const
{
    return m_descriptionText;
}

void Action::setDescriptionText(const QString &newDescriptionText)
{
    m_descriptionText = newDescriptionText;
}

QString Action::imagePath() const
{
    return m_imagePath;
}

void Action::setImagePath(const QString &newImagePath)
{
    m_imagePath = newImagePath;
}

ActionType Action::type() const
{
    return m_type;
}

void Action::setType(ActionType newType)
{
    m_type = newType;
}

Action::Action(ActionType type, const QString &descriptionText, const QString &imagePath) : m_descriptionText(descriptionText),
    m_imagePath(imagePath),
    m_type(type)
{}
