#ifndef REWARDACTION_H
#define REWARDACTION_H

#include "action.h"

class RewardAction : public Action
{
private:
    int m_money;
    QVector<int> m_itemsIds;



public:
    RewardAction(int money = 0, const QVector<int> &itemsIds = QVector<int>());
    static RewardAction fromString(QString str);

    int money() const;
    void setMoney(int newMoney);
    QVector<int> itemsIds() const;
    void setItemsIds(const QVector<int> &newItemsIds);

    // Action interface
public:
    virtual Action toAction() const;
    virtual QString toString() const;

};

#endif // REWARDACTION_H
