#ifndef DATABASEMODEL_H
#define DATABASEMODEL_H

#include <QObject>
#include "../item/itemsmodel.h"
#include "../character/charactermodel.h"
#include "../consequence/consequencesmodel.h"

class DatabaseModel : public QObject
{
    Q_OBJECT

private:
    ItemsModel* m_itemsModel;
    CharacterModel* m_charactersModel;
    ConsequencesModel* m_consequencesModel;

public:
    DatabaseModel(ItemsModel *itemsModel = new ItemsModel(), CharacterModel *charactersModel = new CharacterModel(), ConsequencesModel *consequencesModel = new ConsequencesModel(), QObject *parent = nullptr);
    QString toString();
    static DatabaseModel* fromString(QString str);


    ItemsModel *itemsModel() const;
    void setItemsModel(ItemsModel *newItemsModel);
    CharacterModel *charactersModel() const;
    void setCharactersModel(CharacterModel *newCharactersModel);
    ConsequencesModel *consequencesModel() const;
    void setConsequencesModel(ConsequencesModel *newConsequencesModel);
};

#endif // DATABASEMODEL_H
