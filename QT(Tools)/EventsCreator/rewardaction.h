#ifndef REWARDACTION_H
#define REWARDACTION_H

#include <QVector>
#include "action.h"

class RewardAction : public Action
{
private:
    QVector<int> m_items;
    int m_money;

public:
    RewardAction(const QVector<int> &items, int money);


    QVector<int> items() const;
    void setItems(const QVector<int> &newItems);
    int money() const;
    void setMoney(int newMoney);
};

#endif // REWARDACTION_H
