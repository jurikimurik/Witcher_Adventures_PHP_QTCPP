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


public:
    DiceAction(int difficulty = 1, int players = 1, const QVector<int> &enemiesIds = QVector<int>(), const QString &textData = QString());
    static DiceAction fromString(QString str);

    int difficulty() const;
    void setDifficulty(int newDifficulty);
    int players() const;
    void setPlayers(int newPlayers);
    QVector<int> getEnemiesIds() const;
    void setEnemiesIds(const QVector<int> &newEnemiesIds);
    QString textData() const;
    void setTextData(const QString &newTextData);


    // Action interface
public:
    virtual Action toAction() const;
    virtual QString toString() const;

};

#endif // DICEACTION_H
