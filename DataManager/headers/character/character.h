#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "../item/buff.h"
#include "../basic/databaseitem.h"

class Character : public DatabaseItem
{
public:
    Character(int id = -1, const QString &name = QString(), const QString &imageName = QString(), const Buff &attributes = Buff(), const QVector<Buff> &buffs = QVector<Buff>());
    QString imageName() const;
    void setImageName(const QString &newImageName);
    Buff basicStatistics() const;
    void setBasicStatistics(const Buff &newAttributes);
    QVector<Buff> buffs() const;
    void setBuffs(const QVector<Buff> &newBuffs);

private:
    QString m_imageName;
    Buff m_basicStatistics;
    QVector<Buff> m_buffs;

    // DatabaseItem interface
public:
    virtual QString toString();
    static Character fromString(QString str);
};

#endif // CHARACTER_H
