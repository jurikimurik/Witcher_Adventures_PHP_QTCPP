#ifndef CONSEQUENCE_H
#define CONSEQUENCE_H

#include <QString>
#include "../basic/databaseitem.h"

class Consequence : public DatabaseItem
{
public:
    Consequence(int id = -1, const QString &name = QString(), bool isOn = false);

    bool isOn() const;
    void setOn(bool newIsOn);

private:
    bool m_isOn;
};

#endif // CONSEQUENCE_H
