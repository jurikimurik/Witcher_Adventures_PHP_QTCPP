#include "../../headers/action/eventsmodel.h"
#include <QDebug>
const QString EventsModel::modelSplitter = "[::EVENTS::]";

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

QString EventsModel::getModelSplitter()
{
    return modelSplitter;
}

EventsModel *EventsModel::fromString(QString str)
{
    EventsModel* model = new EventsModel();
    QStringList info = str.split(getModelSplitter());
    QStringList events = info.at(1).split(DatabaseItem::getArraySplitter());
    for(const auto& elem: events)
    {
        if(elem.isEmpty())
            continue;
        QStringList properties = elem.split(DatabaseItem::getSplitter());
        int mapId = properties.takeFirst().toInt();
        Event event = Event::fromString(properties.join(DatabaseItem::getSplitter()));
        model->insert(mapId, event);
    }
    return model;
}

void EventsModel::addEvent(const Event &event)
{
    insert(event.id(), event);
    emit dataUpdated(getAllNamesAndIds());
}

void EventsModel::removeEvent(const Event &event)
{
    remove(event.id());
    emit dataUpdated(getAllNamesAndIds());
}

void EventsModel::updateEvent(const Event &event)
{
    addEvent(event);
}

QString EventsModel::toString()
{
    QString properties = getModelSplitter();
    QString arraySplitter = DatabaseItem::getArraySplitter();
    QString splitter = DatabaseItem::getSplitter();

    for(const auto& elem : keys())
    {
        properties += arraySplitter + QString::number(elem) + splitter + value(elem).toString() + arraySplitter
            ;
    }
    properties += getModelSplitter();
    return properties;
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
