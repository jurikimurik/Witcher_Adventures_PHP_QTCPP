#include "../../headers/action/event.h"


#include <QDebug>
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

void Event::updateAction(int whichOne, const Action &action)
{
    (*this)[whichOne] = action;
}

void Event::removeAction(int number)
{
    remove(number);
}

QString Event::toString()
{
    QString properties = DatabaseItem::toString();
    QString splitter = DatabaseItem::getItemSplitter();

    properties += description() + DatabaseItem::getSplitter();

    properties += splitter;
    for(const auto& elem: *this)
    {
        properties += elem.toString() + splitter;
    }

    return properties;
}

Event Event::fromString(QString str)
{
    QStringList props = str.split(DatabaseItem::getSplitter());

    // Reading basics of Event
    QString desc = props.at(2);
    int id = props.at(0).toInt();
    QString name = props.at(1);

    //Creating event and adding actions
    Event newEvent(desc, id, name);
    QStringList actionProps = str.split(DatabaseItem::getItemSplitter());
    //  - Deleting first (because it's basics of Event)
    actionProps.pop_front();
    for(const auto& elem: actionProps)
    {
        if(!elem.isEmpty())
            newEvent.addAction(Action::fromString(elem));
    }

    return newEvent;

}



