#ifndef BATTLEACTION_H
#define BATTLEACTION_H

#include "action.h"

class BattleAction : public Action
{
private:
    QString m_textData;
    QVector<int> m_enemiesIds;
    int m_winActionId;
    int m_loseActionId;


public:
    BattleAction(const QString &textData = QString(), const QVector<int> &enemiesIds = QVector<int>(), int winActionId = -1, int loseActionId = -1);
    static BattleAction fromString(QString str);

    QString textData() const;
    void setTextData(const QString &newTextData);
    QVector<int> enemiesIds() const;
    void setEnemiesIds(const QVector<int> &newEnemiesIds);
    int winActionId() const;
    void setWinActionId(int newWinActionId);
    int loseActionId() const;
    void setLoseActionId(int newLoseActionId);

    // Action interface
public:
    virtual Action toAction() const;
    virtual QString toString() const;
};

#endif // BATTLEACTION_H
