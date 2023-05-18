#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "../item/buff.h"

class Character
{
public:
    Character();
    Character(int id = -1, const QString &name = QString(), const QString &imageName = QString(), const Buff &attributes = Buff());
    int id() const;
    void setId(int newId);
    QString name() const;
    void setName(const QString &newName);
    QString imageName() const;
    void setImageName(const QString &newImageName);
    Buff attributes() const;
    void setAttributes(const Buff &newAttributes);

private:
    int m_id;
    QString m_name;
    QString m_imageName;
    Buff m_attributes;
};

#endif // CHARACTER_H
