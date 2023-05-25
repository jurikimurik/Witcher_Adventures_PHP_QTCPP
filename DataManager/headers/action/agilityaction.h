#ifndef AGILITYACTION_H
#define AGILITYACTION_H

#include "action.h"

class AgilityAction : public Action
{
private:
    int m_difficulty;
    int m_timePerOne;


public:
    AgilityAction(int difficulty = 1, int timePerOne = 5);
    static AgilityAction fromString(QString str);

    int difficulty() const;
    void setDifficulty(int newDifficulty);
    int timePerOne() const;
    void setTimePerOne(int newTimePerOne);

    // Action interface
public:
    virtual Action toAction() const;
    virtual QString toString() const;

};

#endif // AGILITYACTION_H
