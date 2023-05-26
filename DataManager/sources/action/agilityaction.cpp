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
    QString data = dataSplitter + QString::number(difficulty()) + dataSplitter + QString::number(timePerOne()) + dataSplitter;
    return Action(ActionType::Agility, data, idToAction());
}

QString AgilityAction::toString() const
{
    return toAction().toString();
}


AgilityAction::AgilityAction(int difficulty, int timePerOne) : Action(ActionType::Agility),
    m_difficulty(difficulty),
    m_timePerOne(timePerOne)
{}

AgilityAction AgilityAction::fromString(QString str)
{
    Action base = Action::fromString(str);
    QStringList data = base.data().split(dataSplitter);

    int difficulty = data.at(1).toInt();
    int timePerOne = data.at(2).toInt();

    return AgilityAction(difficulty, timePerOne);
}
