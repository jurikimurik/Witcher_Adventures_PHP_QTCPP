#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "../item/buff.h"
#include "../basic/databaseitem.h"

class Character : public DatabaseItem
{
public:
    Character(int id = -1, const QString &name = QString(), const QString &imageName = QString(), const Buff &attributes = Buff());
    QString imageName() const;
    void setImageName(const QString &newImageName);
    Buff attributes() const;
    void setAttributes(const Buff &newAttributes);

private:
    QString m_imageName;
    Buff m_attributes;

    // DatabaseItem interface
public:
    virtual QString toString();
    static Character fromString(QString str);
};

#endif // CHARACTER_H
