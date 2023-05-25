#ifndef CHOICEACTION_H
#define CHOICEACTION_H

#include "action.h"
#include "basic/choice.h"

class ChoiceAction : public Action
{
private:
    QString m_text;
    QVector<Choice> m_choices;


public:
    ChoiceAction(const QString &text = QString(), const QVector<Choice> &choices = QVector<Choice>());

    static ChoiceAction fromString(QString str);

    QVector<Choice> choices() const;
    void setChoices(const QVector<Choice> &newChoices);
    QString text() const;
    void setText(const QString &newText);

    // Action interface
public:
    virtual Action toAction() const;
    virtual QString toString() const;

};

#endif // CHOICEACTION_H
