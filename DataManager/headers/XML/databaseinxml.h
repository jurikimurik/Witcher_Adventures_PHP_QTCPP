#ifndef DATABASEINXML_H
#define DATABASEINXML_H

#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include "../database/databasemodel.h"

class DatabaseInXML : public QObject
{
    Q_OBJECT

public:
    DatabaseInXML(DatabaseModel *model, QObject *parent = nullptr);

    DatabaseModel *model() const;
    void setModel(DatabaseModel *newModel);

public slots:
    void saveToFile(const QString& file);
    DatabaseModel* readFromFile(const QString& file);

private:
    DatabaseModel* m_model;
};

#endif // DATABASEINXML_H
