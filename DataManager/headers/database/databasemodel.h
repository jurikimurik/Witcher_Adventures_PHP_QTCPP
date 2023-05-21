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
    explicit DatabaseModel(ItemsModel *itemsModel = new ItemsModel(), CharacterModel *charactersModel = new CharacterModel(), ConsequencesModel *consequencesModel = new ConsequencesModel(), QObject *parent = nullptr);
    virtual ~DatabaseModel();
    QString toString();
    static DatabaseModel* fromString(QString str);

public:
    static const QString modelSplitter;

    ItemsModel *itemsModel() const;
    void setItemsModel(ItemsModel *newItemsModel);
    CharacterModel *charactersModel() const;
    void setCharactersModel(CharacterModel *newCharactersModel);
    ConsequencesModel *consequencesModel() const;
    void setConsequencesModel(ConsequencesModel *newConsequencesModel);
    static QString getModelSplitter();
};

#endif // DATABASEMODEL_H
