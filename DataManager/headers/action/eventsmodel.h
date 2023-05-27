#ifndef EVENTSMODEL_H
#define EVENTSMODEL_H

#include <QObject>
#include <QMap>
#include "event.h"

class EventsModel : public QObject, public QMap<int, Event>
{
    Q_OBJECT

public:
    EventsModel(QObject *parent = nullptr, QMap<int, Event> data = QMap<int, Event>());

    QStringList getAllNamesAndIds();
    QStringList getAllNames();
    QStringList getAllIds();

    QString toString();
    static EventsModel* fromString(QString str);

public slots:
    void addEvent(const Event& action);
    void updateEvent(const Event& action);
    void removeEvent(const Event& action);

signals:
    void dataUpdated();

};

#endif // EVENTSMODEL_H
