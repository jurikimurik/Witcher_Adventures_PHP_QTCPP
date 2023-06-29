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

Action AgilityAction::toAction() const
{
    QString data = dataSplitter + QString::number(difficulty()) + dataSplitter + QString::number(timePerOne()) + dataSplitter +
                   QString::number(winActionId()) + dataSplitter + QString::number(loseActionId()) + dataSplitter;
    return Action(ActionType::Agility, data, idToAction());
}

QString AgilityAction::toString() const
{
    return toAction().toString();
}


int AgilityAction::winActionId() const
{
    return m_winActionId;
}

void AgilityAction::setWinActionId(int newWinActionId)
{
    m_winActionId = newWinActionId;
}

int AgilityAction::loseActionId() const
{
    return m_loseActionId;
}

void AgilityAction::setLoseActionId(int newLoseActionId)
{
    m_loseActionId = newLoseActionId;
}

AgilityAction::AgilityAction(int difficulty, int timePerOne, int winActionId, int loseActionId) : Action(ActionType::Agility),
    m_difficulty(difficulty),
    m_timePerOne(timePerOne),
    m_winActionId(winActionId),
    m_loseActionId(loseActionId)
{}

AgilityAction AgilityAction::fromString(QString str)
{
    Action base = Action::fromString(str);
    QStringList data = base.data().split(dataSplitter);

    int difficulty = data.at(1).toInt();
    int timePerOne = data.at(2).toInt();
    int winActionId = data.value(3).toInt();
    int loseActionId = data.value(4).toInt();

    return AgilityAction(difficulty, timePerOne, winActionId, loseActionId);
}
