#ifndef CONSEQUENCE_H
#define CONSEQUENCE_H

#include <QString>

class Consequence
{
public:
    Consequence(int id = -1, const QString &name = QString(), bool isOn = false);

    int id() const;
    void setId(int newId);
    QString name() const;
    void setName(const QString &newName);
    bool isOn() const;
    void setOn(bool newIsOn);

private:
    int m_id;
    QString m_name;
    bool m_isOn;
};

#endif // CONSEQUENCE_H
