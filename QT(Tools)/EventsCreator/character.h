#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>
#include "attributes.h"

class Character
{
private:
    const int mc_id;
    QString m_Name;
    QString m_imagePath;
    Attributes m_attributes;

public:
    Character(int id, QString name, Attributes attributes, QString imagePath = QString());
    int getMc_id() const;
    QString Name() const;
    void setName(const QString &newName);
    QString imagePath() const;
    void setImagePath(const QString &newImagePath);
    Attributes attributes() const;
    void setAttributes(const Attributes &newAttributes);
};

#endif // CHARACTER_H
