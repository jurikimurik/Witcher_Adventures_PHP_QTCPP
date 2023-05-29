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

    static const QString modelSplitter;
    QString toString();
    static EventsModel* fromString(QString str);


    static QString getModelSplitter();

public slots:
    void addEvent(const Event& event);
    void updateEvent(const Event& event);
    void removeEvent(const Event& event);

signals:
    void dataUpdated(QStringList list);

};

#endif // EVENTSMODEL_H
