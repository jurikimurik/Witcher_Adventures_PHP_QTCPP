#include "../../headers/database/databasemodel.h"

const QString DatabaseModel::modelSplitter = "[:|:DATABASE:|:]";


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

EventsModel *DatabaseModel::eventsModel() const
{
    return m_eventsModel;
}

void DatabaseModel::setEventsModel(EventsModel *newEventsModel)
{
    m_eventsModel = newEventsModel;
}

DatabaseModel::DatabaseModel(ItemsModel *itemsModel, CharacterModel *charactersModel,
                             ConsequencesModel *consequencesModel, EventsModel *eventsModel, QObject *parent) : QObject(parent),
    m_itemsModel(itemsModel),
    m_charactersModel(charactersModel),
    m_consequencesModel(consequencesModel),
    m_eventsModel(eventsModel)
{
    m_itemsModel->setParent(this);
    m_charactersModel->setParent(this);
    m_consequencesModel->setParent(this);
    m_eventsModel->setParent(this);


}

DatabaseModel::~DatabaseModel()
{
    delete m_itemsModel;
    delete m_charactersModel;
    delete m_consequencesModel;
}

QString DatabaseModel::toString()
{
    return getModelSplitter() + m_itemsModel->toString() + m_charactersModel->toString() + m_consequencesModel->toString() + m_eventsModel->toString() + getModelSplitter();
}

DatabaseModel *DatabaseModel::fromString(QString str)
{
    ItemsModel* items = ItemsModel::fromString(str);
    CharacterModel* character = CharacterModel::fromString(str);
    ConsequencesModel* consequences = ConsequencesModel::fromString(str);
    EventsModel* events = EventsModel::fromString(str);

    return new DatabaseModel(items, character, consequences, events);
}

QString DatabaseModel::getModelSplitter()
{
    return modelSplitter;
}
