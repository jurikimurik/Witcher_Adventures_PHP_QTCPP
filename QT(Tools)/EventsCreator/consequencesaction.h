#ifndef CONSEQUENCESACTION_H
#define CONSEQUENCESACTION_H

#include <QVector>
#include "action.h"
#include "consequence.h"

class ConsequencesAction : public Action
{
private:
    QVector<Consequence> m_consequences;

public:
    ConsequencesAction(const QVector<Consequence> &consequences);
    QVector<Consequence> consequences() const;
    void setConsequences(const QVector<Consequence> &newConsequences);
};

#endif // CONSEQUENCESACTION_H
