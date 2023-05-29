#include "../../headers/consequence/consequencesmodel.h"

const QString ConsequencesModel::modelSplitter = "[::CONSEQUENCES::]";

ConsequencesModel::ConsequencesModel(QMap<int, Consequence> database, QObject *parent)
    : QObject{parent},
      QMap<int, Consequence>(database)
{

}

QStringList ConsequencesModel::getAllNamesAndIds()
{
    QStringList list;
    for(const auto& elem : values())
    {
        list.push_back(QString::number(elem.id()) + " - " + elem.name());
    }
    return list;
}

QStringList ConsequencesModel::getAllIds()
{
    QStringList list;
    for(const auto& elem : values())
    {
        list.push_back(QString::number(elem.id()));
    }
    return list;
}

QString ConsequencesModel::toString()
{
    QString properties = getModelSplitter();
    QString itemSplitter = DatabaseItem::getItemSplitter();
    QString splitter = DatabaseItem::getSplitter();

    for(const auto& elem : keys())
    {
        properties += itemSplitter + QString::number(elem) + splitter + value(elem).toString() + itemSplitter;
    }
    properties += getModelSplitter();
    return properties;
}

ConsequencesModel* ConsequencesModel::fromString(QString str)
{
    ConsequencesModel* model = new ConsequencesModel();
    QStringList consequence = str.split(getModelSplitter());
    QStringList items = consequence.at(1).split(DatabaseItem::getItemSplitter());
    for(const auto& elem: items)
    {
        if(elem.isEmpty())
            continue;

        QStringList properties = elem.split(DatabaseItem::getSplitter());
        int mapId = properties.takeFirst().toInt();
        Consequence cons = Consequence::fromString(properties.join(DatabaseItem::getSplitter()));
        model->insert(mapId, cons);
    }
    return model;
}

QString ConsequencesModel::getModelSplitter()
{
    return modelSplitter;
}

void ConsequencesModel::updateConsequence(const Consequence &cons)
{
    insert(cons.id(), cons);
    emit dataUpdated();
}

void ConsequencesModel::deleteConsequence(const Consequence &cons)
{
    remove(cons.id());
    emit dataUpdated();
}

void ConsequencesModel::idsAndNamesNeeded()
{
    emit getAllNamesAndIds();
}

QStringList ConsequencesModel::getAllNames()
{
    QStringList list;
    for(const auto& elem : values())
    {
        list.push_back(elem.name());
    }
    return list;
}
