#include "../../headers/action/diceaction.h"


int DiceAction::difficulty() const
{
    return m_difficulty;
}

void DiceAction::setDifficulty(int newDifficulty)
{
    m_difficulty = newDifficulty;
}

int DiceAction::players() const
{
    return m_players;
}

void DiceAction::setPlayers(int newPlayers)
{
    m_players = newPlayers;
}

QVector<int> DiceAction::getEnemiesIds() const
{
    return enemiesIds;
}

void DiceAction::setEnemiesIds(const QVector<int> &newEnemiesIds)
{
    enemiesIds = newEnemiesIds;
}

QString DiceAction::textData() const
{
    return m_textData;
}

void DiceAction::setTextData(const QString &newTextData)
{
    m_textData = newTextData;
}

Action DiceAction::toAction() const
{
    QString data = dataSplitter + QString::number(difficulty()) + dataSplitter + QString::number(players()) + dataSplitter;
    for(auto& elem : getEnemiesIds())
    {
        data += QString::number(elem) + "|";
    }
    data += dataSplitter;

    data += textData() + dataSplitter;

    return Action(ActionType::Dice,data,idToAction());
}

QString DiceAction::toString() const
{
    return toAction().toString();
}

DiceAction::DiceAction(int difficulty, int players, const QVector<int> &enemiesIds, const QString &textData) :
    Action(ActionType::Dice),
    m_difficulty(difficulty),
    m_players(players),
    enemiesIds(enemiesIds),
    m_textData(textData)
{}

DiceAction DiceAction::fromString(QString str)
{
    Action base = Action::fromString(str);
    QStringList data = base.data().split(dataSplitter);

    int difficulty = data.at(1).toInt();

    int players = data.at(2).toInt();

    QVector<int> enemiesIds;
    for(const auto& elem : data.at(3).split("|"))
    {
        if(!elem.isEmpty())
            enemiesIds.push_back(elem.toInt());
    }

    QString text = data.at(4);

    return DiceAction(difficulty, players, enemiesIds, text);
}
