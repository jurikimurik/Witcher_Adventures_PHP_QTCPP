#ifndef CONSEQUENCESACTION_H
#define CONSEQUENCESACTION_H

#include "action.h"

class ConsequenceAction: public Action
{
private:
    QVector<QString> m_conditions;
    static const QString SPLITTER;

public:
    ConsequenceAction(const QVector<QString> &conditions = QVector<QString>());
    static ConsequenceAction fromString(QString str);

    virtual Action toAction() const;
    virtual QString toString() const;

    QVector<QString> conditions() const;
    void setConditions(const QVector<QString> &newConditions);
};

#endif // CONSEQUENCESACTION_H
