#ifndef CHOICE_H
#define CHOICE_H

#include "../../consequence/consequence.h"

class Choice
{
private:
    int m_idToAction;
    QString m_text;
    Consequence m_consequence;

public:
    Choice(int idToAction = -1, const QString &text = QString(), const Consequence &consequence = Consequence());

    QString toString();
    static Choice fromString(QString str);

    int idToAction() const;
    void setIdToAction(int newIdToAction);
    QString text() const;
    void setText(const QString &newText);
    Consequence consequence() const;
    void setConsequence(const Consequence &newConsequence);
};

#endif // CHOICE_H
