#include "../../headers/action/consequenceaction.h"

const QString ConsequenceAction::SPLITTER = "§";

ConsequenceAction::ConsequenceAction(const QVector<QString> &conditions)
    : m_conditions(conditions)
{

}

ConsequenceAction ConsequenceAction::fromString(QString str)
{
    Action base = Action::fromString(str);
    QStringList data = base.data().split(dataSplitter);

    QVector<QString> conditions;
    QString allConditions = data.value(1);
    for(QString condition : allConditions.split(SPLITTER))
    {
        if(!condition.isEmpty())
            conditions.push_back(condition);
    }

    return ConsequenceAction(conditions);
}

Action ConsequenceAction::toAction() const
{
    QString data = dataSplitter;
    for(const QString& condition : m_conditions)
    {
        data += condition + SPLITTER;
    }
    data += dataSplitter;

    return Action(ActionType::Consequence, data, idToAction());
}

QString ConsequenceAction::toString() const
{
    return toAction().toString();
}

QVector<QString> ConsequenceAction::conditions() const
{
    return m_conditions;
}

void ConsequenceAction::setConditions(const QVector<QString> &newConditions)
{
    m_conditions = newConditions;
}
