#include "rewardaction.h"

QVector<int> RewardAction::items() const
{
    return m_items;
}

void RewardAction::setItems(const QVector<int> &newItems)
{
    m_items = newItems;
}

int RewardAction::money() const
{
    return m_money;
}

void RewardAction::setMoney(int newMoney)
{
    m_money = newMoney;
}

RewardAction::RewardAction(const QVector<int> &items, int money) : Action(ActionType::Reward),
    m_items(items),
    m_money(money)
{}
