#ifndef DATABASEITEM_H
#define DATABASEITEM_H

#include <QString>
#include <QStringList>

class DatabaseItem
{
public:
    DatabaseItem(int id = -1, const QString &name = QString());

    int id() const;
    void setId(int newId);
    QString name() const;
    void setName(const QString &newName);

    virtual QString toString();
    virtual DatabaseItem fromString(QString str);

    static const QString splitter;
    static QString getSplitter();

private:
    int m_id;
    QString m_name;
};

#endif // DATABASEITEM_H
