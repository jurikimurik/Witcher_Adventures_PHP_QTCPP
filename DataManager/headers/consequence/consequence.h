#ifndef CONSEQUENCE_H
#define CONSEQUENCE_H

#include <QString>
#include "../basic/databaseitem.h"

class Consequence : public DatabaseItem
{
public:
    Consequence(int id = -1, const QString &name = QString(), bool isOn = false);
    virtual ~Consequence();

    bool isOn() const;
    void setOn(bool newIsOn);

private:
    bool m_isOn;

    // DatabaseItem interface
public:
    virtual QString toString();
    static Consequence fromString(QString str);
};

#endif // CONSEQUENCE_H
