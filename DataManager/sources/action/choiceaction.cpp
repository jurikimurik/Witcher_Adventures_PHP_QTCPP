#include "../../headers/action/choiceaction.h"

QVector<Choice> ChoiceAction::choices() const
{
    return m_choices;
}

void ChoiceAction::setChoices(const QVector<Choice> &newChoices)
{
    m_choices = newChoices;
}

QString ChoiceAction::text() const
{
    return m_text;
}

void ChoiceAction::setText(const QString &newText)
{
    m_text = newText;
}

Action ChoiceAction::toAction() const
{
    QString data = dataSplitter + text() + dataSplitter;
    for(auto& elem : choices())
    {
        data += elem.toString() + "|";
    }
    data += dataSplitter;

    return Action(ActionType::Choice,data,idToAction());
}

QString ChoiceAction::toString() const
{
    return toAction().toString();
}

ChoiceAction::ChoiceAction(const QString &text, const QVector<Choice> &choices) : Action(ActionType::Choice),
    m_text(text),
    m_choices(choices)
{}

ChoiceAction ChoiceAction::fromString(QString str)
{
    Action base = Action::fromString(str);
    QStringList data = base.data().split(dataSplitter);

    QString text = data.at(1);

    QVector<Choice> choices;
    for(const auto& elem : data.at(2).split("|"))
    {
        if(!elem.isEmpty())
            choices.push_back(Choice::fromString(elem));
    }

    return ChoiceAction(text, choices);
}
