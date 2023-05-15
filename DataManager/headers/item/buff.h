#ifndef BUFF_H
#define BUFF_H

#include <QString>
#include "../special/attributes.h"

class Buff
{
private:
    QString m_name;
    int m_duration;
    Attributes m_changedAttributes;

public:
    Buff();
    Buff(int duration, Attributes attr, QString name = QString());
    QString name() const;
    void setName(const QString &newName);
    int duration() const;
    void setDuration(int newDuration);
    Attributes changedAttributes() const;
    void setChangedAttributes(const Attributes &newChangedAttributes);
};

#endif // BUFF_H
