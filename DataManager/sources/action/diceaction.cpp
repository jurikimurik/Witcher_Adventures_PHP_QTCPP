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

    data += QString::number(winActionId()) + dataSplitter;

    data += QString::number(loseActionId()) + dataSplitter;

    return Action(ActionType::Dice,data,idToAction());
}

QString DiceAction::toString() const
{
    return toAction().toString();
}

int DiceAction::winActionId() const
{
    return m_winActionId;
}

void DiceAction::setWinActionId(int newWinActionId)
{
    m_winActionId = newWinActionId;
}

int DiceAction::loseActionId() const
{
    return m_loseActionId;
}

void DiceAction::setLoseActionId(int newLoseActionId)
{
    m_loseActionId = newLoseActionId;
}

DiceAction::DiceAction(int difficulty, int players, const QVector<int> &enemiesIds, const QString &textData, int winActionId, int loseActionId) :
    Action(ActionType::Dice),
    m_difficulty(difficulty),
    m_players(players),
    enemiesIds(enemiesIds),
    m_textData(textData),
    m_winActionId(winActionId),
    m_loseActionId(loseActionId)
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

    int winActionId = data.value(5).toInt();
    int loseActionId = data.value(6).toInt();

    return DiceAction(difficulty, players, enemiesIds, text, winActionId, loseActionId);
}
