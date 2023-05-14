#ifndef CHOICEACTION_H
#define CHOICEACTION_H

#include <QVector>
#include "action.h"
#include "choice.h"

class ChoiceAction : public Action
{
private:
    QVector<Choice> m_choicesTexts;
public:
    ChoiceAction(const QVector<Choice> &choicesTexts);
    QVector<Choice> choicesTexts() const;
    void setChoicesTexts(const QVector<Choice> &newChoicesTexts);
};

#endif // CHOICEACTION_H
