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

Event::~Event()
{

}

void Event::moveAction(int from, int where)
{
    swapItemsAt(from, where);
}

void Event::addAction(const Action &action)
{
    push_back(action);
}

void Event::removeAction(int number)
{
    remove(number);
}

QString Event::toString()
{

}



