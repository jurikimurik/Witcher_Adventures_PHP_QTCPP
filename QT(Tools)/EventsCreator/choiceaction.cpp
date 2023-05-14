#include "choiceaction.h"

QVector<Choice> ChoiceAction::choicesTexts() const
{
    return m_choicesTexts;
}

void ChoiceAction::setChoicesTexts(const QVector<Choice> &newChoicesTexts)
{
    m_choicesTexts = newChoicesTexts;
}

ChoiceAction::ChoiceAction(const QVector<Choice> &choicesTexts) : Action(ActionType::Choice),
    m_choicesTexts(choicesTexts)
{}
