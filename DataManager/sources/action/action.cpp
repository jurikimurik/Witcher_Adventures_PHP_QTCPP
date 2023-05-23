#include "../../headers/action/action.h"

const QString Action::dataSplitter = "|---|";

ActionType Action::type() const
{
    return m_type;
}

void Action::setType(ActionType newType)
{
    m_type = newType;
}

QString Action::data() const
{
    return m_data;
}

void Action::setData(const QString &newData)
{
    m_data = newData;
}

int Action::idToAction() const
{
    return m_idToAction;
}

void Action::setIdToAction(int newIdToAction)
{
    m_idToAction = newIdToAction;
}

Action::Action(ActionType type, const QString &data, int toAction) : m_type(type),
    m_data(data),
    m_idToAction(toAction)
{}

Action Action::toAction()
{
    return *this;
}

QString Action::toString()
{
    QString splitter = DatabaseItem::getSplitter();
    QString properties = QString::number((int)type()) + splitter + data() + splitter + QString::number(idToAction()) + splitter;

    return properties;
}

Action Action::fromString(QString str)
{
    QStringList props = str.split(DatabaseItem::getSplitter());
    ActionType type = (ActionType) props.at(0).toInt();
    QString data = props.at(1);
    int toAction = props.at(2).toInt();

    return Action(type, data, toAction);
}
