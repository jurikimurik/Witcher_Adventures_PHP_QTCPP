#include "choice.h"

QString *Choice::choiceText() const
{
    return m_choiceText;
}

void Choice::setChoiceText(const QString &newChoiceText)
{
    *m_choiceText = newChoiceText;
}

int *Choice::choiceId() const
{
    return m_choiceId;
}

void Choice::setChoiceId(const int &newChoiceId)
{
    *m_choiceId = newChoiceId;
}

Choice::Choice() : m_choiceText(&first), m_choiceId(&second)
{}

Choice::Choice(QString text, int id) : Choice()
{
    setChoiceText(text);
    setChoiceId(id);
}
