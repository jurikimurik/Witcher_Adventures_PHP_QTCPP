#include "../../headers/XML/databaseinxml.h"

#include <QDebug>

DatabaseModel *DatabaseInXML::model() const
{
    return m_model;
}

void DatabaseInXML::setModel(DatabaseModel *newModel)
{
    m_model = newModel;
}

void DatabaseInXML::saveToFile(const QString &file)
{

}

void DatabaseInXML::readFromFile(const QString &file)
{

}

DatabaseInXML::DatabaseInXML(DatabaseModel *model, QObject *parent) : QObject(parent),
    m_model(model)
{

}
