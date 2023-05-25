#include "../../headers/action/battleaction.h"


QString BattleAction::textData() const
{
    return m_textData;
}

void BattleAction::setTextData(const QString &newTextData)
{
    m_textData = newTextData;
}

QVector<int> BattleAction::enemiesIds() const
{
    return m_enemiesIds;
}

void BattleAction::setEnemiesIds(const QVector<int> &newEnemiesIds)
{
    m_enemiesIds = newEnemiesIds;
}

Action BattleAction::toAction() const
{
    QString data = dataSplitter + textData() + dataSplitter;
    for(const auto& elem : enemiesIds())
    {
        data += QString::number(elem) + "|";
    }
    data += dataSplitter;

    return Action(ActionType::Battle, data, idToAction());
}

QString BattleAction::toString() const
{
    return toAction().toString();
}

BattleAction::BattleAction(const QString &textData, const QVector<int> &enemiesIds) : Action(ActionType::Battle),
    m_textData(textData),
    m_enemiesIds(enemiesIds)
{}

BattleAction BattleAction::fromString(QString str)
{
    Action base = Action::fromString(str);
    QStringList data = base.data().split(dataSplitter);

    QString text = data.at(1);
    QVector<int> ids;
    for(const auto& elem : data.at(2).split("|"))
    {
        if(!elem.isEmpty())
            ids.push_back(elem.toInt());
    }

    return BattleAction(text, ids);
}
