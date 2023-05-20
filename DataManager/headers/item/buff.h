#ifndef BUFF_H
#define BUFF_H

#include "../basic/databaseitem.h"
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
    virtual ~Buff();
    Buff(int duration, Attributes attr, QString name = QString());
    QString name() const;
    void setName(const QString &newName);
    int duration() const;
    void setDuration(int newDuration);
    Attributes changedAttributes() const;
    void setChangedAttributes(const Attributes &newChangedAttributes);

    virtual QString toString();
    static Buff fromString(QString properties);
};

#endif // BUFF_H
