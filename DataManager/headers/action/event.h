#ifndef EVENT_H
#define EVENT_H

#include <QVector>
#include "action.h"

class Event : public QVector<Action>, public DatabaseItem
{
private:
    QString m_description;

public:
    Event(const QString &description = QString(), int id = -1, const QString &name = QString());
    void moveAction(int from, int where);
    void addAction(const Action& action);
    void removeAction(int number);


    QString toString();
    static Event fromString(QString str);

    QString description() const;
    void setDescription(const QString &newDescription);
};

#endif // EVENT_H
