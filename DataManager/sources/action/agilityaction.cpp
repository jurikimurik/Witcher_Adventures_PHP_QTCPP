#include "../../headers/action/agilityaction.h"



int AgilityAction::difficulty() const
{
    return m_difficulty;
}

void AgilityAction::setDifficulty(int newDifficulty)
{
    m_difficulty = newDifficulty;
}

int AgilityAction::timePerOne() const
{
    return m_timePerOne;
}

void AgilityAction::setTimePerOne(int newTimePerOne)
{
    m_timePerOne = newTimePerOne;
}

Action AgilityAction::toAction()
{
    QString data = dataSplitter + QString::number(difficulty()) + dataSplitter + QString::number(timePerOne()) + dataSplitter;
    return Action(ActionType::NONE, data, idToAction());
}

QString AgilityAction::toString()
{
    return toAction().toString();
}


AgilityAction::AgilityAction(int difficulty, int timePerOne) : Action(ActionType::Agility),
    m_difficulty(difficulty),
    m_timePerOne(timePerOne)
{}

AgilityAction AgilityAction::fromString(QString str)
{

}
