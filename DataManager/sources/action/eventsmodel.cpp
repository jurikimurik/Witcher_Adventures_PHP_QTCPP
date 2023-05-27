#include "../../headers/action/eventsmodel.h"

EventsModel::EventsModel(QObject *parent, QMap<int, Event> data)  : QObject(parent)
{
    swap(data);
}

QStringList EventsModel::getAllNamesAndIds()
{
    QStringList properties;
    for(const auto& elem : values())
    {
        properties.push_back(QString::number(elem.id()) + " - " + elem.name());
    }
    return properties;
}

QStringList EventsModel::getAllIds()
{
    QStringList properties;
    for(const auto& elem : values())
    {
        properties.push_back(QString::number(elem.id()));
    }
    return properties;
}

EventsModel *EventsModel::fromString(QString str)
{

}

void EventsModel::addEvent(const Event &event)
{
    insert(event.id(), event);
    emit dataUpdated();
}

void EventsModel::removeEvent(const Event &event)
{
    remove(event.id());
    emit dataUpdated();
}

void EventsModel::updateEvent(const Event &event)
{
    addEvent(event);
}

QString EventsModel::toString()
{

}

QStringList EventsModel::getAllNames()
{
    QStringList properties;
    for(const auto& elem : values())
    {
        properties.push_back(elem.name());
    }
    return properties;
}
