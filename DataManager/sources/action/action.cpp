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

QString Action::name() const
{
    return m_name;
}

void Action::setName(const QString &newName)
{
    m_name = newName;
}

Action::Action(ActionType type, const QString &data, int toAction, QString name) : m_type(type),
    m_data(data),
    m_idToAction(toAction),
    m_name(name)
{}

Action::~Action()
{

}

Action Action::toAction() const
{
    return *this;
}

QString Action::toString() const
{
    QString splitter = DatabaseItem::getSplitter();
    QString properties = QString::number((int)type()) + splitter + data() + splitter + QString::number(idToAction()) + splitter + name() + splitter;

    return properties;
}

Action Action::fromString(QString str)
{
    QStringList props = str.split(DatabaseItem::getSplitter());
    ActionType type = (ActionType) props.at(0).toInt();
    QString data = props.at(1);
    int toAction = props.at(2).toInt();
    QString name = props.value(3);


    return Action(type, data, toAction, name);
}
