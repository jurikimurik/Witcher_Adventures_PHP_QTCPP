#ifndef AGILITYACTION_H
#define AGILITYACTION_H

#include "action.h"

class AgilityAction : public Action
{
private:
    int m_difficulty;
    int m_timePerOne;
    int m_winActionId;
    int m_loseActionId;


public:
    AgilityAction(int difficulty = 1, int timePerOne = 5, int winActionId = -1, int loseActionId = -1);
    static AgilityAction fromString(QString str);

    int difficulty() const;
    void setDifficulty(int newDifficulty);
    int timePerOne() const;
    void setTimePerOne(int newTimePerOne);
    int winActionId() const;
    void setWinActionId(int newWinActionId);
    int loseActionId() const;
    void setLoseActionId(int newLoseActionId);

    // Action interface
public:
    virtual Action toAction() const;
    virtual QString toString() const;
};

#endif // AGILITYACTION_H
