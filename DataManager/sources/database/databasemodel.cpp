#include "../../headers/database/databasemodel.h"

DatabaseModel::DatabaseModel(QObject *parent)
    : QObject{parent}
{

}

ItemsModel *DatabaseModel::itemsModel() const
{
    return m_itemsModel;
}

void DatabaseModel::setItemsModel(ItemsModel *newItemsModel)
{
    m_itemsModel = newItemsModel;
}

CharacterModel *DatabaseModel::charactersModel() const
{
    return m_charactersModel;
}

void DatabaseModel::setCharactersModel(CharacterModel *newCharactersModel)
{
    m_charactersModel = newCharactersModel;
}

ConsequencesModel *DatabaseModel::consequencesModel() const
{
    return m_consequencesModel;
}

void DatabaseModel::setConsequencesModel(ConsequencesModel *newConsequencesModel)
{
    m_consequencesModel = newConsequencesModel;
}

DatabaseModel::DatabaseModel(ItemsModel *itemsModel, CharacterModel *charactersModel, ConsequencesModel *consequencesModel, QObject *parent) : QObject(parent),
    m_itemsModel(itemsModel),
    m_charactersModel(charactersModel),
    m_consequencesModel(consequencesModel)
{
    m_itemsModel->setParent(this);
    m_charactersModel->setParent(this);
    m_consequencesModel->setParent(this);
}
