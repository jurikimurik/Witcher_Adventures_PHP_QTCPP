#ifndef ACTION_H
#define ACTION_H

#include <QString>
#include "../../headers/basic/databaseitem.h"


enum class ActionType {
    NONE = 0,
    Description = 1,
    Agility = 2,
    Battle = 3,
    Reward = 4,
    Choice = 5,
    Dice = 6
};

class Action
{
private:
    ActionType m_type;
    QString m_data;
    int m_idToAction;

public:
    static const QString dataSplitter;

public:
    Action(ActionType type = ActionType::NONE, const QString &data = QString(), int toAction = -1);
    virtual ~Action();

    virtual Action toAction() const;
    virtual QString toString() const;
    static Action fromString(QString str);

    ActionType type() const;
    void setType(ActionType newType);
    QString data() const;
    void setData(const QString &newData);
    int idToAction() const;
    void setIdToAction(int newIdToAction);
};

#endif // ACTION_H
