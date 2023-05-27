#include "../../headers/action/event.h"




QString Event::description() const
{
    return m_description;
}

void Event::setDescription(const QString &newDescription)
{
    m_description = newDescription;
}

Event::Event(const QString &description, int id, const QString &name) : DatabaseItem(id, name),
    m_description(description)
{}
