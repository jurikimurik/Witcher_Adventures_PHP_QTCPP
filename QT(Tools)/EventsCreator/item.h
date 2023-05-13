#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QVector>
#include "buff.h"

class Item
{
private:
    const int mc_id;
    QString m_name;
    QString m_ImagePath;
    QString m_description;
    QVector<Buff> m_increases;

public:
    Item(int id, QString name, QVector<Buff> increases, QString imagePath = QString());
    int getMc_id() const;
    QString name() const;
    void setName(const QString &newName);
    QString ImagePath() const;
    void setImagePath(const QString &newImagePath);
    QString description() const;
    void setDescription(const QString &newDescription);
    QVector<Buff> increases() const;
    void setIncreases(const QVector<Buff> &newIncreases);
};

#endif // ITEM_H
