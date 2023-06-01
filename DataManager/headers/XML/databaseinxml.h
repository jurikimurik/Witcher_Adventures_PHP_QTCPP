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
    //----------------------------------SAVE------------------------------
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
    //--------------------------------------------------------------------

    //----------------------------------READ------------------------------
    DatabaseModel* readDatabaseModel();

    ItemsModel* readItemsModel();
    Item readItem();
    ItemType readItemType();
    Buff readBuff();
    Attributes readAttributes();

    ConsequencesModel* readConsequencesModel();
    Consequence readConsequence();

    CharacterModel* readCharactersModel();
    Character readCharacter();

    EventsModel* readEventsModel();
    Event readEvent();
    Action readAction();
    //--------------------------------------------------------------------

private:
    DatabaseModel* m_model;
    QXmlStreamReader reader;
    QXmlStreamWriter writer;
};

#endif // DATABASEINXML_H
