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
    virtual ~Event();

    void moveAction(int from, int where);
    void addAction(const Action& action);
    template <typename T> void addActions(const T& actions);
    void updateAction(int whichOne, const Action& action);
    void removeAction(int number);


    virtual QString toString();
    static Event fromString(QString str);

    QString description() const;
    void setDescription(const QString &newDescription);
};

template<typename T>
void Event::addActions(const T &actions)
{
    if constexpr(std::is_same<typename T::value_type, Action>::value)
    {
        for(const auto& elem: actions)
            push_back(elem);
    } else {
        throw std::runtime_error("Array don't contain objects of Action type.");
    }
}

#endif // EVENT_H
