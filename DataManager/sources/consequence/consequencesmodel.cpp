#include "../../headers/consequence/consequencesmodel.h"

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

QStringList ConsequencesModel::getAllNames()
{
    QStringList list;
    for(const auto& elem : values())
    {
        list.push_back(elem.name());
    }
    return list;
}
