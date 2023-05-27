#include "../../headers/action/eventsmodel.h"

EventsModel::EventsModel(QObject *parent, QMap<int, Event> data)  : QObject(parent)
{
    swap(data);
}

QStringList EventsModel::getAllNamesAndIds()
{

}

QStringList EventsModel::getAllIds()
{

}

EventsModel *EventsModel::fromString(QString str)
{

}

void EventsModel::addEvent(const Event &action)
{

}

void EventsModel::removeEvent(const Event &action)
{

}

void EventsModel::updateEvent(const Event &action)
{

}

QString EventsModel::toString()
{

}

QStringList EventsModel::getAllNames()
{

}
