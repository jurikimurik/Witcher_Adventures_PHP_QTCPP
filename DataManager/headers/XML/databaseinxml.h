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

    QXmlStreamReader& reader();
    QXmlStreamWriter& writer();

public slots:
    void saveToFile(const QString& file);
    DatabaseModel* readFromFile(const QString& file);


private:
    void saveItems();
    void saveItem(const Item& elem);
    void saveType(const ItemType& type);
    void saveBuff(const Buff& buff);
    void saveAttributes(const Attributes& attributes);

    void saveConsequences();
    void saveConsequence(const Consequence& elem);

    void saveCharacters();
    void saveCharacter(const Character& elem);

    void saveEvents();
    void saveEvent(const Event& elem);
    void saveAction(const Action& action);

private:
    DatabaseModel* m_model;
    QXmlStreamReader m_reader;
    QXmlStreamWriter m_writer;
};

#endif // DATABASEINXML_H
