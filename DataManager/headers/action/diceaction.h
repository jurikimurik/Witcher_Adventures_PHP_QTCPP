#ifndef DICEACTION_H
#define DICEACTION_H

#include "action.h"

class DiceAction : public Action
{
private:
    int m_difficulty;
    int m_players;
    QVector<int> enemiesIds;
    QString m_textData;
    int m_winActionId;
    int m_loseActionId;

public:
    DiceAction(int difficulty = 1, int players = 1, const QVector<int> &enemiesIds = QVector<int>(), const QString &textData = QString(), int winActionId = -1, int loseActionId = -1);
    static DiceAction fromString(QString str);

    int difficulty() const;
    void setDifficulty(int newDifficulty);
    int players() const;
    void setPlayers(int newPlayers);
    QVector<int> getEnemiesIds() const;
    void setEnemiesIds(const QVector<int> &newEnemiesIds);
    QString textData() const;
    void setTextData(const QString &newTextData);
    int winActionId() const;
    void setWinActionId(int newWinActionId);
    int loseActionId() const;
    void setLoseActionId(int newLoseActionId);


    // Action interface
public:
    virtual Action toAction() const;
    virtual QString toString() const;
};

#endif // DICEACTION_H
