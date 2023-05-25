#ifndef BATTLEACTION_H
#define BATTLEACTION_H

#include "action.h"

class BattleAction : public Action
{
private:
    QString m_textData;
    QVector<int> m_enemiesIds;


public:
    BattleAction(const QString &textData = QString(), const QVector<int> &enemiesIds = QVector<int>());
    static BattleAction fromString(QString str);

    QString textData() const;
    void setTextData(const QString &newTextData);
    QVector<int> enemiesIds() const;
    void setEnemiesIds(const QVector<int> &newEnemiesIds);

    // Action interface
public:
    virtual Action toAction() const;
    virtual QString toString() const;

};

#endif // BATTLEACTION_H
