#ifndef BATTLEACTION_H
#define BATTLEACTION_H

#include "action.h"

class BattleAction : public Action
{
private:
    QVector<int> m_enemiesIds;

public:
    BattleAction(const QVector<int> &enemiesIds);

    void setEnemiesIds(const QVector<int> &newEnemiesIds);
    QVector<int> enemiesIds() const;
};

#endif // BATTLEACTION_H
