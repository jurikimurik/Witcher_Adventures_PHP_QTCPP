#include "../../headers/action/rewardaction.h"


int RewardAction::money() const
{
    return m_money;
}

void RewardAction::setMoney(int newMoney)
{
    m_money = newMoney;
}

QVector<int> RewardAction::itemsIds() const
{
    return m_itemsIds;
}

void RewardAction::setItemsIds(const QVector<int> &newItemsIds)
{
    m_itemsIds = newItemsIds;
}

Action RewardAction::toAction()
{
    QString data = dataSplitter + QString::number(money()) + dataSplitter;
    for(const auto& elem : itemsIds())
    {
        data += QString::number(elem) + "|";
    }
    data += dataSplitter;
    return Action(ActionType::NONE, data, idToAction());
}

QString RewardAction::toString()
{
    return toAction().toString();
}

RewardAction::RewardAction(int money, const QVector<int> &itemsIds) : Action(ActionType::Reward),
    m_money(money),
    m_itemsIds(itemsIds)
{}

RewardAction RewardAction::fromString(QString str)
{
    Action base = Action::fromString(str);
    QStringList data = base.data().split(dataSplitter);

    int money = data.at(1).toInt();
    QVector<int> ids;
    for(const auto& elem : data.at(2).split("|"))
    {
        if(!elem.isEmpty())
            ids.push_back(elem.toInt());
    }

    return RewardAction(money, ids);
}
