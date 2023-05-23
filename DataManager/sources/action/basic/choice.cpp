#include "../../../headers/action/basic/choice.h"


int Choice::idToAction() const
{
    return m_idToAction;
}

void Choice::setIdToAction(int newIdToAction)
{
    m_idToAction = newIdToAction;
}

QString Choice::text() const
{
    return m_text;
}

void Choice::setText(const QString &newText)
{
    m_text = newText;
}

Consequence Choice::consequence() const
{
    return m_consequence;
}

void Choice::setConsequence(const Consequence &newConsequence)
{
    m_consequence = newConsequence;
}

Choice::Choice(int idToAction, const QString &text, const Consequence &consequence) : m_idToAction(idToAction),
    m_text(text),
    m_consequence(consequence)
{}

Choice Choice::fromString(QString str)
{
    QStringList props = str.split("~");
    int id = props.at(1).toInt();
    QString text = props.at(2);
    Consequence cons(props.at(3).toInt(), QString(), props.at(4).toInt());

    return Choice(id, text, cons);
}

QString Choice::toString()
{
    QString splitter = "~";
    Consequence cons = consequence();
    QString data = splitter + QString::number(idToAction()) + splitter + text() + splitter + QString::number(cons.id()) + splitter + QString::number(cons.isOn()) + splitter;
    return data;
}
