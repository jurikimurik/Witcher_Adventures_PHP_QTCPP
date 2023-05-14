#include "battleaction.h"


QVector<int> BattleAction::enemiesIds() const
{
    return m_enemiesIds;
}

void BattleAction::setEnemiesIds(const QVector<int> &newEnemiesIds)
{
    m_enemiesIds = newEnemiesIds;
}

BattleAction::BattleAction(const QVector<int> &enemiesIds) : Action(ActionType::Battle),
    m_enemiesIds(enemiesIds)
{}
