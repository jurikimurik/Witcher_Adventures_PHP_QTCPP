#include "consequencesaction.h"

QVector<Consequence> ConsequencesAction::consequences() const
{
    return m_consequences;
}

void ConsequencesAction::setConsequences(const QVector<Consequence> &newConsequences)
{
    m_consequences = newConsequences;
}

ConsequencesAction::ConsequencesAction(const QVector<Consequence> &consequences) : Action(ActionType::Consequences),
    m_consequences(consequences)
{}
